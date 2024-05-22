#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32f4xx.h"
#include "bf_lib.h"
#include "bsp_gpio.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


#define DEBUG  COM1
#define _LOG(fmt, ...)    BF_Printf(DEBUG, fmt, __VA_ARGS__)

#define _ERR_LOG          BF_Printf(DEBUG,"Error in file %s, line %d, function %s\n", __FILE__, __LINE__, __func__)



typedef enum
{
    COM1 = 0,
    COM2,
    COM3,
    COM4,
    COM5,
    COM6,
    COM7,
    COM8,
    COM_MAX
} COM_ID;

#define PRBUFFER_SIZE 256

#define UART1_EN 1
#define UART2_EN 0
#define UART3_EN 0
#define UART4_EN 0
#define UART5_EN 0
#define UART6_EN 0
#define UART7_EN 0
#define UART8_EN 0

#define UART_RS485_IO_NO        255

#if UART1_EN == 1
    #define UART1_TX            PA9
    #define UART1_RX            PA10
    #define UART1_RS            UART_RS485_IO_NO

    #define UART1_BAUD          115200      //波特率
    #define UART1_DATA          8           //数据位
    #define UART1_STOP          1           //停止位
    #define UART1_PARITY        0           //校验位

    #define UART1_TX_BUF_SIZE   (1 * 1024)
    #define UART1_RX_BUF_SIZE   (1 * 1024)

#endif

#if UART2_EN == 1
    #define UART2_TX            PA2
    #define UART2_RX            PA3
    #define UART2_RS            PG8

    #define UART2_BAUD          115200      // 波特率
    #define UART2_DATA          8           // 数据位
    #define UART2_STOP          1           // 停止位
    #define UART2_PARITY        0           // 校验位

    #define UART2_TX_BUF_SIZE   (1 * 1024)
    #define UART2_RX_BUF_SIZE   (1 * 1024)

#endif

#if UART3_EN == 1
    #define UART3_TX            PB10
    #define UART3_RX            PB11
    #define UART3_RS            UART_RS485_IO_NO

    #define UART3_BAUD          115200      // 波特率
    #define UART3_DATA          8           // 数据位
    #define UART3_STOP          1           // 停止位
    #define UART3_PARITY        0           // 校验位

    #define UART3_TX_BUF_SIZE   (1 * 1024)
    #define UART3_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART4_EN == 1
    #define UART4_TX            PB1// Define the TX pin for UART4
    #define UART4_RX            PB2// Define the RX pin for UART4
    #define UART4_RS            UART_RS485_IO_NO

    #define UART4_BAUD          115200      // 波特率
    #define UART4_DATA          8           // 数据位
    #define UART4_STOP          1           // 停止位
    #define UART4_PARITY        0           // 校验位

    #define UART4_TX_BUF_SIZE   (1 * 1024)
    #define UART4_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART5_EN == 1
    #define UART5_TX            PB1// Define the TX pin for UART5
    #define UART5_RX            PB2// Define the RX pin for UART5
    #define UART5_RS            UART_RS485_IO_NO

    #define UART5_BAUD          115200      // 波特率
    #define UART5_DATA          8           // 数据位
    #define UART5_STOP          1           // 停止位
    #define UART5_PARITY        0           // 校验位

    #define UART5_TX_BUF_SIZE   (1 * 1024)
    #define UART5_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART6_EN == 1
    #define UART6_TX            PB1// Define the TX pin for UART6
    #define UART6_RX            PB2// Define the RX pin for UART6
    #define UART6_RS            UART_RS485_IO_NO

    #define UART6_BAUD          115200      // 波特率
    #define UART6_DATA          8           // 数据位
    #define UART6_STOP          1           // 停止位
    #define UART6_PARITY        0           // 校验位

    #define UART6_TX_BUF_SIZE   (1 * 1024)
    #define UART6_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART7_EN == 1
    #define UART7_TX            PB1// Define the TX pin for UART7
    #define UART7_RX            PB2// Define the RX pin for UART7
    #define UART7_RS            UART_RS485_IO_NO

    #define UART7_BAUD          115200      // 波特率
    #define UART7_DATA          8           // 数据位
    #define UART7_STOP          1           // 停止位
    #define UART7_PARITY        0           // 校验位

    #define UART7_TX_BUF_SIZE   (1 * 1024)
    #define UART7_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART8_EN == 1
    #define UART8_TX            PB1// Define the TX pin for UART8
    #define UART8_RX            PB2// Define the RX pin for UART8
    #define UART8_RS            UART_RS485_IO_NO

    #define UART8_BAUD          115200      // 波特率
    #define UART8_DATA          8           // 数据位
    #define UART8_STOP          1           // 停止位
    #define UART8_PARITY        0           // 校验位

    #define UART8_TX_BUF_SIZE   (1 * 1024)
    #define UART8_RX_BUF_SIZE   (1 * 1024)
#endif

#define UART_COUNT (UART1_EN + UART2_EN + \
                    UART3_EN + UART4_EN + \
                    UART5_EN + UART6_EN + \
                    UART7_EN + UART8_EN)


void Uart_Init(void);

void Uart_String(COM_ID _Id, uint8_t *ch);
void BF_Printf(COM_ID _Id, const char *format, ...);

#endif // !__BSP_UART_H
