#ifndef __BSP_SOFT_I2C_H
#define __BSP_SOFT_I2C_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "stdbool.h"
#include "bsp_systick.h"


void Soft_I2C_Init(void);
void Soft_I2C_Start(void);
void Soft_I2C_Stop(void);
void Soft_I2C_SendByte(uint8_t txdata);
uint8_t Soft_I2C_ReceiveByte(void);
void Soft_I2C_ReceiveBytes(uint8_t *pData,uint8_t len);
void Soft_I2C_SendACK(bool ack);
uint8_t Soft_I2C_ReceiveACK(void);
uint8_t Soft_I2C_AddrCheck(uint8_t _Addr);

#endif 
