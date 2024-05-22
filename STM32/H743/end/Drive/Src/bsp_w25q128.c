#include "bsp_w25q128.h"

//static void W25Qxx_RESET_DEVICE(void);
static void W25Qxx_Write_ENABLE(void);
//static void W25Qxx_Write_DISABLE(void);
static void W25Qxx_GetBUSY(void);
static uint8_t W25Qxx_GetReg(uint8_t reg);
//static void W25Qxx_SetReg(uint8_t reg, uint8_t val);

#define W25Q128_PAGE_SIZE       256
#define W25Q128_Sector_SIZE     4096
#define W25Q128_BLOCK_SIZE      65536
#define W25Q128_FLASH_SIZE      16777216

/**
 * @brief 初始化W25Qxx存储器
 */
void W25Qxx_Init(void)
{
    SPI_Init();
    // W25Qxx_RESET_DEVICE();
}

/**
 * @brief 读取W25Qxx存储器的设备ID
 * 
 * @return uint32_t 返回设备ID MID,DID
 */
uint32_t W25Qxx_ReadID(void)
{
    uint8_t i;
    uint8_t _ID[3];

    SPI_CS(0);
    SPI_Transmit(CMD_JEDEC_ID);
    for (i = 0; i < 3; i++)
    {
        _ID[i] = SPI_Reveice();
    }
    SPI_CS(1);
    return ((_ID[0] << 16) | (_ID[1] << 8) | _ID[2]);
}

/**
 * @brief 擦除W25Qxx存储器中指定扇区
 * 
 * @param _Addr 扇区的起始地址
 */
void W25Qxx_Sector_Erase(uint32_t _Addr)
{
    W25Qxx_GetBUSY();
    W25Qxx_Write_ENABLE();

    SPI_CS(0);
    SPI_Transmit(CMD_SECTOR_ERASE_4KB);
    SPI_Transmit(ADDRESS_23_16(_Addr & 0xFF0000));
    SPI_Transmit(ADDRESS_15_8(_Addr & 0x00F000));
    SPI_Transmit(ADDRESS_7_0(_Addr & 0x000000));
    SPI_CS(1);
}

/**
 * @brief 对整个W25Qxx芯片进行擦除
 */
void W25Qxx_Chip_Erase(void)
{
    W25Qxx_GetBUSY();
    W25Qxx_Write_ENABLE();

    SPI_CS(0);
    SPI_Transmit(CMD_CHIP_ERASE);
    SPI_CS(1);
}

/**
 * @brief 将数据写入W25Qxx存储器的指定页面
 * 
 * @param _Addr 写入的起始地址
 * @param _pBuf 写入的数据缓冲区
 */
void W25Qxx_PageWrite(uint32_t _Addr, uint8_t *_pBuf)
{
    uint16_t len = 256;

    W25Qxx_GetBUSY();
    W25Qxx_Write_ENABLE();

    SPI_CS(0);

    SPI_Transmit(CMD_PAGE_PROGRAM);
    SPI_Transmit(ADDRESS_23_16(_Addr & 0xFF0000));
    SPI_Transmit(ADDRESS_15_8(_Addr & 0x00FF00));
    SPI_Transmit(ADDRESS_7_0(_Addr & 0x000000));
    while (len--)
    {
        SPI_Transmit(*_pBuf);
        _pBuf++;
    }

    SPI_CS(1);
}

/**
 * @brief 从W25Qxx存储器的指定页面读取数据
 * 
 * @param _Addr 读取的起始地址
 * @param _pBuf 存储读取数据的缓冲区
 */
void W25Qxx_PageRead(uint32_t _Addr, uint8_t *_pBuf)
{
    uint16_t len = 256;

    W25Qxx_GetBUSY();

    SPI_CS(0);

    SPI_Transmit(CMD_READ_DATA);
    SPI_Transmit(ADDRESS_23_16(_Addr & 0xFF0000));
    SPI_Transmit(ADDRESS_15_8(_Addr & 0x00FF00));
    SPI_Transmit(ADDRESS_7_0(_Addr & 0x0000FF));

    while (len--)
    {
        *_pBuf = SPI_Reveice();
        _pBuf++;
    }
    SPI_CS(1);
}

/**
 * @brief 将数据写入W25Qxx存储器
 * 
 * @param _Addr 写入的起始地址
 * @param _pBuf 写入的数据缓冲区
 * @param _len 写入的数据长度（字节）
 * @return uint16_t W25Qxx_GetBUSY返回写入的扇区数和页数的组合,高8位扇区数，低8位页数
 */
