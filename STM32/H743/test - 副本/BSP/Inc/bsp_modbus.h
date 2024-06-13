#ifndef __BSP_MODBUS_H
#define __BSP_MODBUS_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"


#define MODBUS_ADDRESS          0x02  // Modbus �豸��ַ

#define LED1_ADDR               0x10  // ��һ�� LED �ļĴ�����ַ
#define LED2_ADDR               0x11  // �ڶ��� LED �ļĴ�����ַ
#define LED3_ADDR               0x12  // ������ LED �ļĴ�����ַ

#define KEY1_ADDR               0x10  // ��һ�� KEY �ļĴ�����ַ
#define KEY2_ADDR               0x11  // �ڶ��� KEY �ļĴ�����ַ
#define KEY3_ADDR               0x12  // ������ KEY �ļĴ�����ַ



void Modbus_Error(uint8_t *_pBuf);
void Modbus_check(uint8_t *_pBuf,uint8_t _len);

#endif // !__BSP_UART_H
