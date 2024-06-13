#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "stdio.h"

void Uart_Init(uint32_t baudrate);
//void Uart_SendChar(uint8_t ch);
//void Uart_SendString(uint8_t *str);
//void Uart_SendArray(uint8_t *arr,uint32_t length);
//void Uart_num(u64 num);
//void Uart_Printf(uint8_t *str,u64 num);
#endif // !__BSP_UART_H
