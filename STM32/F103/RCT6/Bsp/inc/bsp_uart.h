#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"
#include <stdarg.h>
#include <stdio.h>

#define USART_DEBUG USART1
#define ESP8266_UART USART3

#define LOG_Printf(fmt, ...) UsartPrintf(USART_DEBUG, fmt, ##__VA_ARGS__)
#define ESP_Send(fmt, ...) UsartPrintf(ESP8266_UART, fmt, ##__VA_ARGS__)

void USART1_Init(void);
void USART2_Init(void);
void USART3_Init(void);
void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len);
void UsartPrintf(USART_TypeDef *USARTx, char *fmt, ...);
void Uart_SendChar(USART_TypeDef *USARTx, uint8_t ch);

#endif // !__BSP_UART_H
