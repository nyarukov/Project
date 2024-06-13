#ifndef __UART_H
#define __UART_H

#include "stm32h7xx_hal.h"
#include "user_lib.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

typedef enum{
    COM1 = 0,
    COM2,
    COM3,
    COM4,
    COM5,
    COM6,
    COM7,
    COM8,
    COM_MAX
}COM_ID;


typedef struct{
    uint16_t write;
    uint16_t read;
    uint16_t lenght;
    uint8_t buffer[BUFFER_SIZE];
}RingBuffer_t;

extern RingBuffer_t buffer[COM_MAX];

uint8_t RingBuffer_Write(RingBuffer_t *_buffer, uint8_t *_pData,uint16_t _len);
uint8_t RingBuffer_Read(RingBuffer_t *_buffer, uint8_t *_pData,uint16_t _len);
uint8_t IsRingBufferEmpty(RingBuffer_t *_buffer);

void Com_Init(COM_ID _Com, uint32_t _BaudRaet);
void Com_printf(COM_ID _Com,char *fmt, ...);
void Com_SendChar(COM_ID _Com,uint8_t ch);
uint8_t Com_ReceiveChar(COM_ID _Com);
void Com_SendArr(COM_ID _Com,uint8_t *_Arr,uint16_t _Len);
#endif // !__UART_H
