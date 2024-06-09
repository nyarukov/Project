/*
 * 项目名称: modbus_slave
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: MODBUS从机协议
 */

#include "modbus_slave.h"

// C 文件内容...

// clang-format off
#define Modmalloc(type, size)               (type *)malloc(sizeof(type) * size);
#define Modfree(prt)                        free(prt)

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

static uint16_t Addr;
static uint32_t Count;
static uint32_t Len;

/**
 * @brief 初始化Modbus从站结构。
 *
 * @param _Slave 指向要初始化的 ModbusSlave 结构的指针。
 * @param _IDx 通信端口号
 * @param _addr 从设备的地址。
 * @param SendData 串口发送函数。
 * @param _holding_size 保持寄存器数组的大小。
 * @param _input_size 输入寄存器数组的大小。
 * @param _coils_size 线圈数组的大小。
 * @param _discrete_size 离散输入数组的大小。
 * @return Status 指示初始化过程成功或失败的状态。
 */
Status init_modbus_slave(ModbusSlave *_Slave,
                         COM_ID _IDx,
                         uint8_t _addr,
                         Status (*SendData)(COM_ID _Id,
                                            uint8_t *_pBuf,
                                            uint32_t _Len),
                         size_t _holding_size,
                         size_t _input_size,
                         size_t _coils_size,
                         size_t _discrete_size)
{

    if (!_Slave)
        return BF_NULL_POINTER;
    _Slave->Registers._Coils_ptr =
        Modmalloc(uint8_t, _coils_size);

    if (_Slave->Registers._Coils_ptr == BF_NULL)
    {
        Modfree(_Slave->Registers._Coils_ptr);
        return BF_NULL_POINTER;
    }
    _Slave->Registers._DiscreteInputs_ptr =
        Modmalloc(uint8_t, _discrete_size);
    if (_Slave->Registers._DiscreteInputs_ptr == BF_NULL)
    {
        Modfree(_Slave->Registers._Coils_ptr);
        Modfree(_Slave->Registers._DiscreteInputs_ptr);
        return BF_NULL_POINTER;
    }
    _Slave->Registers._HoldingRegisters_ptr =
        Modmalloc(uint16_t, _holding_size);
    if (_Slave->Registers._HoldingRegisters_ptr == BF_NULL)
    {
        Modfree(_Slave->Registers._Coils_ptr);
        Modfree(_Slave->Registers._DiscreteInputs_ptr);
        Modfree(_Slave->Registers._HoldingRegisters_ptr);
        return BF_NULL_POINTER;
    }
    _Slave->Registers._InputRegisters_ptr =
        Modmalloc(uint16_t, _input_size);
    if (_Slave->Registers._InputRegisters_ptr == BF_NULL)
    {
        Modfree(_Slave->Registers._Coils_ptr);
        Modfree(_Slave->Registers._DiscreteInputs_ptr);
        Modfree(_Slave->Registers._HoldingRegisters_ptr);
        Modfree(_Slave->Registers._InputRegisters_ptr);

        return BF_NULL_POINTER;
    }

    mem_set(_Slave->Registers._Coils_ptr, 0, _coils_size);
    mem_set(_Slave->Registers._DiscreteInputs_ptr, 0, _discrete_size);
    mem_set(_Slave->Registers._HoldingRegisters_ptr, 0, _holding_size);
    mem_set(_Slave->Registers._InputRegisters_ptr, 0, _input_size);

    _Slave->Control.Com = _IDx;
    _Slave->Control.Addr = _addr;
    _Slave->Control.Status |= BF_INTI;

    _Slave->Control.SendData = SendData;
    _Slave->Registers._HoldingRegisters_size = _holding_size;
    _Slave->Registers._InputRegisters_size = _input_size;
    _Slave->Registers._Coils_size = _coils_size;
    _Slave->Registers._DiscreteInputs_size = _discrete_size;

    return BF_OK;
}

