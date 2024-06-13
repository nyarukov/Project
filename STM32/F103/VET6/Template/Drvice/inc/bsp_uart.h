#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "bf_middle.h"
#include "bsp_gpio.h"

#define DEBUG  COM2
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

typedef enum{
    UART_REMAP_NO,
    UART_REMAP_1,
    UART_REMAP_2,
    UART_REMAP_3
}Uart_Remap;

#define UART1_EN 1
#define UART2_EN 1
#define UART3_EN 0
#define UART4_EN 0
#define UART5_EN 0
#define UART6_EN 0
#define UART7_EN 0
#define UART8_EN 0

#define UART_RS485_IO_NO        255

#if UART1_EN == 1
    #define UART1_TX            PB6
    #define UART1_RX            PB7
    
    #define UART1_RS            UART_RS485_IO_NO
    #define UART1_REMAP         UART_REMAP_1

    #define UART1_BAUD          115200      
    #define UART1_DATA          8           
    #define UART1_STOP          1           
    #define UART1_PARITY        0           

    #define UART1_TX_BUF_SIZE   (1 * 1024)
    #define UART1_RX_BUF_SIZE   (1 * 1024)

#endif

#if UART2_EN == 1
    #define UART2_TX            PD5
    #define UART2_RX            PD6
    
    #define UART2_RS            PD4
    #define UART2_REMAP         UART_REMAP_1

    #define UART2_BAUD          115200      
    #define UART2_DATA          8           
    #define UART2_STOP          1           
    #define UART2_PARITY        0           

    #define UART2_TX_BUF_SIZE   (1 * 1024)
    #define UART2_RX_BUF_SIZE   (1 * 1024)

#endif

#if UART3_EN == 1
    #define UART3_TX            PD8
    #define UART3_RX            PD9

    #define UART3_RS            PD10
    #define UART3_REMAP         UART_REMAP_3

    #define UART3_BAUD          115200
    #define UART3_DATA          8     
    #define UART3_STOP          1     
    #define UART3_PARITY        0     

    #define UART3_TX_BUF_SIZE   (1 * 1024)
    #define UART3_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART4_EN == 1
    #define UART4_TX            PC10
    #define UART4_RX            PC11

    #define UART4_RS            PD3
    #define UART4_REMAP         UART_REMAP_NO

    #define UART4_BAUD          115200
    #define UART4_DATA          8     
    #define UART4_STOP          1     
    #define UART4_PARITY        0     

    #define UART4_TX_BUF_SIZE   (1 * 1024)
    #define UART4_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART5_EN == 1
    #define UART5_TX            PC12
    #define UART5_RX            PD2
    
    #define UART5_RS            UART_RS485_IO_NO
    #define UART5_REMAP         UART_REMAP_NO

    #define UART5_BAUD          115200
    #define UART5_DATA          8     
    #define UART5_STOP          1     
    #define UART5_PARITY        0     

    #define UART5_TX_BUF_SIZE   (1 * 1024)
    #define UART5_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART6_EN == 1
    #define UART6_TX            PB1
    #define UART6_RX            PB2
    
    #define UART6_RS            UART_RS485_IO_NO
    #define UART6_REMAP         UART_REMAP_NO

    #define UART6_BAUD          115200 
    #define UART6_DATA          8      
    #define UART6_STOP          1      
    #define UART6_PARITY        0      

    #define UART6_TX_BUF_SIZE   (1 * 1024)
    #define UART6_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART7_EN == 1
    #define UART7_TX            PB1
    #define UART7_RX            PB2
    
    #define UART7_RS            UART_RS485_IO_NO
    #define UART7_REMAP         UART_REMAP_NO

    #define UART7_BAUD          115200
    #define UART7_DATA          8     
    #define UART7_STOP          1     
    #define UART7_PARITY        0     

    #define UART7_TX_BUF_SIZE   (1 * 1024)
    #define UART7_RX_BUF_SIZE   (1 * 1024)
#endif

#if UART8_EN == 1
    #define UART8_TX            PB1
    #define UART8_RX            PB2
    #define UART8_RS            UART_RS485_IO_NO

    #define UART8_BAUD          115200
    #define UART8_DATA          8     
    #define UART8_STOP          1     
    #define UART8_PARITY        0     

    #define UART8_TX_BUF_SIZE   (1 * 1024)
    #define UART8_RX_BUF_SIZE   (1 * 1024)
#endif

#define UART_COUNT              (UART1_EN + UART2_EN + \
                                 UART3_EN + UART4_EN + \
                                 UART5_EN + UART6_EN + \
                                 UART7_EN + UART8_EN)


void Uart_Init(void);
void BF_Printf(COM_ID _Id, const char *format, ...);


#endif // !__BSP_UART_H
