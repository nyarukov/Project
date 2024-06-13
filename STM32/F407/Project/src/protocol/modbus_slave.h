/*
 * 项目名称: modbus_slave
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01
 * 描述: MODBUS从机协议
 */

#ifndef __MODBUS_SLAVE_H
#define __MODBUS_SLAVE_H

// 头文件内容...

#include "modbus.h"

typedef struct
{
    ModbusRegisters Registers;
    ModbusControl Control;
} ModbusSlave;

extern ModbusSlave Salve1;

#define MODBUS_SLAVE_WRITE_COIL(_Addr, _pBuf, _Len) \
    Modbus_Slave_Write_Coil(&Salve1, _Addr, _pBuf, _Len);

#define MODBUS_SLAVE_WRITE_DISCRETE(_Addr, _pBuf, _Len) \
    Modbus_Slave_Write_Discrete(&Salve1, _Addr, _pBuf, _Len);

#define MODBUS_SLAVE_WRITE_HOLDING(_Addr, _pBuf, _Len) \
    Modbus_Slave_Write_Holding(&Salve1, _Addr, _pBuf, _Len);

#define MODBUS_SLAVE_WRITE_INPUT(_Addr, _pBuf, _Len) \
    Modbus_Slave_Write_Input(&Salve1, _Addr, _pBuf, _Len);

Status init_modbus_slave(ModbusSlave *_Slave,
                         COM_ID _IDx,
                         uint8_t _addr,
                         Status (*SendData)(COM_ID _Id,
                                            uint8_t *_pBuf,
                                            uint32_t _Len),
                         size_t _holding_size,
                         size_t _input_size,
                         size_t _coils_size,
                         size_t _discrete_size);

Status free_modbus_slave(ModbusSlave *slave);

Status Modbus_Slave_Proc(ModbusSlave *_Slave,
                         uint8_t *_pBuf,
                         uint32_t _Len);

Status Modbus_Slave_Write_Coil(ModbusSlave *_Slave,
                               uint16_t _Addr,
                               uint8_t *_pBuf,
                               uint32_t _Len);

Status Modbus_Slave_Write_Discrete(ModbusSlave *_Slave,
                                   uint16_t _Addr,
                                   uint8_t *_pBuf,
                                   uint32_t _Len);

Status Modbus_Slave_Write_Holding(ModbusSlave *_Slave,
                                  uint16_t _Addr,
                                  uint16_t *_pBuf,
                                  uint32_t _Len);

Status Modbus_Slave_Write_Input(ModbusSlave *_Slave,
                                uint16_t _Addr,
                                uint16_t *_pBuf,
                                uint32_t _Len);
#endif
