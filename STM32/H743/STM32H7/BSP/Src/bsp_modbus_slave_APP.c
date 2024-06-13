#include "bsp_modbus_slave_app.h"

Modbus_Regv reg_val;

uint8_t Modbus_01H_Callback(uint16_t _Addr)
{
    switch (_Addr)
    {
    case LED1_ADDR:
        return (__GPIO_OUT_READ(GPIOA, 11) ? 0 : 1);
    case LED2_ADDR:
        return (__GPIO_OUT_READ(GPIOA, 12) ? 0 : 1);
    case LED3_ADDR:
        return (__GPIO_OUT_READ(GPIOA, 15) ? 0 : 1);
    }
    return 0;
}

uint8_t Modbus_02H_Callback(uint16_t _Addr)
{
    switch (_Addr)
    {
    case KEY1_ADDR:
        return (__GPIO_IN_READ(GPIOB, 3) ? 0 : 1);
    case KEY2_ADDR:
        return (__GPIO_IN_READ(GPIOB, 4) ? 0 : 1);
    case KEY3_ADDR:
        return (__GPIO_IN_READ(GPIOB, 5) ? 0 : 1);
    }
    return 0;
}

uint16_t Modbus_03H_Callback(uint16_t _Addr)
{
    switch (_Addr)
    {
    case REG1_ADDR:
        return reg_val.REG1_val;
    case REG2_ADDR:
        return reg_val.REG2_val;
    case REG3_ADDR:
        return reg_val.REG3_val;
    }
    return 0;
}

uint16_t Modbus_04H_Callback(uint16_t _Addr)
{
    switch (_Addr)
    {
    case REG1_ADDR:
        return 0xF88D;
    case REG2_ADDR:
        return 0x4668;
    case REG3_ADDR:
        return 0xFE8E;
    }
    return 0;
}
void Modbus_05H_Callback(uint16_t _Addr,uint16_t _Data)
{
    switch (_Addr)
    {
    case LED1_ADDR:
        __SET_GPIO_LOW_IF_EQUAL(GPIOA, 11, _Data, 0xFF00);
        break;
    case LED2_ADDR:
        __SET_GPIO_LOW_IF_EQUAL(GPIOA, 12,_Data, 0xFF00);
        break;
    case LED3_ADDR:
        __SET_GPIO_LOW_IF_EQUAL(GPIOA, 15, _Data, 0xFF00);
        break;
    }
}
void Modbus_06H_Callback(uint16_t _Addr,uint16_t _Data)
{
    switch (_Addr)
    {
    case REG1_ADDR:
        reg_val.REG1_val = _Data;
        break;
    case REG2_ADDR:
        reg_val.REG2_val = _Data;
        break;
    case REG3_ADDR:
        reg_val.REG3_val = _Data;
        break;
    }
}
void Modbus_10H_Callback(uint16_t _Addr,uint16_t _Data)
{
     switch (_Addr)
    {
    case REG1_ADDR:
        reg_val.REG1_val = _Data;
        break;
    case REG2_ADDR:
        reg_val.REG2_val = _Data;
        break;
    case REG3_ADDR:
        reg_val.REG3_val = _Data;
        break;
    }
}
