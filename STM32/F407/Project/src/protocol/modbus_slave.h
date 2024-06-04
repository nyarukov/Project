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

// clang-format off
#define MODBUS_ADDRESS          1

// clang-format on

typedef struct
{
    uint16_t reg_addr;
    uint16_t reg_count;
    uint16_t reg_val;
    uint16_t crc;
    uint8_t reg_length;
    uint8_t buffer[128];
} Modbus_Slave_t;

void Modbus_Slave(uint8_t *_pBuf, uint16_t _Len);
#endif