Status free_modbus_slave(ModbusSlave *_Slave)
{
    if (!_Slave)
        return BF_NULL_POINTER;

    Modfree(_Slave->Registers._HoldingRegisters_ptr);
    Modfree(_Slave->Registers._InputRegisters_ptr);
    Modfree(_Slave->Registers._Coils_ptr);
    Modfree(_Slave->Registers._DiscreteInputs_ptr);
    return BF_OK;
}

static void Error(ModbusSlave *_Slave,
                  uint8_t _Code,
                  uint8_t _ErrorCode)
{
    uint8_t Buf[5];

    Buf[0] = _Slave->Control.Addr; // Modbus 设备地址
    Buf[1] = 0x80 | _Code;         // 功能码的响应码
    Buf[2] = _ErrorCode;           // 异常码

    uint16_t _CRC = Check_Modbus_CRC16(Buf, 3); // 计算 CRC 校验值
    Buf[3] = LOW_BYTE(_CRC);                    // CRC 校验值高位
    Buf[4] = HIGH_BYTE(_CRC);                   // CRC 校验值低位

    _Slave->Control.SendData(_Slave->Control.Com, Buf, 5); // 发送异常响应数据
}

static void SendData(ModbusSlave *_Slave,
                     uint8_t *_pBuf,
                     uint32_t _Len)
{
    uint16_t _CRC = Check_Modbus_CRC16(_pBuf, _Len);

    _pBuf[_Len] = LOW_BYTE(_CRC);
    _pBuf[_Len + 1] = HIGH_BYTE(_CRC);

    _Slave->Control.SendData(_Slave->Control.Com, _pBuf, _Len + 2);
}

static Status read_coil_status(ModbusSlave *_Slave)
{
    Len = BYTE_COUNT(Count);

    uint8_t *Buf = Modmalloc(uint8_t, Len + 5);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = READ_COILS;
    Buf[2] = Len;

    mem_cpy(&Buf[3], &_Slave->Registers._Coils_ptr[Addr], Len);

    SendData(_Slave, Buf, 3 + Len);

    Modfree(Buf);
    return BF_OK;
}

static Status read_discrete_input_status(ModbusSlave *_Slave)
{
    Len = BYTE_COUNT(Count);

    uint8_t *Buf = Modmalloc(uint8_t, Len + 5);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = READ_DISCRETE_INPUTS;
    Buf[2] = Len;

    mem_cpy(&Buf[3], &_Slave->Registers._DiscreteInputs_ptr[Addr], Len);

    SendData(_Slave, Buf, 3 + Len);

    Modfree(Buf);
    return BF_OK;
}

static Status read_holding_register(ModbusSlave *_Slave)
{
    Len = Count << 1;

    uint8_t *Buf = Modmalloc(uint8_t, Len + 5);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = READ_HOLDING_REGISTERS;
    Buf[2] = Len;

    mem_cpy(&Buf[3], &_Slave->Registers._HoldingRegisters_ptr[Addr], Len);

    SendData(_Slave, Buf, 3 + Len);

    Modfree(Buf);
    return BF_OK;
}

static Status read_input_register(ModbusSlave *_Slave)
{
    Len = Count << 1;

    uint8_t *Buf = Modmalloc(uint8_t, Len + 5);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = READ_INPUT_REGISTERS;
    Buf[2] = Len;

    mem_cpy(&Buf[3], &_Slave->Registers._InputRegisters_ptr[Addr], Len);

    SendData(_Slave, Buf, 3 + Len);

    Modfree(Buf);
    return BF_OK;
}

