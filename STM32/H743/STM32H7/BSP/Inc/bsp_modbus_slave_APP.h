#ifndef __BSP_MODBUS_SLAVE_APP_H
#define __BSP_MODBUS_SLAVE_APP_H

#include "bsp_modbus_slave.h"

//01
#define LED1_ADDR               10
#define LED2_ADDR               11
#define LED3_ADDR               12
//02
#define KEY1_ADDR               10
#define KEY2_ADDR               11
#define KEY3_ADDR               12
//03
#define REG1_ADDR               0
#define REG2_ADDR               2
#define REG3_ADDR               4

typedef struct 
{
    uint16_t REG1_val;
    uint16_t REG2_val;
    uint16_t REG3_val;
}Modbus_Regv;


#endif // !__BSP_MODBUS_SLAVE_APP_H
