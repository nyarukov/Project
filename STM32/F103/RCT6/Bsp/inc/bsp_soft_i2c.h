#ifndef __BSP_SOFT_I2C_H
#define __BSP_SOFT_I2C_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"
#include "stdbool.h"
#include "bsp_systick.h"
#include "bsp_uart.h"

void Soft_I2C_Init(void);
void Soft_I2C_Start(void);
void Soft_I2C_Stop(void);
void Soft_I2C_SendByte(uint8_t Byte);
uint8_t Soft_I2C_ReceiveByte(void);
void Soft_I2C_SendAck(uint8_t AckBit);
uint8_t Soft_I2C_ReceiveAck(void);
uint8_t Soft_I2C_AddrCheck(uint8_t address);
void Soft_I2C_ScanDevices(void);

#endif
