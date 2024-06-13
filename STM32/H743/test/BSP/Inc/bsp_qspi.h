#ifndef __BSP_QSPI_W25Q128_H
#define __BSP_QSPI_W25Q128_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp.h"

#define W25Q128_QSPI_FLASH_SIZE     25
#define CMD_WRITE_ENABLE                        0x06     // åä½¿è?
#define CMD_JEDEC_ID                            0x9F     // JEDEC ID

#define CMD_READ_STATUS_REGISTER_1              0x05     // è¯»åç¶æå¯å­å¨-1
#define CMD_WRITE_STATUS_REGISTER_1             0x01     // åå¥ç¶æå¯å­å¨-1
#define CMD_READ_STATUS_REGISTER_2              0x35     // è¯»åç¶æå¯å­å¨-2
#define CMD_WRITE_STATUS_REGISTER_2             0x31     // åå¥ç¶æå¯å­å¨-2
#define CMD_READ_STATUS_REGISTER_3              0x15     // è¯»åç¶æå¯å­å¨-3
#define CMD_WRITE_STATUS_REGISTER_3             0x11     // åå¥ç¶æå¯å­å¨-3

#define CMD_EnterQSPIMode                       0x38
#define CMD_ExitQSPIMode                        0xFF

#define CMD_SECTOR_ERASE                        0x20     // 4KBæåºæ¦é¤
#define CMD_CHIP_ERASE                          0xC7     // å¨æ¦é¤æä»?
#define CMD_QUAD_QUAD_IN_PAGE_PROGRAM           0x32     // åè¾å¥é¡µç¨åº
#define CMD_FAST_READ_OUT_QUAD                  0x6B     // å¿?éè?»ååè·¯è¾åº
#define CMD_FAST_READ_QUAD_IO                   0xEB     // å¿?éè?»åå? I/O

extern QSPI_HandleTypeDef QSPIHandle;

void QSPI_Init(void);
void QSPI_SendCmd(uint32_t _Cmd, uint32_t _CmdMode,
                uint32_t _Addr, uint32_t _AddrMode,
                uint32_t _AddrSize, uint32_t DunmyCycles,
                uint32_t _DataMode);

void QSPI_Transmit(uint8_t *_pBuf, uint32_t _len);
void QSPI_Receive(uint8_t *_pBuf, uint32_t _len);
#endif
