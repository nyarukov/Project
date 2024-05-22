#ifndef __BSP_SDIO_SD_H
#define __BSP_SDIO_SD_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "bsp.h"


#define   SD_TRANSFER_OK                ((uint8_t)0x00)
#define   SD_TRANSFER_BUSY              ((uint8_t)0x01)

#define SD_CardInfo HAL_SD_CardInfoTypeDef

void SD_Init(void);
void SD_ReadBlocks(uint8_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout);
void SD_WriteBlocks(uint8_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout);
void SD_Erase(uint32_t StartAddr, uint32_t EndAddr);
uint8_t SD_GetCardState(void);
void SD_GetCardInfo(SD_CardInfo *CardInfo);
void SD_Test(void);
#endif // !__BSP_EXIT_H
