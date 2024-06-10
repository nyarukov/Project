/*
 * 项目名称: modbus_rtu
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-10 14:04:35
 * 最后修改日期: 2024-06-10 14:04:35
 * 描述: modbus_rtu
 */

#ifndef __MODBUS_RTU_H
#define __MODBUS_RTU_H

// 头文件内容...

#include "middle.h"
#include "uart.h"

// clang-format off
#define MODBUS_RTU_MIN_FRAME_SIZE       4       // 接受最少长度
// clang-format on

typedef struct modbus_rtu_frame
{
    uint8_t addr;
    uint8_t function;
    uint8_t byte;
    uint8_t buf[255];
    uint16_t crc;
    uint16_t length;
} ModbusRTUFrame;

Status modbus_rtu_read_coils(COM_ID _Id, uint8_t _Chx,
                             uint8_t _Addr, uint8_t _Num,
                             uint8_t *_pBuf, uint32_t _TimeOut);

typedef struct modbus_rtu_registers
{
    uint16_t *_HoldingRegisters_ptr;
    uint16_t *_InputRegisters_ptr;
    uint8_t *_Coils_ptr;
    uint8_t *_DiscreteInputs_ptr;
    size_t _HoldingRegisters_size;
    size_t _InputRegisters_size;
    size_t _Coils_size;
    size_t _DiscreteInputs_size;
} __attribute__((packed)) ModbusRtuRegisters;

typedef struct modbus_rtu_control
{
    COM_ID Com;
    uint8_t Addr;
    uint8_t Status;
    Status (*SendData)(COM_ID _Id,
                       uint8_t *_pBuf,
                       uint32_t _Len);
} __attribute__((packed)) ModbusRtuControl;

#endif