static Status write_single_output_coil(ModbusSlave *_Slave,
                                       uint8_t *_pBuf)
{

    if (_pBuf[0] & 0x01)
    {
        _Slave->Registers._Coils_ptr[Addr >> 3] |= (1 << (Addr % 8));
    }
    else
    {
        _Slave->Registers._Coils_ptr[Addr >> 3] &= ~(1 << (Addr % 8));
    }

    uint8_t *Buf = Modmalloc(uint8_t, 6);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = WRITE_SINGLE_COIL;
    Buf[2] = HIGH_BYTE(Addr);
    Buf[3] = LOW_BYTE(Addr);
    Buf[4] = (_Slave->Registers._Coils_ptr[Addr >> 3] & (1 << (Addr % 8))) ? 0xFF : 0x00;
    Buf[5] = 0;

    SendData(_Slave, Buf, 6);

    Modfree(Buf);
    return BF_OK;
}

#if 0
static Status write_multiple_output_coils(ModbusSlave *_Slave,
 {                                         uint8_t *_pBuf)

    //  0  1  2  3  4  5  6  7  8
    // 01 0F 00 00 00 0F 02 0F 0F
    // 01 0F 00 0A 00 01 01 01

    uint8_t _ByteSize = _pBuf[0];

    uint8_t _AddrGroup = Addr >> 3;
    uint8_t _Addrbits = Addr % 8;

    uint8_t _ValGroup = Count >> 3;
    uint8_t _Val_Bits = Count % 8;

    _LOG("_AddrGroup[%d]\t _Addrbits[%d]\r\n", _AddrGroup, _Addrbits);
    _LOG("_ValGroup[%d]\t _Val_Bits[%d]\r\n", _ValGroup, _Val_Bits);

    if ((_Addrbits == BF_NULL) && (_Val_Bits == BF_NULL))
    {
        mem_cpy(&_Slave->Registers._Coils_ptr[_AddrGroup], &_pBuf[1], _ByteSize);
    }
    else
    {
        for (size_t i = 0; i < _ValGroup; i++)
        {
            _Slave->Registers._Coils_ptr[Addr + i] &= ~0xFF;
            _Slave->Registers._Coils_ptr[Addr + i] = _pBuf[1 + i];
        }

        // 非零偏移量需要逐位处理
        for (size_t i = 0; i < _Val_Bits; i++)
        {
            uint8_t bit_pos = (_Addrbits + i) % 8;               // 当前位在字节中的位置
            uint8_t byte_pos = _AddrGroup + (_Addrbits + i) / 8; // 当前字节的位置

            // 清除当前位
            _Slave->Registers._Coils_ptr[byte_pos] &= ~(1 << bit_pos);
            // 设置当前位
            _Slave->Registers._Coils_ptr[byte_pos] |= ((_pBuf[1 + _ValGroup] >> i) & 0x01) << bit_pos;

            _LOG("[%d]\t", (_pBuf[_ValGroup] >> i) & 0x01);
        }
        _LOG("\r\n");
    }

    uint8_t *Buf = Modmalloc(uint8_t, 6);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = WRITE_MULTIPLE_COILS;

    Buf[2] = HIGH_BYTE(Addr);
    Buf[3] = LOW_BYTE(Addr);
    Buf[4] = HIGH_BYTE(Count);
    Buf[5] = LOW_BYTE(Count);

    SendData(_Slave, Buf, 6);

    Modfree(Buf);

return BF_OK;
}
#endif
static Status write_single_holding_register(ModbusSlave *_Slave,
                                            uint8_t *_pBuf)
{
    Len = Count << 1;

    uint8_t *Buf = Modmalloc(uint8_t, 6);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    Buf[0] = _Slave->Control.Addr;
    Buf[1] = WRITE_SINGLE_REGISTER;
    Buf[2] = HIGH_BYTE(Addr);
    Buf[3] = LOW_BYTE(Addr);
    Buf[4] = _pBuf[0];
    Buf[5] = _pBuf[1];

    _Slave->Registers._HoldingRegisters_ptr[Addr] =
        BEBufToUint16(_pBuf[0], _pBuf[1]);

    SendData(_Slave, Buf, 6);

    Modfree(Buf);
    return BF_OK;
}

