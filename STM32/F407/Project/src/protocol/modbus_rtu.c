/*
 * 项目名称: modbus_rtu
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-10 14:04:35
 * 最后修改日期: 2024-06-10 14:04:35
 * 描述: modbus_rtu
 */

#include "modbus_rtu.h"
// C 文件内容...

// clang-format off

#define READ_COILS                          0x01    // 读取线圈状态（读取开关量输入状态）
#define READ_DISCRETE_INPUTS                0x02    // 读取输入状态（读取开关量输出状态）
#define READ_HOLDING_REGISTERS              0x03    // 读取保持寄存器（读取存储的数据）
#define READ_INPUT_REGISTERS                0x04    // 读取输入寄存器（读取存储的数据）
#define WRITE_SINGLE_COIL                   0x05    // 强制单线圈（控制开关量输出）
#define WRITE_MULTIPLE_COILS                0x0F    // 强制多单线圈（控制开关量输出）
#define WRITE_SINGLE_REGISTER               0x06    // 写单个保持寄存器（控制存储的数据）
#define WRITE_MULTIPLE_REGISTERS            0x10    // 写多个保持寄存器（控制存储的数据）

#define ILLEGAL_FUNCTION                    0x01    // 非法功能码
#define ILLEGAL_DATA_ADDRESS                0x02    // 非法数据地址
#define ILLEGAL_DATA_VALUE                  0x03    // 非法数据值
#define SLAVE_DEVICE_FAILURE                0x04    // 从机故障
#define ACKNOWLEDGE                         0x05    // 确认
#define SLAVE_DEVICE_BUSY                   0x06    // 从机忙
#define NEGATIVE_ACKNOWLEDGE                0x07    // 否定确认
#define PARITY_ERROR                        0x08    // 存储奇偶性差错
// clang-format on

/**
 * @brief 解析Modbus RTU数据帧
 *
 * 此函数用于解析接收到的Modbus RTU数据帧，提取地址、功能码和数据内容，并进行CRC校验。
 *
 * @param _pBuf 指向包含Modbus RTU数据帧的缓冲区的指针
 * @param _Len 缓冲区的长度（字节数）
 * @param _Frame 指向存储解析结果的ModbusRTUFrame结构的指针
 * @return Status 返回解析操作的状态码
 * - BF_SUCCESS：解析成功
 * - BF_TOO_SMALL：数据帧长度太小
 * - BF_CRC_ERROR：CRC校验失败
 * - BF_NULL_POINTER：内存分配失败或空指针错误
 */
Status Parse_Modbus_Rtu_Frame(uint8_t *_pBuf, uint16_t _Len,
                              ModbusRTUFrame *_Frame)
{
    Check_NULL(_pBuf);

    if (_Len < MODBUS_RTU_MIN_FRAME_SIZE)
        return BF_TOO_SMALL;

    Check_CRC(_pBuf, _Len, &_Frame->crc);

    _Frame->addr = _pBuf[0];
    _Frame->function = _pBuf[1];
    _Frame->length = _Len - 4;
    Check_NULL(_Frame->buf);

    mem_cpy(_Frame->buf, &_pBuf[2], _Frame->length);
    return BF_SUCCESS;
}

/**
 * @brief 在 Modbus RTU 通信中发送数据帧
 *
 * @param _Id 通信端口ID
 * @param _Addr 设备地址
 * @param _Function 功能码
 * @param _pBuf 待发送的数据缓冲区指针
 * @param _Len 待发送数据的长度
 * @return Status 发送操作的状态。
 * - BF_SUCCESS：发送成功
 * - BF_TOO_SMALL：数据帧长度太小
 */
Status Modbus_Rtu_SendBuf(COM_ID _Id, uint8_t _Addr,
                          uint8_t _Function, uint8_t *_pBuf,
                          uint32_t _Len)
{
    Check_NULL(_pBuf);

    if (_Len < MODBUS_RTU_MIN_FRAME_SIZE)
        return BF_TOO_SMALL;

    uint8_t buf[_Len + 4];
    buf[0] = _Addr;
    buf[1] = _Function;
    mem_cpy(&buf[2], _pBuf, _Len);

    uint16_t _Crc = Check_Modbus_CRC16(buf, _Len + 2);
    buf[2 + _Len] = LOW_BYTE(_Crc);
    buf[3 + _Len] = HIGH_BYTE(_Crc);

    return Uart_SendData(_Id, buf, _Len + 4);
}

Status jiexi_daying(COM_ID _Id)
{
    uint32_t size;
    if ((Buffer_Get_Written_Count(&COM_OF(_Id).RxBuf, &size) == BF_SUCCESS) && (size > 0))
    {
        ModbusRTUFrame frame;
        if (Parse_Modbus_Rtu_Frame(COM_OF(_Id).RxBuf.Buf, size, &frame) == BF_SUCCESS)
        {
            _LOG("解析成功:\n");
            _LOG("地址: %d\n", frame.addr);
            _LOG("功能码: %d\n", frame.function);
            _LOG("数据: ");
            for (int i = 0; i < frame.length; i++)
            {
                _LOG("%02X ", frame.buf[i]);
            }
            _LOG("\nCRC: %04X\n", frame.crc);
        }

        Buffer_Clear(&COM_OF(_Id).RxBuf, 0);
        return BF_SUCCESS;
    }
}
// 主机
Status modbus_rtu_read_coils(COM_ID _Id, uint8_t _Chx,
                             uint8_t _Addr, uint8_t _Num,
                             uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    //_LOG("超时\r\n");
    TIME_OUT(_TimeOut)
    {
        if (jiexi_daying(_Id) == BF_SUCCESS)
        {
            return BF_SUCCESS;
        }
    }
    _LOG("超时\r\n");
    return BF_TIMEOUT;
}
Status modbus_rtu_write_coil(COM_ID _Id, uint8_t _Addr,
                             uint8_t _Chx, uint8_t _Val,
                             uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    // buf[2] = HIGH_BYTE(_Num);
    // buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_coils(COM_ID _Id, uint8_t _Addr,
                              uint8_t _Chx, uint8_t _Num,
                              uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_discrete_input(COM_ID _Id, uint8_t _Chx,
                                      uint8_t _Addr, uint8_t _Num,
                                      uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_holding(COM_ID _Id, uint8_t _Chx,
                               uint8_t _Addr, uint8_t _Num,
                               uint16_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_holding(COM_ID _Id, uint8_t _Chx,
                                uint8_t _Addr, uint8_t _Num,
                                uint16_t Buf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_holdings(COM_ID _Id, uint8_t _Chx,
                                 uint8_t _Addr, uint8_t _Num,
                                 uint16_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_input(COM_ID _Id, uint8_t _Chx,
                             uint8_t _Addr, uint8_t _Num,
                             uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}

// 从机