#ifndef __BSP_QSPI_W25Q128_H
#define __BSP_QSPI_W25Q128_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "bsp.h"

#define W25Q128_QSPI_FLASH_SIZE     25
#define CMD_WRITE_ENABLE                        0x06     // 写使能
#define CMD_JEDEC_ID                            0x9F     // JEDEC ID

#define CMD_READ_STATUS_REGISTER_1              0x05     // 读取状态寄存器-1
#define CMD_WRITE_STATUS_REGISTER_1             0x01     // 写入状态寄存器-1
#define CMD_READ_STATUS_REGISTER_2              0x35     // 读取状态寄存器-2
#define CMD_WRITE_STATUS_REGISTER_2             0x31     // 写入状态寄存器-2
#define CMD_READ_STATUS_REGISTER_3              0x15     // 读取状态寄存器-3
#define CMD_WRITE_STATUS_REGISTER_3             0x11     // 写入状态寄存器-3

#define CMD_EnterQSPIMode                       0x38
#define CMD_ExitQSPIMode                        0xFF

#define CMD_SECTOR_ERASE                        0x20     // 4KB扇区擦除
#define CMD_CHIP_ERASE                          0xC7     // 全擦除指令
#define CMD_QUAD_QUAD_IN_PAGE_PROGRAM           0x32     // 四输入页程序
#define CMD_FAST_READ_OUT_QUAD                  0x6B     // 快速读取四路输出
#define CMD_FAST_READ_QUAD_IO                   0xEB     // 快速读取四 I/O

extern QSPI_HandleTypeDef QSPIHandle;

void QSPI_Init(void);
void QSPI_SendCmd(uint32_t _Cmd, uint32_t _CmdMode,
                uint32_t _Addr, uint32_t _AddrMode,
                uint32_t _AddrSize, uint32_t DunmyCycles,
                uint32_t _DataMode);

void QSPI_Transmit(uint8_t *_pBuf, uint32_t _len);
void QSPI_Receive(uint8_t *_pBuf, uint32_t _len);
#endif
