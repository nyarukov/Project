#ifndef __BSP_MODBUS_SLAVE_H
#define __BSP_MODBUS_SLAVE_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"


#define MODBUS_ADDRESS          11

typedef struct {
    uint16_t reg_addr;
    uint16_t reg_count;
    uint16_t reg_val;
    uint16_t crc;
    uint8_t reg_length;
    uint8_t buffer[128];
} Modbus_Slave_t;


void Modbus_check(uint8_t *_pBuf,uint8_t _len);

__weak uint8_t Modbus_01H_Callback(uint16_t _Addr);
__weak uint8_t Modbus_02H_Callback(uint16_t _Addr);
__weak uint16_t Modbus_03H_Callback(uint16_t _Addr);
__weak uint16_t Modbus_04H_Callback(uint16_t _Addr);
__weak void Modbus_05H_Callback(uint16_t _Addr,uint16_t _Data);
__weak void Modbus_06H_Callback(uint16_t _Addr,uint16_t _Data);
__weak void Modbus_10H_Callback(uint16_t _Addr,uint16_t _Data);
#endif // !__BSP_UART_H
