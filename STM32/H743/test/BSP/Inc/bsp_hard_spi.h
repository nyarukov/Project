#ifndef __BSP_HARD_SPI_H
#define __BSP_HARD_SPI_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp.h"

#define Hard_SPI_CS(n)   ((n)? __GPIO_SET_BIT(GPIOA,4) :__GPIO_RESET_BIT(GPIOA,4))

extern SPI_HandleTypeDef SPI1_FLASH ;

void Hard_SPI_Init(void);
void Hard_SPI_Transmit(uint8_t _pBuffer);
uint8_t Hard_SPI_Reveice(void);
uint8_t Hard_SPI_TransmitReceive(uint8_t _pWBuffer);
void Hard_SPI_Test(void);

#endif
