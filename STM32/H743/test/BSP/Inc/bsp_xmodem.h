#ifndef __BSP_XMODEM_H
#define __BSP_XMODEM_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"

typedef struct
{
    uint8_t Package_num;
    uint8_t Reverse_code;
    uint8_t Buffer[1024];
    uint16_t crc;
}Xmodem_t;


#endif // !__BSP_XMODEM_H
