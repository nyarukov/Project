// /*
//  * 项目名称: modbus_master
//  * 版本:1.0
//  * 作者: Yusaka
//  * 创建日期: 2024-06-01
//  * 最后修改日期: 2024-06-01 18:09:50
//  * 描述: MODBUS主机协议
//  */

// #include "modbus_master.h"

// // C 文件内容...

// // clang-format off
// #define READ_COILS                          0x01    // 读取线圈状态（读取开关量输入状态）
// #define READ_DISCRETE_INPUTS                0x02    // 读取输入状态（读取开关量输出状态）
// #define READ_HOLDING_REGISTERS              0x03    // 读取保持寄存器（读取存储的数据）
// #define READ_INPUT_REGISTERS                0x04    // 读取输入寄存器（读取存储的数据）
// #define WRITE_SINGLE_COIL                   0x05    // 强制单线圈（控制开关量输出）
// #define WRITE_MULTIPLE_COILS                0x0F    // 强制多单线圈（控制开关量输出）
// #define WRITE_SINGLE_REGISTER               0x06    // 写单个保持寄存器（控制存储的数据）
// #define WRITE_MULTIPLE_REGISTERS            0x10    // 写多个保持寄存器（控制存储的数据）

// #define ILLEGAL_FUNCTION                    0x01    // 非法功能码
// #define ILLEGAL_DATA_ADDRESS                0x02    // 非法数据地址
// #define ILLEGAL_DATA_VALUE                  0x03    // 非法数据值
// #define SLAVE_DEVICE_FAILURE                0x04    // 从机故障
// #define ACKNOWLEDGE                         0x05    // 确认
// #define SLAVE_DEVICE_BUSY                   0x06    // 从机忙
// #define NEGATIVE_ACKNOWLEDGE                0x07    // 否定确认
// #define PARITY_ERROR                        0x08    // 存储奇偶性差错
// // clang-format on

// /**
//  * @brief 初始化 Modbus 主站结构体。
//  *
//  * @param _Master 指向要初始化的 ModbusMaster 结构的指针。
//  * @param _IDx 通信端口号。
//  * @param _addr 主机设备地址。
//  * @param _timeout 超时持续时间（以毫秒为单位）。
//  * @param SendData 指向串口发送函数的指针。
//  * @return Status 返回初始化过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status init_modbus_master(ModbusMaster *_Master,
//                           COM_ID _IDx,
//                           uint8_t _addr,
//                           Status (*SendData)(COM_ID _Id,
//                                              uint8_t *_pBuf,
//                                              uint32_t _Len))
// {
//     if (_Master == BF_NULL)
//         return BF_NULL_POINTER;

//     _Master->Control.Addr = _addr;
//     _Master->Control.Com = _IDx;
//     _Master->Control.Status |= BF_INTI;
//     _Master->Control.SendData = SendData;
//     return BF_OK;
// }

// /**
//  * @brief 读取线圈状态。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 线圈的起始地址。
//  * @param _pBuf 指向存储读取数据的缓冲区。
//  * @param _Len 要读取的线圈数量。
//  * @return Status 返回读取过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status SendData(ModbusMaster *_Master,
//                 uint8_t *_pBuf,
//                 uint32_t _Len,
//                 uint32_t _Timeout)
// {
//     uint16_t _CRC = Check_Modbus_CRC16(_pBuf, _Len);

//     _pBuf[_Len] = LOW_BYTE(_CRC);
//     _pBuf[_Len + 1] = HIGH_BYTE(_CRC);

//     _Master->Control.SendData(_Master->Control.Com, _pBuf, _Len + 2);
//     return BF_OK;
// }

// /**
//  * @brief 写单个线圈状态。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 线圈的地址。
//  * @param _Status 线圈的状态（0 或 1）。
//  * @return Status 返回写入过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_send_request(ModbusMaster *_Master,
//                                   uint8_t _ID,
//                                   uint8_t function,
//                                   uint16_t _Addr,
//                                   uint16_t value_or_len,
//                                   uint32_t _Timeout)
// {
//     uint8_t Buf[8];
//     Buf[0] = _ID;
//     Buf[1] = function;
//     Buf[2] = HIGH_BYTE(_Addr);
//     Buf[3] = LOW_BYTE(_Addr);
//     Buf[4] = HIGH_BYTE(value_or_len);
//     Buf[5] = LOW_BYTE(value_or_len);
//     return SendData(_Master, Buf, 6);
// }

// /**
//  * @brief 读取线圈状态。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 线圈的起始地址。
//  * @param _pBuf 指向存储读取数据的缓冲区。
//  * @param _Len 要读取的线圈数量。
//  * @return Status 返回读取过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_read_coils(ModbusMaster *_Master,
//                                 uint8_t _ID,
//                                 uint16_t _Addr,
//                                 uint8_t *_pBuf,
//                                 uint32_t _Len,
//                                 uint32_t _Timeout)
// {

