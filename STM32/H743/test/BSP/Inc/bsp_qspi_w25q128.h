#ifndef __BSP_QSPI_W25Qxx_W25Q128_H
#define __BSP_QSPI_W25Qxx_W25Q128_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_qspi.h"
#include "bsp.h"

#define CMD_WRITE_ENABLE                        0x06     // 写使�?
#define CMD_WRITE_DISABLE                       0x04     // 写�?��??

#define CMD_READ_STATUS_REGISTER_1              0x05     // 读取状态寄存器-1
#define CMD_READ_STATUS_REGISTER_2              0x35     // 读取状态寄存器-2
#define CMD_READ_STATUS_REGISTER_3              0x15     // 读取状态寄存器-3

#define CMD_WRITE_STATUS_REGISTER_1             0x01     // 写入状态寄存器-1
#define CMD_WRITE_STATUS_REGISTER_2             0x31     // 写入状态寄存器-2
#define CMD_WRITE_STATUS_REGISTER_3             0x11     // 写入状态寄存器-3

#define CMD_JEDEC_ID                            0x9F     // JEDEC ID
#define CMD_READ_UNIQUE_ID                      0x4B     // 读取�?一ID
#define CMD_MFTR_DEVICE_ID_DUAL_IO              0x92     // 制造商/设�?�ID双输入输�?
#define CMD_MFTR_DEVICE_ID_QUAD_IO              0x94     // 制造商/设�?�ID四输入输�?

#define CMD_FLASH_RESET_ENABLE                  0x66     // 使能复位
#define CMD_FLASH_RESET_DISABLE                 0x99     // 复位设�??


#define CMD_QSPIMODE_ENABLE                     0x38     // 进入QSPI模式
#define CMD_QSPIMODE_DISABLE                    0xFF     // 退出QSPI模式

#define CMD_PageProgram                         0x02     // 页面编程
#define CMD_QUAD_QUAD_IN_PAGE_PROGRAM           0x32     // 四输入页编程

#define CMD_SECTOR_ERASE                        0x20     // 扇区擦除�?4KB�?
#define CMD_BLOCK_32KB_ERASE                    0x52     // 块擦除（32KB�?
#define CMD_BLOCK_64KB_ERASE                    0xD8     // 块擦除（64KB�?
#define CMD_CHIP_ERASE                          0xC7     // �?片擦�?

#define CMD_READ_DATA                           0x03     // 读取数据
#define CMD_FAST_READ                           0x0B     // �?速�?�取
#define CMD_DUAL_OUT_FAST_READ                  0x3B     // �?速双输出读取
#define CMD_DUAL_INOUT_FAST_READ                0xBB     // �?速双输入输出读取
#define CMD_FAST_READ_OUT_QUAD                  0x6B     // �?速四输出读取
#define CMD_FAST_READ_QUAD_IO                   0xEB     // �?速四输入输出读取

void QSPI_W25Qxx_Init(void);
uint32_t QSPI_W25Qxx_ReadID(void);
void QSPI_W25Qxx_Erase_Sector(uint32_t _Addr);
void QSPI_W25Qxx_WriteBuff(uint8_t *_pBuf, uint32_t _Addr, uint32_t _len);
void QSPI_W25Qxx_ReadBuff(uint8_t *_pBuf, uint32_t _Addr, uint32_t _len);
void QSPI_W25Qxx_MemoryMapped(void);
void QSPI_W25Qxx_Test(uint8_t val);

#endif 
