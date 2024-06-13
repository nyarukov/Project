/*
 * 项目名称: modbus_master
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: MODBUS主机协议
 */

#ifndef __MODBUS_H
#define __MODBUS_H

// 头文件内容...

#include "middle.h"
#include "uart.h"

typedef struct modbus_registers
{
    uint16_t *_HoldingRegisters_ptr;
    uint16_t *_InputRegisters_ptr;
    uint8_t *_Coils_ptr;
    uint8_t *_DiscreteInputs_ptr;
    size_t _HoldingRegisters_size;
    size_t _InputRegisters_size;
    size_t _Coils_size;
    size_t _DiscreteInputs_size;
} __attribute__((packed)) ModbusRegisters;

typedef struct modbus_control
{
    COM_ID Com;
    uint8_t Addr;
    uint8_t Status;
    Status (*SendData)(COM_ID _Id,
                       uint8_t *_pBuf,
                       uint32_t _Len);
} __attribute__((packed)) ModbusControl;



#endif