//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       READ_COILS,
//                                       _Addr,
//                                       _Len);
// }

// /**
//  * @brief 写单个线圈状态。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 线圈的地址。
//  * @param _Status 线圈的状态（0 或 1）。
//  * @return Status 返回写入过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_write_single_coil(ModbusMaster *_Master,
//                                        uint8_t _ID,
//                                        uint16_t _Addr,
//                                        uint8_t _Status,
//                                        uint32_t _Timeout)
// {
//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       WRITE_SINGLE_COIL,
//                                       _Addr,
//                                       (uint16_t)(((_Status) ? 0xFF : 0x00) << 8));
// }

// /**
//  * @brief 读取离散输入状态。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 离散输入的起始地址。
//  * @param _pBuf 指向存储读取数据的缓冲区。
//  * @param _Len 要读取的离散输入数量。
//  * @return Status 返回读取过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_read_discretes(ModbusMaster *_Master,
//                                     uint8_t _ID,
//                                     uint16_t _Addr,
//                                     uint8_t *_pBuf,
//                                     uint32_t _Len,
//                                     uint32_t _Timeout)
// {
//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       READ_DISCRETE_INPUTS,
//                                       _Addr,
//                                       _Len);
// }

// /**
//  * @brief 读取单个保持寄存器的值。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 保持寄存器的地址。
//  * @param _pBuf 指向存储读取数据的缓冲区。
//  * @param _Len 要读取的寄存器数量。
//  * @return Status 返回读取过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_read_single_holding(ModbusMaster *_Master,
//                                          uint8_t _ID,
//                                          uint16_t _Addr,
//                                          uint16_t *_pBuf,
//                                          uint32_t _Len,
//                                          uint32_t _Timeout)
// {
//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       READ_HOLDING_REGISTERS,
//                                       _Addr,
//                                       _Len);
// }

// /**
//  * @brief 写单个保持寄存器的值。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 保持寄存器的地址。
//  * @param _Buf 要写入的值。
//  * @return Status 返回写入过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_write_single_holding(ModbusMaster *_Master,
//                                           uint8_t _ID,
//                                           uint16_t _Addr,
//                                           uint16_t _Buf,
//                                           uint32_t _Timeout)
// {
//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       WRITE_SINGLE_REGISTER,
//                                       _Addr,
//                                       _Buf);
// }

// /**
//  * @brief 写多个保持寄存器的值。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 保持寄存器的起始地址。
//  * @param _pBuf 指向要写入的数据缓冲区。
//  * @param _Len 要写入的寄存器数量。
//  * @return Status 返回写入过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_write_multiple_holdings(ModbusMaster *_Master,
//                                              uint8_t _ID,
//                                              uint16_t _Addr,
//                                              uint16_t *_pBuf,
//                                              uint32_t _Len,
//                                              uint32_t _Timeout)
// {
//     uint8_t Buf[9 + (_Len << 1)];
//     Buf[0] = _ID;
//     Buf[1] = WRITE_MULTIPLE_REGISTERS;
//     Buf[2] = HIGH_BYTE(_Addr);
//     Buf[3] = LOW_BYTE(_Addr);
//     Buf[4] = HIGH_BYTE(_Len);
//     Buf[5] = LOW_BYTE(_Len);
//     Buf[6] = (_Len << 1);
//     for (size_t i = 0; i < _Len; i++)
//     {
//         Buf[7 + (i << 1)] = HIGH_BYTE(_pBuf[i]);
//         Buf[8 + (i << 1)] = LOW_BYTE(_pBuf[i]);
//     }

//     SendData(_Master, Buf, 7 + (_Len << 1));
//     return BF_OK;
// }

// /**
//  * @brief 读取输入寄存器的值。
//  *
//  * @param _Master 指向 ModbusMaster 结构的指针。
//  * @param _ID 从站地址。
//  * @param _Addr 输入寄存器的起始地址。
//  * @param _pBuf 指向存储读取数据的缓冲区。
//  * @param _Len 要读取的寄存器数量。
//  * @return Status 返回读取过程的状态，BF_OK 表示成功，其他值表示失败。
//  */
// Status modbus_master_read_input(ModbusMaster *_Master,
//                                 uint8_t _ID,
//                                 uint16_t _Addr,
//                                 uint16_t *_pBuf,
//                                 uint32_t _Len,
//                                 uint32_t _Timeout)
// {
//     return modbus_master_send_request(_Master,
//                                       _ID,
//                                       READ_INPUT_REGISTERS,
//                                       _Addr,
//                                       _Len);
// }