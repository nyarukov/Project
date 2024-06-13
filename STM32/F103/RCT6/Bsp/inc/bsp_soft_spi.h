#ifndef __BSP_Soft_SPI_H
#define __BSP_Soft_SPI_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"

#define Soft_SPI_CS_Pin GPIO_Pin_11
#define Soft_SPI_SCLK_Pin GPIO_Pin_7
#define Soft_SPI_MOSI_Pin GPIO_Pin_6

#define Soft_SPI_CS(n) ((n) ? __GPIO_SET_BIT(GPIOA, 11) : __GPIO_RESET_BIT(GPIOA, 11))
#define Soft_SPI_SCLK(n) ((n) ? __GPIO_SET_BIT(GPIOA, 7) : __GPIO_RESET_BIT(GPIOA, 7))
#define Soft_SPI_MOSI(n) ((n) ? __GPIO_SET_BIT(GPIOA, 6) : __GPIO_RESET_BIT(GPIOA, 6))

void Soft_SPI_Init(void);
void Soft_SPI_Transmit(uint8_t _Byte);

#endif
