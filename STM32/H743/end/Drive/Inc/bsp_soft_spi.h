#ifndef __BSP_Soft_SPI_H
#define __BSP_Soft_SPI_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"


#define Soft_SPI_CS(n)           ((n)? __GPIO_SET_BIT(GPIOA,4):__GPIO_RESET_BIT(GPIOA,4))

void Soft_SPI_Init(void);
void Soft_SPI_Transmit(uint8_t _Byte);
uint8_t Soft_SPI_Receive(void);
uint8_t Soft_SPI_TransmitReceive(uint8_t _Byte);

#endif 
