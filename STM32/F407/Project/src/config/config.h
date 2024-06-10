/*
 * 项目名称: config
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 项目配置
 */

#ifndef __CONFIG_H
#define __CONFIG_H

// 头文件内容...
#include "middle.h"

/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*                                          DI 配置相关的代码                                      */
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

// clang-format off
#define DI_MODE         GPIO_Mode_IN
#define DI_OTYP         GPIO_OType_OD
#define DI_PUPD         GPIO_PuPd_UP

#define DI_NUM          (0)

#define DI_GROUP        BYTE_COUNT(DI_NUM)

#define DI1             PE4
#define DI2             PE3
#define DI3             PE2

// clang-format on

/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*                                          DO 配置相关的代码                                      */
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

// clang-format off
#define DO_MODE         GPIO_Mode_OUT
#define DO_OTYP         GPIO_OType_PP
#define DO_SPEED        GPIO_Speed_50MHz

#define DO_NUM          (2)

#define DO_GROUP        BYTE_COUNT(DO_NUM)

#define DO1             PF9
#define DO2             PF10

// clang-format on

/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*                                          UART 配置相关的代码                                      */
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

// clang-format off
#define UART1_EN        1
#define UART2_EN        1
#define UART3_EN        0
#define UART4_EN        0
#define UART5_EN        0
#define UART6_EN        0
#define UART7_EN        0
#define UART8_EN        0

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
    #define UART1_PARITY                (0)             // 校验位    0->无   1->奇   2->偶

    #define UART1_TX_BUF_SIZE           (1 * 512)
    #define UART1_RX_BUF_SIZE           (1 * 512)

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

#define COM8_IDX    (COM7_IDX + 1)
#else
#define COM8_IDX    COM7_IDX

#endif

#define UART_COUNT          (COM8_IDX + 1)

// clang-format on

/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*                                          I2C 配置相关的代码                                       */
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

// clang-format off

#define I2C_CLOCK               500000
#define soft_delay(n)           Delay_Us(I2C_CLOCK / (n))

#define I2C_CMD_WRITE           (0xFE)
#define I2C_CMD_READ            (0x01)

#define I2C1_EN    0
#define I2C2_EN    0
#define I2C3_EN    0
#define I2C4_EN    0

#define I2C_MODE_MASTER         0
#define I2C_MODE_SLAVE          1

#if I2C1_EN == 1
    #define I2C1_SCL            PD6
    #define I2C1_SDA            PD7

    #define I2C1_MODE           I2C_MODE_MASTER
    #define I2C1_CLOCK_SPEED    100000

    #define I2C1_SLAVE_ADDR     0x10

    #if I2C1_MODE == I2C_MODE_MASTER

        #define I2C1_SLAVE_COUNT    2

    #else
        #define I2C1_TX_BUF_SIZE  64
    #endif

#define I2C1_IDX    (0)
#else
#define I2C1_IDX    (-1)

#endif

#if I2C2_EN == 1
    #define I2C2_SCL            PB6
    #define I2C2_SDA            PB7

    #define I2C2_MODE           I2C_MODE_MASTER
    #define I2C2_CLOCK_SPEED    100000

    #define I2C2_SLAVE_ADDR     0x10

    #if I2C2_MODE == I2C_MODE_MASTER

        #define I2C2_SLAVE_COUNT    2

    #else

    #endif

    #define I2C2_IDX    (I2C1_IDX + 1)
#else
    #define I2C2_IDX    I2C1_IDX
#endif

#if I2C3_EN == 1
    #define I2C3_SCL            PB8
    #define I2C3_SDA            PB9

    #define I2C3_MODE           I2C_MODE_MASTER
    #define I2C3_CLOCK_SPEED    100000

    #define I2C3_SLAVE_ADDR     0x10

    #if I2C3_MODE == I2C_MODE_MASTER

        #define I2C3_SLAVE_COUNT    2
        
    #else

    #endif

    #define I2C3_IDX    (I2C2_IDX + 1)
#else
    #define I2C3_IDX    I2C2_IDX
#endif

#if I2C4_EN == 1
    #define I2C4_SCL            PD6
    #define I2C4_SDA            PD7

    #define I2C4_MODE           I2C_MODE_MASTER
    #define I2C4_CLOCK_SPEED    100000

    #define I2C4_SLAVE_ADDR     0x10

    #if I2C4_MODE == I2C_MODE_MASTER
        
        #define I2C4_SLAVE_COUNT    2

    #else

    #endif

    #define I2C4_IDX    (I2C3_IDX + 1)
#else
    #define I2C4_IDX    I2C3_IDX
#endif

#define I2C_COUNT       (I2C4_IDX + 1)
// clang-format on

#endif
