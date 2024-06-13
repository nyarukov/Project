#ifndef __UART_PROC_H
#define __UART_PROC_H

#include "user_function_proc.h"
#include "bsp_uart.h"

void Process_COM1(uint8_t *_pBuf, uint32_t _Len);
void Process_COM2(uint8_t *_pBuf, uint32_t _Len);
void Process_COM3(uint8_t *_pBuf, uint32_t _Len);
void Process_COM4(uint8_t *_pBuf, uint32_t _Len);
void Process_COM5(uint8_t *_pBuf, uint32_t _Len);
void Process_COM6(uint8_t *_pBuf, uint32_t _Len);
void Process_COM7(uint8_t *_pBuf, uint32_t _Len);
void Process_COM8(uint8_t *_pBuf, uint32_t _Len);

void Uart_Process_Function(uint8_t _Id, uint8_t *_pBuf, uint32_t _Len);

#endif /* __UART_PROC_H */
