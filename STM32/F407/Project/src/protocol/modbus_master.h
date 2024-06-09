/*
 * 项目名称: modbus_master
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: MODBUS主机协议
 */

#ifndef __MODBUS_MASTER_H
#define __MODBUS_MASTER_H

// 头文件内容...

#include "modbus.h"

typedef struct
{
    ModbusControl Control;
} ModbusMaster;

Status init_modbus_master(ModbusMaster *_Master,
                          COM_ID _IDx,
                          uint8_t _addr,
                          Status (*SendData)(COM_ID _Id,
                                             uint8_t *_pBuf,
                                             uint32_t _Len));

Status modbus_master_read_coils(ModbusMaster *_Master,
                                uint8_t _ID,
                                uint16_t _Addr,
                                uint8_t *_pBuf,
                                uint32_t _Len,
                                uint32_t _Timeout);

Status modbus_master_write_single_coil(ModbusMaster *_Master,
                                       uint8_t _ID,
                                       uint16_t _Addr,
                                       uint8_t _Status,
                                       uint32_t _Timeout);

Status modbus_master_read_discretes(ModbusMaster *_Master,
                                    uint8_t _ID,
                                    uint16_t _Addr,
                                    uint8_t *_pBuf,
                                    uint32_t _Len,
                                    uint32_t _Timeout);

Status modbus_master_read_single_holding(ModbusMaster *_Master,
                                         uint8_t _ID,
                                         uint16_t _Addr,
                                         uint16_t *_pBuf,
                                         uint32_t _Len,
                                         uint32_t _Timeout);

Status modbus_master_write_single_holding(ModbusMaster *_Master,
                                          uint8_t _ID,
                                          uint16_t _Addr,
                                          uint16_t _Buf,
                                          uint32_t _Timeout);

Status modbus_master_write_multiple_holdings(ModbusMaster *_Master,
                                             uint8_t _ID,
                                             uint16_t _Addr,
                                             uint16_t *_pBuf,
                                             uint32_t _Len,
                                             uint32_t _Timeout);

Status modbus_master_read_input(ModbusMaster *_Master,
                                uint8_t _ID,
                                uint16_t _Addr,
                                uint16_t *_pBuf,
                                uint32_t _Len,
                                uint32_t _Timeout);
#endif
