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
#include "modbus_slave.h"

#define DEBUG COM1

#define _LOG(fmt, ...) BF_Printf(DEBUG, fmt, __VA_ARGS__)

#define _ERR_LOG BF_Printf(DEBUG, "Error in file %s, line %d, function %s\n", __FILE__, __LINE__, __func__)

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

// clang-format off

#define UART1_EN        1
#define UART2_EN        1
#define UART3_EN        0
#define UART4_EN        0
#define UART5_EN        0
#define UART6_EN        0
#define UART7_EN        0
#define UART8_EN        0

#define UART_COUNT      (COM8_IDX + 1)


#define UART_RS485_IO_NO    (255)

#define UART_REUSE_NO       (255)

#if UART1_EN == 1

    #define UART1_TX                    PA9
    #define UART1_RX                    PA10
    #define UART1_REUSE                 GPIO_AF_USART1
    #define UART1_RS                    UART_RS485_IO_NO

    #define UART1_BAUD                  (115200)        // 波特率
    #define UART1_DATA                  (0)             // 数据位    0->8    1->9
    #define UART1_STOP                  (0)             // 停止位    0->1    1->2
    #define UART1_PARITY                (0)             // 校验位    0->无   1-     >奇   2->偶

    #define UART1_TX_BUF_SIZE           (1 * 512)
    #define UART1_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART1_TX_BUFFER[UART1_TX_BUF_SIZE];
        extern uint8_t UART1_RX_BUFFER[UART1_RX_BUF_SIZE];

        #define COM1_IDX    (0)
        #else
        #define COM1_IDX    (-1)

#endif

#if UART2_EN == 1
    #define UART2_TX                    PA2
    #define UART2_RX                    PA3
    #define UART2_REUSE                 GPIO_AF_USART2
    #define UART2_RS                    PG8

    #define UART2_BAUD                  (115200) // 波特率
    #define UART2_DATA                  (0)      // 数据位
    #define UART2_STOP                  (0)      // 停止位
    #define UART2_PARITY                (0)    // 校验位

    #define UART2_TX_BUF_SIZE           (1 * 512)
    #define UART2_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART2_TX_BUFFER[UART2_TX_BUF_SIZE];
        extern uint8_t UART2_RX_BUFFER[UART2_RX_BUF_SIZE];

        #define COM2_IDX    (COM1_IDX + 1)
        #else
        #define COM2_IDX    COM1_IDX

#endif

#if UART3_EN == 1
    #define UART3_TX                    PB10
    #define UART3_RX                    PB11
    #define UART3_REUSE                 GPIO_AF_USART3
    #define UART3_RS                    UART_RS485_IO_NO

    #define UART3_BAUD                  (115200) // 波特率
    #define UART3_DATA                  (0)      // 数据位
    #define UART3_STOP                  (0)      // 停止位
    #define UART3_PARITY                (0)    // 校验位

    #define UART3_TX_BUF_SIZE           (1 * 512)
    #define UART3_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART3_TX_BUFFER[UART3_TX_BUF_SIZE];
        extern uint8_t UART3_RX_BUFFER[UART3_RX_BUF_SIZE];

        #define COM3_IDX    (COM2_IDX + 1)
        #else
        #define COM3_IDX    COM2_IDX

#endif

#if UART4_EN == 1
    #define UART4_TX                    PB1 // Define the TX pin for UART4
    #define UART4_RX                    PB2 // Define the RX pin for UART4
    #define UART4_REUSE                 GPIO_AF_UART4
    #define UART4_RS                    UART_RS485_IO_NO

    #define UART4_BAUD                  (115200) // 波特率
    #define UART4_DATA                  (0)      // 数据位
    #define UART4_STOP                  (0)      // 停止位
    #define UART4_PARITY                (0)    // 校验位

    #define UART4_TX_BUF_SIZE           (1 * 512)
    #define UART4_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART4_TX_BUFFER[UART4_TX_BUF_SIZE];
        extern uint8_t UART4_RX_BUFFER[UART4_RX_BUF_SIZE];

        #define COM4_IDX    (COM3_IDX + 1)
        #else
        #define COM4_IDX    COM3_IDX

