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

#include "middle.h"
#include "uart.h"
#include "DI.h"
#include "DO.h"

// clang-format off
#define MODBUS_ADDRESS              1

#define MODEBUS_RX_BUFSIZE          128

#define Input_Reg_Count             16
#define Holding_Reg_Count           16

extern uint8_t Input_Registers[Input_Reg_Count];            // 输入寄存器
extern uint8_t Holding_Registers[Holding_Reg_Count];        // 保持寄存器
// clang-format on

Status Modbus_Slave(uint8_t *_pBuf, uint16_t _Len);

#endif
