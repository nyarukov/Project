#ifndef __BSP_W25Q128_H
#define __BSP_W25Q128_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "main.h"

#include "bsp_hard_spi.h"

#define SPI_Init()                          Hard_SPI_Init()
#define SPI_CS(n)                           Hard_SPI_CS(n)
#define SPI_Transmit(TxBuf)                 Hard_SPI_Transmit(TxBuf)
#define SPI_Reveice()                       Hard_SPI_Reveice()
#define SPI_TransmitReceive(TxBuf)          Hard_SPI_TransmitReceive(TxBuf)

#define APP_SIZE                            0xF00000

#define CMD_WRITE_ENABLE                    0x06  // 写使能命令
#define CMD_VOLATILE_SR_WRITE_ENABLE        0x50  // 可挥发状态寄存器写使能命令
#define CMD_WRITE_DISABLE                   0x04  // 写禁止命令
#define CMD_MANUFACTURER_DEVICE_ID          0x90  // 制造商/设备 ID 命令
#define CMD_JEDEC_ID                        0x9F  // JEDEC ID 命令
#define CMD_READ_UNIQUE_ID                  0x4B  // 读取唯一 ID 命令
#define CMD_READ_DATA                       0x03  // 读取数据命令
#define CMD_FAST_READ                       0x0B  // 快速读取命令
#define CMD_PAGE_PROGRAM                    0x02  // 页面编程命令
#define CMD_SECTOR_ERASE_4KB                0x20  // 扇区擦除 (4KB) 命令
#define CMD_BLOCK_ERASE_32KB                0x52  // 块擦除 (32KB) 命令
#define CMD_BLOCK_ERASE_64KB                0xD8  // 块擦除 (64KB) 命令
#define CMD_CHIP_ERASE                      0xC7  // 芯片擦除命令
#define CMD_READ_STATUS_REGISTER_1          0x05  // 读取状态寄存器-1 命令
#define CMD_WRITE_STATUS_REGISTER_1         0x01  // 写入状态寄存器-1 命令
#define CMD_READ_STATUS_REGISTER_2          0x35  // 读取状态寄存器-2 命令
#define CMD_WRITE_STATUS_REGISTER_2         0x31  // 写入状态寄存器-2 命令
#define CMD_READ_STATUS_REGISTER_3          0x15  // 读取状态寄存器-3 命令
#define CMD_WRITE_STATUS_REGISTER_3         0x11  // 写入状态寄存器-3 命令
#define CMD_READ_SFDP_REGISTER              0x5A  // 读取 SFDP 寄存器命令
#define CMD_ERASE_SECURITY_REGISTER         0x44  // 擦除安全寄存器命令
#define CMD_PROGRAM_SECURITY_REGISTER       0x42  // 编程安全寄存器命令
#define CMD_READ_SECURITY_REGISTER          0x48  // 读取安全寄存器命令
#define CMD_GLOBAL_BLOCK_LOCK               0x7E  // 全局块锁定命令
#define CMD_GLOBAL_BLOCK_UNLOCK             0x98  // 全局块解锁命令
#define CMD_READ_BLOCK_LOCK                 0x3D  // 读取块锁定命令
#define CMD_INDIVIDUAL_BLOCK_LOCK           0x36  // 个别块锁定命令
#define CMD_INDIVIDUAL_BLOCK_UNLOCK         0x39  // 个别块解锁命令
#define CMD_ERASE_PROGRAM_SUSPEND           0x75  // 擦除/编程挂起命令
#define CMD_ERASE_PROGRAM_RESUME            0x7A  // 擦除/编程恢复命令
#define CMD_POWER_DOWN                      0xB9  // 关闭电源命令
#define CMD_RELEASE_POWER_DOWN_ID           0xAB  // 释放电源下降 / 读取 ID 命令
#define CMD_ENABLE_RESET                    0x66  // 启用复位命令
#define CMD_RESET_DEVICE                    0x99  // 复位设备命令
#define CMD_DUMMY_BYTE                      0xFF  // 交换数据

// 定义命令参数
#define ADDRESS_23_16(addr)     ((addr) >> 16)
#define ADDRESS_15_8(addr)      ((addr) >> 8)
#define ADDRESS_7_0(addr)       ((addr))

//设备ID
typedef enum
{
    W25Q80 = 0xEF4014,
    W25Q16 = 0xEF4015,
    W25Q32 = 0xEF4016,
    W25Q64 = 0xEF4017,
    W25Q128 = 0xEF4018,
} W25QXXX_ID_t;

void W25Qxx_Init(void);
uint32_t W25Qxx_ReadID(void);
void W25Qxx_Sector_Erase(uint32_t _Addr);
void W25Qxx_Chip_Erase(void);
void W25Qxx_PageWrite(uint32_t _Addr,uint8_t *_pBuf);
void W25Qxx_PageRead(uint32_t _Addr,uint8_t *_pBuf);
uint16_t W25Qxx_Write(uint32_t _Addr, uint8_t *_pBuf, uint32_t _len);
void W25Qxx_Read(uint32_t _Addr, uint8_t *_pBuf, uint32_t _len);
void W25Qxx_ReadOTAFlag(void);
void W25qxx_WriteOTAFlag(void);

#endif