#endif

#if UART5_EN == 1
    #define UART5_TX                    PB1 // Define the TX pin for UART5
    #define UART5_RX                    PB2 // Define the RX pin for UART5
    #define UART5_REUSE                 GPIO_AF_UART5
    #define UART5_RS                    UART_RS485_IO_NO

    #define UART5_BAUD                  (115200) // 波特率
    #define UART5_DATA                  (0)      // 数据位
    #define UART5_STOP                  (0)      // 停止位
    #define UART5_PARITY                (0)    // 校验位

    #define UART5_TX_BUF_SIZE           (1 * 512)
    #define UART5_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART5_TX_BUFFER[UART5_TX_BUF_SIZE];
        extern uint8_t UART5_RX_BUFFER[UART5_RX_BUF_SIZE];

        #define COM5_IDX    (COM4_IDX + 1)
        #else
        #define COM5_IDX    COM4_IDX

#endif

#if UART6_EN == 1
    #define UART6_TX                    PB1 // Define the TX pin for UART6
    #define UART6_RX                    PB2 // Define the RX pin for UART6
    #define UART6_REUSE                 GPIO_AF_USART6
    #define UART6_RS                    UART_RS485_IO_NO

    #define UART6_BAUD                  (115200) // 波特率
    #define UART6_DATA                  (0)      // 数据位
    #define UART6_STOP                  (0)      // 停止位
    #define UART6_PARITY                (0)    // 校验位

    #define UART6_TX_BUF_SIZE           (1 * 512)
    #define UART6_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART6_TX_BUFFER[UART6_TX_BUF_SIZE];
        extern uint8_t UART6_RX_BUFFER[UART6_RX_BUF_SIZE];

        #define COM6_IDX    (COM5_IDX + 1)
        #else
        #define COM6_IDX    COM5_IDX

#endif

#if UART7_EN == 1
    #define UART7_TX                    PB1 // Define the TX pin for UART7
    #define UART7_RX                    PB2 // Define the RX pin for UART7
    #define UART7_REUSE                 GPIO_AF_UART7
    #define UART7_RS                    UART_RS485_IO_NO

    #define UART7_BAUD                  (115200) // 波特率
    #define UART7_DATA                  (0)      // 数据位
    #define UART7_STOP                  (0)      // 停止位
    #define UART7_PARITY                (0)    // 校验位

    #define UART7_TX_BUF_SIZE           (1 * 512)
    #define UART7_RX_BUF_SIZE           (1 * 512)

        extern uint8_t UART7_TX_BUFFER[UART7_TX_BUF_SIZE];
        extern uint8_t UART7_RX_BUFFER[UART7_RX_BUF_SIZE];

        #define COM7_IDX    (COM6_IDX + 1)
        #else
        #define COM7_IDX    COM6_IDX

#endif

#if UART8_EN == 1
    #define UART8_TX                    PB1 // Define the TX pin for UART8
    #define UART8_RX                    PB2 // Define the RX pin for UART8
    #define UART8_REUSE                 GPIO_AF_UART8
    #define UART8_RS                    UART_RS485_IO_NO

    #define UART8_BAUD                  (115200) // 波特率
    #define UART8_DATA                  (0)      // 数据位
    #define UART8_STOP                  (0)      // 停止位
    #define UART8_PARITY                (0)    // 校验位

    #define UART8_TX_BUF_SIZE           (1 * 512)
    #define UART8_RX_BUF_SIZE           (1 * 512)

        extern extern uint8_t UART8_TX_BUFFER[UART8_TX_BUF_SIZE];
        extern extern uint8_t UART8_RX_BUFFER[UART8_RX_BUF_SIZE];

        #define COM8_IDX    (COM7_IDX + 1)
        #else
        #define COM8_IDX    COM7_IDX

#endif
// clang-format on

#if (UART_COUNT > 0)

void COM_Init(void);
Status Uart_SendData(COM_ID _Id, uint8_t *_pBuf, uint32_t _Len);
void BF_Printf(COM_ID _Id, const char *format, ...);

#endif

#endif
