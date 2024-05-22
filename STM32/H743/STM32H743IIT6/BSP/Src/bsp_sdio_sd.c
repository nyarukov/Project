#include "bsp_sdio_sd.h"

SD_HandleTypeDef SDHandle;

void SD_Init(void)
{
    /* if CLKDIV = 0 then SDMMC Clock frequency = SDMMC Kernel Clock
    else SDMMC Clock frequency = SDMMC Kernel Clock / [2 * CLKDIV].
    240MHz / (2*3) = 40MHz
    */
    SDHandle.Instance = SDMMC1;
    SDHandle.Init.ClockDiv = 0;
    SDHandle.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    SDHandle.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
    SDHandle.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    SDHandle.Init.BusWide = SDMMC_BUS_WIDE_4B;

    if (HAL_SD_Init(&SDHandle) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

void HAL_SD_MspInit(SD_HandleTypeDef *hsd)
{

    RCC_PeriphCLKInitTypeDef SD_CLK = {0};
    GPIO_InitTypeDef SD_Struct = {0};

    SD_CLK.PeriphClockSelection = RCC_PERIPHCLK_SDMMC;
    SD_CLK.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL;

    if (HAL_RCCEx_PeriphCLKConfig(&SD_CLK) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

    __HAL_RCC_SDMMC1_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*SDMMC1 GPIO Configuration
    PC8     ------> SDMMC1_D0
    PC9     ------> SDMMC1_D1
    PC10     ------> SDMMC1_D2
    PC11     ------> SDMMC1_D3
    PC12     ------> SDMMC1_CK
    PD2     ------> SDMMC1_CMD  */
    SD_Struct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12;
    SD_Struct.Mode = GPIO_MODE_AF_PP;
    SD_Struct.Pull = GPIO_NOPULL;
    SD_Struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    SD_Struct.Alternate = GPIO_AF12_SDIO1;
    HAL_GPIO_Init(GPIOC, &SD_Struct);

    SD_Struct.Pin = GPIO_PIN_2;
    SD_Struct.Mode = GPIO_MODE_AF_PP;
    SD_Struct.Pull = GPIO_NOPULL;
    SD_Struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    SD_Struct.Alternate = GPIO_AF12_SDIO1;
    HAL_GPIO_Init(GPIOD, &SD_Struct);

    HAL_NVIC_SetPriority(SDMMC1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
}
void HAL_SD_MspDeInit(SD_HandleTypeDef *sdHandle)
{

    __HAL_RCC_SDMMC1_CLK_DISABLE();

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);
    HAL_NVIC_DisableIRQ(SDMMC1_IRQn);
}
/**
 * @brief  以轮询模式从 SD 卡中的指定地址读取块。
 * @param  pData: 指向包含要传输的数据的缓冲区的指针
 * @param  ReadAddr: 读取数据的地址
 * @param  NumOfBlocks: 要读取的 SD 块数
 * @param  Timeout: 读操作超时
 */
void SD_ReadBlocks(uint8_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{

    if (HAL_SD_ReadBlocks(&SDHandle, pData, ReadAddr, NumOfBlocks, Timeout) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

/**
 * @brief  以轮询模式将块写入 SD 卡中的指定地址。
 * @param  pData: 指向包含要传输的数据的缓冲区的指针
 * @param  WriteAddr: 数据写入地址
 * @param  NumOfBlocks: 要写入的 SD 块数
 * @param  Timeout: 写操作超时
 */
void SD_WriteBlocks(uint8_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
    if (HAL_SD_WriteBlocks(&SDHandle, pData, WriteAddr, NumOfBlocks, Timeout) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

/**
 * @brief  擦除给定 SD 卡的指定存储区域。
 * @param  StartAddr: 起始字节地址
 * @param  EndAddr: 结束字节地址
 */
void SD_Erase(uint32_t StartAddr, uint32_t EndAddr)
{

    if (HAL_SD_Erase(&SDHandle, StartAddr, EndAddr) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

/**
 * @brief  获取当前SD卡数据状态。
 * @retval 数据传输状态。
 *          该值可以是以下值之一：
 *            @arg  SD_TRANSFER_OK: 没有数据传输正在执行
 *            @arg  SD_TRANSFER_BUSY: 数据传输正在执行
 * @retval SD_TRANSFER_OK : SD_TRANSFER_BUSY
 */
uint8_t SD_GetCardState(void)
{
    return ((HAL_SD_GetCardState(&SDHandle) == HAL_SD_CARD_TRANSFER) ? SD_TRANSFER_OK : SD_TRANSFER_BUSY);
}

/**
 * @brief  获取有关特定 SD 卡的 SD 信息。
 * @param  CardInfo: 指向 HAL_SD_CardInfoTypedef 结构的指针
 */
void SD_GetCardInfo(SD_CardInfo *CardInfo)
{
    HAL_SD_GetCardInfo(&SDHandle, CardInfo);
}

void SD_Test(void)
{
    uint16_t i;
    uint8_t wbuf[512];
    uint8_t rbuf[512];
    for (i = 0; i < 512; i++)
    {
        wbuf[i] = 0xAA;
        rbuf[i] = 0xCC;
    }

    SD_Init();
    SD_Erase(0, 512);
    SD_WriteBlocks(wbuf, 0x10, 10, 5000);
    HAL_Delay(1000);
    SD_ReadBlocks(rbuf, 0x10, 10, 5000);
    for (i = 0; i < 512; i++)
    {
        printf("wbuf[%d]:%#X\t rbuf[%d]:%#X\r\n", i, wbuf[i], i, rbuf[i]);
    }
}