#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_btim.h"
#include "stdio.h"

typedef struct
{
    uint8_t bufArr;
    uint8_t buffer[512];
    uint8_t Flag;
    uint16_t Cnt;
} UART_TCB;

extern UART_TCB Uart1;
extern UART_HandleTypeDef huart1;


void Uart_Init(void);
void u1_printf(char *fmt, ...);
void Uart_SendChar(uint8_t ch);
uint8_t Uart_ReceiveChar(void);
void Uart_SendArr(uint8_t *_Arr,uint16_t _Len);
#endif // !__BSP_UART_H
