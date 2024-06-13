#include "bsp_qspi.h"

QSPI_HandleTypeDef QSPIHandle;


void QSPI_Init(void)
{
    QSPIHandle.Instance = QUADSPI;
    QSPIHandle.Init.ClockPrescaler = 1;
    QSPIHandle.Init.FifoThreshold = 32;
    QSPIHandle.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_HALFCYCLE;
    QSPIHandle.Init.FlashSize = W25Q128_QSPI_FLASH_SIZE - 1;
    QSPIHandle.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_3_CYCLE;
    QSPIHandle.Init.ClockMode = QSPI_CLOCK_MODE_0;
    QSPIHandle.Init.FlashID = QSPI_FLASH_ID_1;
    QSPIHandle.Init.DualFlash = QSPI_DUALFLASH_DISABLE;

    if (HAL_QSPI_Init(&QSPIHandle) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

void HAL_QSPI_MspInit(QSPI_HandleTypeDef *hqspi)
{

    RCC_PeriphCLKInitTypeDef QSPI_RCC;
    GPIO_InitTypeDef QSPIStruct;

    __HAL_RCC_QSPI_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    QSPI_RCC.PeriphClockSelection = RCC_PERIPHCLK_QSPI;
    QSPI_RCC.QspiClockSelection = RCC_QSPICLKSOURCE_D1HCLK;

    HAL_RCCEx_PeriphCLKConfig(&QSPI_RCC);

    /*CS*/
    QSPIStruct.Pin = GPIO_PIN_6;
    QSPIStruct.Mode = GPIO_MODE_AF_PP;
    QSPIStruct.Pull = GPIO_PULLUP;
    QSPIStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    QSPIStruct.Alternate = GPIO_AF10_QUADSPI;
    HAL_GPIO_Init(GPIOB, &QSPIStruct);
    /*CLK*/
    QSPIStruct.Pin = GPIO_PIN_2;
    QSPIStruct.Pull = GPIO_NOPULL;
    QSPIStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOB, &QSPIStruct);
    /*IO0,IO1,IO3*/
    QSPIStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13;
    QSPIStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOD, &QSPIStruct);
    /*IO2*/
    QSPIStruct.Pin = GPIO_PIN_2;
    QSPIStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOE, &QSPIStruct);
}

/**
 * @brief QSPI发送命令
 *
 * @param _Cmd  发送的指令
 * @param _CmdMode 指令模式
 *      @arg @ref   QSPI_INSTRUCTION_NONE
 *      @arg @ref   QSPI_INSTRUCTION_1_LINE
 *      @arg @ref   QSPI_INSTRUCTION_2_LINES
 *      @arg @ref   QSPI_INSTRUCTION_4_LINES
 * @param _Addr 目标地址
 * @param _AddrMode 地址模式
 *       @arg @ref  QSPI_ADDRESS_NONE
 *       @arg @ref  QSPI_ADDRESS_1_LINE
 *       @arg @ref  QSPI_ADDRESS_2_LINES
 *       @arg @ref  QSPI_ADDRESS_4_LINES
 * @param _AddrSize 地址长度
 *        @arg @ref QSPI_ADDRESS_8_BITS
 *        @arg @ref QSPI_ADDRESS_16_BITS
 *        @arg @ref QSPI_ADDRESS_24_BITS
 *        @arg @ref QSPI_ADDRESS_32_BITS
 * @param DunmyCycles 空周期
 * @param _DataMode 数据接收模式
 *         @arg @ref QSPI_DATA_NONE
 *         @arg @ref QSPI_DATA_1_LINE
 *         @arg @ref QSPI_DATA_2_LINES
 *         @arg @ref QSPI_DATA_4_LINES
 */
void QSPI_SendCmd(uint32_t _Cmd, uint32_t _CmdMode,
                  uint32_t _Addr, uint32_t _AddrMode,
                  uint32_t _AddrSize, uint32_t DunmyCycles,
                  uint32_t _DataMode)
{
    QSPI_CommandTypeDef QSPI_CMD={0};

    QSPI_CMD.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    QSPI_CMD.DdrMode = QSPI_DDR_MODE_DISABLE;
    QSPI_CMD.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    QSPI_CMD.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    QSPI_CMD.Instruction = _Cmd;
    QSPI_CMD.InstructionMode = _CmdMode;

    QSPI_CMD.Address=_Addr;
    QSPI_CMD.AddressMode = _AddrMode;
    QSPI_CMD.AddressSize = _AddrSize;

    QSPI_CMD.DummyCycles = DunmyCycles;

    QSPI_CMD.DataMode = _DataMode;
    

    if(HAL_QSPI_Command(&QSPIHandle,&QSPI_CMD,1000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
}

void QSPI_Transmit(uint8_t *_pBuf, uint32_t _len)
{
    QSPIHandle.Instance->DLR=_len-1;
    if(HAL_QSPI_Transmit(&QSPIHandle,_pBuf,5000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
}

void QSPI_Receive(uint8_t *_pBuf, uint32_t _len)
{
    QSPIHandle.Instance->DLR=_len-1;
    if(HAL_QSPI_Receive(&QSPIHandle,_pBuf,5000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
}
