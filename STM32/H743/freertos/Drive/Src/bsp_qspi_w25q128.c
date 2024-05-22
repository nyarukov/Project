#include "bsp_qspi_w25q128.h"

static void QSPI_W25Qxx_Reset(void);
static void QSPI_W25Qxx_WriteEnable(void);
static void QSPI_W25Qxx_ENABLE(void);
static void QSPI_W25Qxx_DISABLE(void);
static uint8_t QSPI_W25Qxx_ReadStartReg(uint32_t _Regx);
static void QSPI_W25Qxx_WriteStartReg(uint32_t _Regx, uint8_t *_val);
static void QSPI_W25Qxx_GetBUSY(void);

/**
 * @brief 初始化W25Q128并复位
 * 
 */
void QSPI_W25Qxx_Init(void)
{
    QSPI_Init();
    QSPI_W25Qxx_Reset();
    QSPI_W25Qxx_GetBUSY();
}

/**
 * @brief 读取W25Q128ID
 * 
 * @return uint32_t 制造商ID,设备ID
 */
uint32_t QSPI_W25Qxx_ReadID(void)
{
    uint32_t _ID;
    uint8_t _buf[3];

    QSPI_SendCmd(CMD_JEDEC_ID, QSPI_INSTRUCTION_1_LINE,
                 0, QSPI_ADDRESS_NONE, QSPI_ADDRESS_24_BITS,
                 0, QSPI_DATA_1_LINE);
    QSPI_Receive(_buf, 3);

    _ID = (_buf[0] << 16) | (_buf[1] << 8) | _buf[2];
    return _ID;
}

/**
 * @brief 清除4K扇区
 * 
 * @param _Addr 扇区地址
 */
void QSPI_W25Qxx_Erase_Sector(uint32_t _Addr)
{
    QSPI_W25Qxx_WriteEnable();

    QSPI_SendCmd(CMD_SECTOR_ERASE, QSPI_INSTRUCTION_1_LINE,
                 _Addr, QSPI_ADDRESS_1_LINE, QSPI_ADDRESS_24_BITS,
                 0, QSPI_DATA_NONE);
    QSPI_W25Qxx_GetBUSY();
}

/**
 * @brief 擦除芯片
 * 
 */
void QSPI_W25Qxx_Chip_Erase(void){

    QSPI_W25Qxx_WriteEnable();

    QSPI_SendCmd(CMD_CHIP_ERASE,QSPI_INSTRUCTION_1_LINE,
                0,QSPI_ADDRESS_1_LINE,QSPI_ADDRESS_24_BITS,
                0,QSPI_DATA_NONE);
                
    QSPI_W25Qxx_GetBUSY();
}
/**
 * @brief W25Qxx四输入页编程
 * 
 * @param _pBuf 写入数据缓冲区
 * @param _Addr 写入地址
 * @param _len 写入长度
 */
void QSPI_W25Qxx_WriteBuff(uint8_t *_pBuf, uint32_t _Addr, uint32_t _len)
{
    if(_len>0x100){
        Error_Handler(__FILE__,__LINE__);
    }
    QSPI_W25Qxx_WriteEnable();
    
    QSPI_SendCmd(CMD_QUAD_QUAD_IN_PAGE_PROGRAM, QSPI_INSTRUCTION_1_LINE,
                 _Addr, QSPI_ADDRESS_1_LINE, QSPI_ADDRESS_24_BITS, 
                 0, QSPI_DATA_4_LINES);
    QSPI_Transmit(_pBuf, _len);

    QSPI_W25Qxx_GetBUSY();
}

/**
 * @brief W25Qxx快速四输入输出读取
 * 
 * @param _pBuf 读取数据缓冲区
 * @param _Addr 读取地址
 * @param _len 读取长度
 */
void QSPI_W25Qxx_ReadBuff(uint8_t *_pBuf, uint32_t _Addr, uint32_t _len)
{
    QSPI_W25Qxx_ENABLE();
    
    QSPI_SendCmd(CMD_FAST_READ_QUAD_IO, QSPI_INSTRUCTION_4_LINES,
                 _Addr, QSPI_ADDRESS_4_LINES, QSPI_ADDRESS_24_BITS, 
                 2, QSPI_DATA_4_LINES);
    QSPI_Receive(_pBuf, _len);

    QSPI_W25Qxx_DISABLE();
}

/**
 * @brief QSPI内存映射，地址 0x90000000
 * 
 */
void QSPI_W25Qxx_MemoryMapped(void){
    QSPI_CommandTypeDef QSPI_CMD={0};
    QSPI_MemoryMappedTypeDef QSPI_Memory={0};

    QSPI_CMD.Instruction=CMD_FAST_READ_QUAD_IO;
    QSPI_CMD.InstructionMode=QSPI_INSTRUCTION_1_LINE;

    QSPI_CMD.AddressSize=QSPI_ADDRESS_24_BITS;
    QSPI_CMD.AddressMode=QSPI_ADDRESS_4_LINES;

    QSPI_CMD.AlternateByteMode=QSPI_ALTERNATE_BYTES_NONE;    
    QSPI_CMD.DdrHoldHalfCycle=QSPI_DDR_HHC_ANALOG_DELAY;
    QSPI_CMD.DdrMode=QSPI_DDR_MODE_DISABLE;
    QSPI_CMD.SIOOMode=QSPI_SIOO_INST_EVERY_CMD;

    QSPI_CMD.DummyCycles=6;

    QSPI_CMD.DataMode=QSPI_DATA_4_LINES;

    QSPI_Memory.TimeOutActivation=QSPI_TIMEOUT_COUNTER_DISABLE;
    QSPI_Memory.TimeOutPeriod=0;

    if (HAL_QSPI_MemoryMapped(&QSPIHandle, &QSPI_CMD, &QSPI_Memory) != HAL_OK)
    {
       Error_Handler(__FILE__, __LINE__);
    }
}
/**
 * @brief QSPI写使能
 *
 */