static Status wrtie_multiple_holding_registers(ModbusSlave *_Slave,
                                               uint8_t *_pBuf)
{
    Len = Count << 1;

    uint8_t *Buf = Modmalloc(uint8_t, 6);
    if (Buf == BF_NULL)
    {
        return BF_NULL_POINTER;
    }

    mem_cpy((uint8_t *)&_Slave->Registers._HoldingRegisters_ptr[Addr],
            &_pBuf[0], Len);

    SendData(_Slave, Buf, 6);

    Modfree(Buf);
    return BF_OK;
}

Status Modbus_Slave_Proc(ModbusSlave *_Slave,
                         uint8_t *_pBuf,
                         uint32_t _Len)
{
    if (!_Slave)
        return BF_NULL_POINTER;
    if (_pBuf[0] != _Slave->Control.Addr)
        return BF_ADDR_ERROR;

    if (LEBufToUint16(_pBuf[_Len - 1], _pBuf[_Len - 2]) !=
        Check_Modbus_CRC16(_pBuf, _Len - 2))
        return BF_CRC_ERROR;

    Addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    switch (_pBuf[1])
    {
    case READ_COILS:

        if (Count > _Slave->Registers._Coils_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return read_coil_status(_Slave);

    case READ_DISCRETE_INPUTS:

        if (Count > _Slave->Registers._DiscreteInputs_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return read_discrete_input_status(_Slave);

    case READ_HOLDING_REGISTERS:

        if (Count > _Slave->Registers._HoldingRegisters_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return read_holding_register(_Slave);

    case READ_INPUT_REGISTERS:

        if (Count > _Slave->Registers._InputRegisters_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return read_input_register(_Slave);

    case WRITE_SINGLE_COIL:

        if (Addr > _Slave->Registers._Coils_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }

        return write_single_output_coil(_Slave, &_pBuf[4]);
#if 0
    case WRITE_MULTIPLE_COILS:
        if ((Addr > _Slave->Registers._Coils_size) ||
            ((Addr + _pBuf[6]) > _Slave->Registers._Coils_size))
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }

        return write_multiple_output_coils(_Slave, &_pBuf[6]);
#endif
    case WRITE_SINGLE_REGISTER:

        if (Addr > _Slave->Registers._HoldingRegisters_size)
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return write_single_holding_register(_Slave, &_pBuf[4]);

    case WRITE_MULTIPLE_REGISTERS:

        if ((Count > _Slave->Registers._HoldingRegisters_size) ||
            ((Addr + Count) > _Slave->Registers._Coils_size))
        {
            Error(_Slave, _pBuf[1], ILLEGAL_DATA_ADDRESS);
            return BF_TOO_LARGE;
        }
        return wrtie_multiple_holding_registers(_Slave, &_pBuf[7]);

    default:
        Error(_Slave, _pBuf[1], ILLEGAL_FUNCTION);
        return BF_ERROR;
    }
}

/**
 * @brief 写入线圈寄存器
 *
 * 此函数将指定的字节缓冲区内容写入到 Modbus 从机的线圈寄存器中。
 *
 * @param _Slave 指向 Modbus 从机结构体的指针
 * @param _Addr 起始地址
 * @param _pBuf 指向要写入的数据缓冲区的指针
 * @param _Len 要写入的字节数
 * @return Status 返回操作状态
 *         - BF_OK: 操作成功
 *         - BF_NULL_POINTER: 空指针错误
 *         - BF_INVALID_PARAM: 参数无效
 */
Status Modbus_Slave_Write_Coil(ModbusSlave *_Slave,
                               uint16_t _Addr,
                               uint8_t *_pBuf,
                               uint32_t _Len)
{
    if (!_Slave)
    {
        return BF_NULL_POINTER;
    }
    else if (_Addr >= _Slave->Registers._Coils_size ||
             (_Addr + _Len) > _Slave->Registers._Coils_size)
    {
        return BF_INVALID_PARAM;
    }
    else
    {
        memcpy(&_Slave->Registers._Coils_ptr[_Addr], _pBuf, _Len);
        return BF_OK;
    }
}

/**
 * @brief 写入离散输入寄存器
 *
 * 此函数将指定的字节缓冲区内容写入到 Modbus 从机的离散输入寄存器中。
 *
 * @param _Slave 指向 Modbus 从机结构体的指针
 * @param _Addr 起始地址
 * @param _pBuf 指向要写入的数据缓冲区的指针
 * @param _Len 要写入的字节数
 * @return Status 返回操作状态
 *         - BF_OK: 操作成功
 *         - BF_NULL_POINTER: 空指针错误
 *         - BF_INVALID_PARAM: 参数无效
 */
Status Modbus_Slave_Write_Discrete(ModbusSlave *_Slave,
                                   uint16_t _Addr,
                                   uint8_t *_pBuf,
                                   uint32_t _Len)
{
    if (!_Slave)
    {
        return BF_NULL_POINTER;
    }
    else if (_Addr >= _Slave->Registers._DiscreteInputs_size ||
             (_Addr + _Len) > _Slave->Registers._DiscreteInputs_size)
    {
        return BF_INVALID_PARAM;
    }
    else
    {
        mem_cpy(&_Slave->Registers._DiscreteInputs_ptr[_Addr],
                _pBuf, _Len);
        return BF_OK;
    }
}

/**
 * @brief 写入保持寄存器
 *
 * 此函数将指定的缓冲区内容写入到 Modbus 从机的保持寄存器中。
 *
 * @param _Slave 指向 Modbus 从机结构体的指针
 * @param _Addr 起始地址
 * @param _pBuf 指向要写入的数据缓冲区的指针
 * @param _Len 要写入的数据项数
 * @return Status 返回操作状态
 *         - BF_OK: 操作成功
 *         - BF_NULL_POINTER: 空指针错误
 *         - BF_INVALID_PARAM: 参数无效
 */
Status Modbus_Slave_Write_Holding(ModbusSlave *_Slave,
                                  uint16_t _Addr,
                                  uint16_t *_pBuf,
                                  uint32_t _Len)
{
    if (!_Slave)
    {
        return BF_NULL_POINTER;
    }
    else if (_Addr >= _Slave->Registers._HoldingRegisters_size ||
             (_Addr + _Len) > _Slave->Registers._HoldingRegisters_size)
    {
        return BF_INVALID_PARAM;
    }
    else
    {
        mem_cpy(&_Slave->Registers._HoldingRegisters_ptr[_Addr],
                _pBuf, _Len);
        return BF_OK;
    }
}

/**
 * @brief 写入输入寄存器
 *
 * 此函数将指定的缓冲区内容写入到 Modbus 从机的输入寄存器中。
 *
 * @param _Slave 指向 Modbus 从机结构体的指针
 * @param _Addr 起始地址
 * @param _pBuf 指向要写入的数据缓冲区的指针
 * @param _Len 要写入的数据项数
 * @return Status 返回操作状态
 *         - BF_OK: 操作成功
 *         - BF_NULL_POINTER: 空指针错误
 *         - BF_INVALID_PARAM: 参数无效
 */
Status Modbus_Slave_Write_Input(ModbusSlave *_Slave,
                                uint16_t _Addr,
                                uint16_t *_pBuf,
                                uint32_t _Len)
{
    if (!_Slave)
    {
        return BF_NULL_POINTER;
    }
    else if (_Addr >= _Slave->Registers._InputRegisters_size ||
             (_Addr + _Len) > _Slave->Registers._InputRegisters_size)
    {
        return BF_INVALID_PARAM;
    }
    else
    {
        mem_cpy(&_Slave->Registers._InputRegisters_ptr[_Addr],
                _pBuf, _Len);
        return BF_OK;
    }
}