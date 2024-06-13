#ifndef __SOFTIIC_H
#define __SOFTIIC_H

#include "stm32h7xx_hal.h"
#include "bit_control.h"
#include "stdbool.h"

#define SoftIIC_PORT        GPIOE
#define SoftIIC_SCL_Pin     GPIO_PIN_7
#define SoftIIC_SDA_Pin     GPIO_PIN_8

#define SoftIIC_SCL(n)        ((n)? __GPIO_SET_BIT(SoftIIC_PORT,SoftIIC_SCL_Pin):__GPIO_RESET_BIT(SoftIIC_PORT,SoftIIC_SCL_Pin))
#define SoftIIC_SDA(n)        ((n)? __GPIO_SET_BIT(SoftIIC_PORT,SoftIIC_SDA_Pin):__GPIO_RESET_BIT(SoftIIC_PORT,SoftIIC_SDA_Pin))
#define SoftIIC_READ_SDA      (__GPIO_IN_READ(SoftIIC_PORT,SoftIIC_SDA_Pin))
#define SoftIIC_SDA_Mode(n)   ((n)? (GPIOE->MODER|=1<<(8*2)):(GPIOE->MODER &=~(1<<(8*2))))

#define delayus(n)       HAL_Delay(n)

void SoftIIC_Init(void);
void SoftIIC_Start(void);
void SoftIIC_Stop(void);
void SoftIIC_SendByte(uint8_t txdata);
uint8_t SoftIIC_ReceiveByte(void);
void SoftIIC_SendACK(bool ack);
uint8_t SoftIIC_ReceiveACK(void);
// void SoftIIC_SendByte(uint8_t *pTxData, uint16_t Size);
// void SoftIIC_ReceiveByte(uint8_t *pTxData, uint16_t Size);
#endif 