static void QSPI_W25Qxx_WriteEnable(void)
{
    QSPI_SendCmd(CMD_WRITE_ENABLE, QSPI_INSTRUCTION_1_LINE,
                 0, QSPI_ADDRESS_NONE, 0,
                 0, QSPI_DATA_NONE);
}

/**
 * @brief 进入QSPI模式
 *
 */
static void QSPI_W25Qxx_ENABLE(void)
{
    QSPI_SendCmd(CMD_QSPIMODE_ENABLE,QSPI_INSTRUCTION_1_LINE,0,QSPI_ADDRESS_NONE,QSPI_ADDRESS_24_BITS,0,QSPI_DATA_NONE);
}

/**
 * @brief 退出QSPI模式
 *
 */
static void QSPI_W25Qxx_DISABLE(void)
{
    QSPI_SendCmd(CMD_QSPIMODE_DISABLE,QSPI_INSTRUCTION_4_LINES,0,QSPI_ADDRESS_NONE,QSPI_ADDRESS_24_BITS,0,QSPI_DATA_NONE);
}

/**
 * @brief 复位W25Qxx
 * 
 */
static void QSPI_W25Qxx_Reset(void){
    QSPI_SendCmd(CMD_FLASH_RESET_ENABLE,QSPI_INSTRUCTION_1_LINE,
                0,QSPI_ADDRESS_1_LINE,QSPI_ADDRESS_24_BITS,
                0,QSPI_DATA_NONE);

    QSPI_SendCmd(CMD_FLASH_RESET_DISABLE,QSPI_INSTRUCTION_1_LINE
                ,0,QSPI_ADDRESS_1_LINE,QSPI_ADDRESS_24_BITS,
                0,QSPI_DATA_NONE);
}

/**
 * @brief 读取状态寄存器
 *
 * @param _Regx 状态寄存器
 *      @arg @ref   CMD_READ_STATUS_REGISTER_1
 *      @arg @ref   CMD_READ_STATUS_REGISTER_2
 *      @arg @ref   CMD_READ_STATUS_REGISTER_3
 * @return uint8_t 状态寄存器值
 */
static uint8_t QSPI_W25Qxx_ReadStartReg(uint32_t _Regx)
{
    uint8_t Start = 0;

    QSPI_SendCmd(_Regx, QSPI_INSTRUCTION_1_LINE,
                 0, QSPI_ADDRESS_NONE, QSPI_ADDRESS_24_BITS,
                 0, QSPI_DATA_1_LINE);
    QSPI_Receive(&Start, 1);

    return Start;
}

/**
 * @brief 写入状态寄存器
 *
 * @param _Regx 状态寄存器
 *      @arg @ref   CMD_WRITE_STATUS_REGISTER_1
 *      @arg @ref   CMD_WRITE_STATUS_REGISTER_2
 *      @arg @ref   CMD_WRITE_STATUS_REGISTER_3
 * @param _val 写入值
 */
static void QSPI_W25Qxx_WriteStartReg(uint32_t _Regx, uint8_t *_val)
{
    QSPI_SendCmd(_Regx, QSPI_INSTRUCTION_1_LINE,
                 0, QSPI_ADDRESS_NONE, QSPI_ADDRESS_24_BITS,
                 0, QSPI_DATA_NONE);
    QSPI_Transmit(_val, 1);
}

/**
 * @brief 等待QSPI Flash就绪
 *
 */
static void QSPI_W25Qxx_GetBUSY(void)
{
    uint8_t flag = 0;
    do
    {
       flag = QSPI_W25Qxx_ReadStartReg(CMD_READ_STATUS_REGISTER_1);
    } while (flag & 0x01);
}

void QSPI_W25Qxx_Test(uint8_t val){
	
    printf("ID:%#X\r\n",QSPI_W25Qxx_ReadID());

    uint16_t i;
    uint8_t wbuf[]={0};
    uint8_t rbuf[]={0};
    uint8_t time_start,time_stop;
    for ( i = 0; i < 30; i++)
    {
        wbuf[i]=val;
        printf("wbuf[%d]:%#X\r\n",i,wbuf[i]);
    }

    time_start=HAL_GetTick();
    QSPI_W25Qxx_Erase_Sector(20);
    QSPI_W25Qxx_WriteBuff(wbuf,20,30);
    QSPI_W25Qxx_ReadBuff(rbuf,20,30);
    time_stop=HAL_GetTick();
    printf("Time%dms\r\n",time_stop-time_start);
    for ( i = 0; i < 30; i++)
    {
        printf("wbuf[%d]:%#X\t rbuf[%d]:%#X\r\n",i,wbuf[i],i,rbuf[i]);
    }
    
}