uint16_t W25Qxx_Write(uint32_t _Addr, uint8_t *_pBuf, uint32_t _len)
{
    uint32_t pagesize, pagenot;
    uint32_t sectorsize, sectornot;
    uint32_t pagenum, sectornum;
    // 计算整页数量和不足一页的剩余字节数
    pagesize = _len >> 8;
    pagenot = _len & 255;
    // 计算整扇区数量和不足一个扇区的标志
    sectorsize = pagesize >> 4;
    sectornot = ((pagesize & 15) | pagenot) ? 1 : 0;
    // 擦除扇区
    for (sectornum = 0; sectornum < sectorsize; sectornum++)
    {
        W25Qxx_Sector_Erase(_Addr+(sectornum << 12));
    }
    // 处理不足一个扇区的情况
    if (sectornot--)
    {
        W25Qxx_Sector_Erase(_Addr+(sectorsize<<12) );
        sectorsize += 1;
    }
    // 写入数据到页面
    for (pagenum = 0; pagenum < pagesize; pagenum++)
    {
        W25Qxx_PageWrite(_Addr + (pagenum << 8), _pBuf + (pagenum << 8));
    }
    // 处理不足一页的情况
    if (pagenot--)
    {
        W25Qxx_PageWrite(_Addr + (pagesize << 8), _pBuf + (pagesize << 8));
        pagesize += 1;
    }
    // 返回写入的扇区数和页数
    return ((sectorsize << 8) & 0xFF00) | (pagesize & 0xFF);
}

/**
 * @brief 从W25Qxx存储器中指定地址开始读取数据
 * 
 * @param _Addr 读取的起始地址
 * @param _pBuf 存储读取数据的缓冲区
 * @param _len 读取的数据长度（字节）
 */
void W25Qxx_Read(uint32_t _Addr, uint8_t *_pBuf, uint32_t _len)
{

    W25Qxx_GetBUSY();

    SPI_CS(0);

    SPI_Transmit(CMD_READ_DATA);
    SPI_Transmit(ADDRESS_23_16(_Addr & 0xFF0000));
    SPI_Transmit(ADDRESS_15_8(_Addr & 0x00FF00));
    SPI_Transmit(ADDRESS_7_0(_Addr & 0x0000FF));

    while (_len--)
    {
        *_pBuf= SPI_Reveice();
        _pBuf++;
    }
    SPI_CS(1);
}

// /**
//  * @brief 重置W25Qxx存储器设备
//  */
// static void W25Qxx_RESET_DEVICE(void)
// {
//     SPI_CS(0);
//     SPI_Transmit(CMD_RESET_DEVICE);
//     SPI_CS(1);
// }

/**
 * @brief 启用W25Qxx存储器的写使能状态
 */
static void W25Qxx_Write_ENABLE(void)
{
    SPI_CS(0);
    SPI_Transmit(CMD_WRITE_ENABLE);
    SPI_CS(1);
}

// /**
//  * @brief 禁用W25Qxx存储器的写使能状态
//  */
// static void W25Qxx_Write_DISABLE(void)
// {
//     SPI_CS(0);
//     SPI_Transmit(CMD_WRITE_DISABLE);
//     SPI_CS(1);
// }

/**
 * @brief 检查W25Qxx存储器是否处于忙碌状态
 */
static void W25Qxx_GetBUSY(void)
{
    uint8_t start;
    do
    {
        start = W25Qxx_GetReg(CMD_READ_STATUS_REGISTER_1);
    } while ((start & 0x1) == 0x1);
}

/**
 * @brief 读取W25Qxx存储器的指定寄存器值
 * 
 * @param reg 要读取的寄存器地址
 * @return uint8_t 返回寄存器的值
 */
static uint8_t W25Qxx_GetReg(uint8_t reg)
{
    uint8_t regval;
    SPI_CS(0);
    SPI_Transmit(reg);
    regval = SPI_Reveice();
    SPI_CS(1);
    return regval;
}

// /**
//  * @brief 设置W25Qxx存储器的指定寄存器值
//  * 
//  * @param reg 要设置的寄存器地址
//  * @param val 要写入寄存器的值
//  */
// static void W25Qxx_SetReg(uint8_t reg, uint8_t val)
// {
//     SPI_CS(0);
//     SPI_Transmit(reg);
//     SPI_Transmit(val);
//     SPI_CS(1);
// }


#if FALSH_Test
    void W25Qxx_Test(void)
    {
        W25Qxx_Init();

        printf("ID:%#X\r\n", W25Qxx_ReadID());

        uint16_t i;
        uint16_t size =12289;
        uint8_t wbuf[size];
        uint8_t rbuf[size];
        uint8_t time_start, time_stop;

        for (i = 0; i < size; i++)
        {
            wbuf[i] = 0xDC;
        }

        time_start = HAL_GetTick();
        W25Qxx_Write(0xC000,wbuf,size);
        W25Qxx_Read(0xC000,rbuf,size);
        time_stop = HAL_GetTick();
        for (i = 0; i < size; i++)
        {
            if(wbuf[i]!=rbuf[i]){
                printf("wbuf[%d]:%#X\t rbuf[%d]:%#X\t\n", i, wbuf[i], i, rbuf[i]);
            }
            
        }
        printf("Time:%dms\r\n", time_stop - time_start);
    }
#endif
