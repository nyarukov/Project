/*
 * 项目名称: uart
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: UART驱动
 */

#ifndef __UART_H
#define __UART_H

// 头文件内容...

#include "gpio.h"
#include "middle.h"
#include "Data_Proc.h"
// clang-format off

#if (UART_COUNT > 0)

typedef enum
{
    COM1 = COM1_IDX,
    COM2 = COM2_IDX,
    COM3 = COM3_IDX,
    COM4 = COM4_IDX,
    COM5 = COM5_IDX,
    COM6 = COM6_IDX,
    COM7 = COM7_IDX,
    COM8 = COM8_IDX
} COM_ID;

typedef struct COM_Config
{
    USART_TypeDef *Port;
    uint32_t Buad;
    uint8_t Tx_IO;
    uint8_t Rx_IO;
    uint8_t Rs_IO;
    uint8_t Data : 4;
    uint8_t Stop : 2;
    uint8_t Parity : 2;
    Buffer_t TxBuf;
    Buffer_t RxBuf;
    void (*Callback)(uint8_t *_pBuf, uint32_t _Len);
} COM_Config;


extern struct COM_Config    Com_Config[UART_COUNT];

#define COM_OF(com)         (Com_Config[(com)])

#define DEBUG               COM1

#define _LOG(...)           BF_Printf(DEBUG, __VA_ARGS__)
#define _ERR_LOG            BF_Printf(DEBUG, "Error in file %s, line %d, function %s\n", __FILE__, __LINE__, __func__)
// clang-format on

void Init_Com(void);
Status Uart_SendData(COM_ID _Id, uint8_t *_pBuf, uint32_t _Len);
void BF_Printf(COM_ID _Id, const char *format, ...);
#else

#define _LOG(...)
#define _ERR_LOG

#endif
#endif