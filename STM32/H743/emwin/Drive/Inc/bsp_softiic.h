#ifndef __BSP_SOFTIIC_H
#define __BSP_SOFTIIC_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "stdbool.h"

#define SoftIIC_PORT        GPIOB
#define SoftIIC_SCL_Pin     8
#define SoftIIC_SDA_Pin     9

#define SoftIIC_SCL(n)        ((n)? __GPIO_SET_BIT(SoftIIC_PORT,SoftIIC_SCL_Pin):__GPIO_RESET_BIT(SoftIIC_PORT,SoftIIC_SCL_Pin))
#define SoftIIC_SDA(n)        ((n)? __GPIO_SET_BIT(SoftIIC_PORT,SoftIIC_SDA_Pin):__GPIO_RESET_BIT(SoftIIC_PORT,SoftIIC_SDA_Pin))
#define SoftIIC_READ_SDA      (__GPIO_IN_READ(SoftIIC_PORT,SoftIIC_SDA_Pin))
#define SoftIIC_SDA_Mode(n)   ((n)? __GPIO_OUTPUT(SoftIIC_PORT,SoftIIC_SDA_Pin):__GPIO_INPUT(SoftIIC_PORT,SoftIIC_SDA_Pin))

#define delay(n)       HAL_Delay(n)

void SoftIIC_Init(void);
void SoftIIC_Start(void);
void SoftIIC_Stop(void);
void SoftIIC_SendByte(uint8_t txdata);
uint8_t SoftIIC_ReceiveByte(void);
void SoftIIC_ReceiveBytes(uint8_t *pData,u8 len);
void SoftIIC_SendACK(bool ack);
uint8_t SoftIIC_ReceiveACK(void);

#endif 
