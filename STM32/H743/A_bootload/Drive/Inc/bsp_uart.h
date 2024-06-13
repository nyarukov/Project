#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "string.h"
#include "stdio.h"

typedef struct{
    uint8_t RxbufArr;
    uint8_t Rxbuf[1024];
    uint16_t RxCnt;
    uint8_t	RXFlag;
}RX_TCB;

extern RX_TCB Uart1;
extern UART_HandleTypeDef huart1;

void Uart_Init(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
#endif // !__BSP_UART_H
