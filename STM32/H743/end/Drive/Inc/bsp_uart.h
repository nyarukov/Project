#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "stdio.h"
#include "string.h"


typedef struct{
    uint8_t RxbufArr;
    uint8_t Rxbuf[1024];
    uint16_t RxCnt;
    uint8_t	RXFlag;
}RX_TCB;

extern RX_TCB Uart1;
extern UART_HandleTypeDef huart1;

void Serial1_Init(uint32_t baudrate);
void Serial1_SendChar(uint8_t ch);
uint8_t Serial1_ReceiveChar(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif // !__BSP_UART_H
