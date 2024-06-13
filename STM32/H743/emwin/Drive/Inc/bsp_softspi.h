#ifndef __BSP_SOFTSPI_H
#define __BSP_SOFTSPI_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"

#define SoftSPI_PORT        GPIOA
#define SoftSPI_CS_Pin      GPIO_PIN_4
#define SoftSPI_SCLK_Pin    GPIO_PIN_5
#define SoftSPI_MISO_Pin    GPIO_PIN_6
#define SoftSPI_MOSI_Pin    GPIO_PIN_7

#define SoftSPI_CS(n)         ((n)? __GPIO_SET_BIT(SoftSPI_PORT,4):__GPIO_RESET_BIT(SoftSPI_PORT,4))
#define SoftSPI_SCLK(n)       ((n)? __GPIO_SET_BIT(SoftSPI_PORT,5):__GPIO_RESET_BIT(SoftSPI_PORT,5))
#define SoftSPI_MOSI(n)       ((n)? __GPIO_SET_BIT(SoftSPI_PORT,7):__GPIO_RESET_BIT(SoftSPI_PORT,7))
#define SoftSPI_MISO          (__GPIO_IN_READ(SoftSPI_PORT,6))

void SoftSPI_Init(void);
void SoftSPI_SendByte(uint8_t *pTxData, uint16_t Size);
void SoftSPI_ReceiveByte(uint8_t *pTxData, uint16_t Size);
void SoftSPI_SendReceiveByte(uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
uint8_t SoftSPI_SendReceive(uint8_t TxData);

#endif 
