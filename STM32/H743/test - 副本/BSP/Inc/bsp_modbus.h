#ifndef __BSP_MODBUS_H
#define __BSP_MODBUS_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"


#define MODBUS_ADDRESS          0x02  // Modbus 设备地址

#define LED1_ADDR               0x10  // 第一个 LED 的寄存器地址
#define LED2_ADDR               0x11  // 第二个 LED 的寄存器地址
#define LED3_ADDR               0x12  // 第三个 LED 的寄存器地址

#define KEY1_ADDR               0x10  // 第一个 KEY 的寄存器地址
#define KEY2_ADDR               0x11  // 第二个 KEY 的寄存器地址
#define KEY3_ADDR               0x12  // 第三个 KEY 的寄存器地址



void Modbus_Error(uint8_t *_pBuf);
void Modbus_check(uint8_t *_pBuf,uint8_t _len);

#endif // !__BSP_UART_H
