/*
 * 项目名称: buffer
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:48:39
 * 描述: 缓冲区
 */

#include "buffer.h"

// C 文件内容...

/**
 * @brief 初始化缓冲区
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 缓冲区数据的起始地址
 * @param _Size 缓冲区的大小
 * @return Status 返回初始化状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Config(Buffer_t *_pBuf, void *_Data, uint32_t _Size)
{
    if (!_pBuf || !_Data)
    {
        return BF_NULL_POINTER;
    }
    _pBuf->Buf = _Data;
    _pBuf->BufSize = _Size;
    _pBuf->Count = 0;
    _pBuf->Write = 0;
    _pBuf->Read = 0;
    return BF_SUCCESS;
}

/**
 * @brief 以位为单位向缓存区写入数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 要写入的数据的起始地址
 * @param _Len 要写入的数据长度（以位为单位）
 * @return Status 返回写入操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Write_Bit(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    if (_Len + _pBuf->Count > _pBuf->BufSize)
    {
        return BF_FULL;
    }
    uint32_t index;
    uint8_t *uCharVal = (uint8_t *)_Data;
    for (index = 0; index < _Len; index++)
    {
        _pBuf->Buf[(_pBuf->Write + index) % _pBuf->BufSize] = ((*uCharVal) >> (index % 8)) & 0x01;
        if (!((index + 1) % 8))
        {
            uCharVal++;
        }
    }
    _pBuf->Write = (_pBuf->Write + _Len) % _pBuf->BufSize;
    _pBuf->Count += _Len;
    return BF_SUCCESS;
}

/**
 * @brief 以位为单位从缓存区读取数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 存放读取数据的地址
 * @param _Len 要读取的数据长度（以位为单位）
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Read_Bit(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    _Len = (_Len >= 8) ? (_Len >> 3) : 1;
    if (_Len > _pBuf->Count)
    {
        return BF_EMPTY;
    }
    uint32_t index, i;
    uint8_t *uCharVal;
    for (index = 0; index < _Len; index++)
    {
        uCharVal = &_pBuf->Buf[(_pBuf->Read + index) % _pBuf->BufSize];
        for (i = 0; i < 8; i++)
        {
            *((uint8_t *)_Data + (index << 3) + i) = ((*uCharVal) >> i) & 0x01;
        }
    }
    _pBuf->Read = (_pBuf->Read + _Len) % _pBuf->BufSize;
    _pBuf->Count -= _Len;
    return BF_SUCCESS;
}

// 以字节为单位向缓存区写入数据
/**
 * @brief 以字节为单位向缓存区写入数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 要写入的数据的起始地址
 * @param _Len 要写入的数据长度（以字节为单位）
 * @return Status 返回写入操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Write_Byte(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    if (_Len + _pBuf->Count > _pBuf->BufSize)
    {
        return BF_FULL;
    }
    uint32_t index;
    for (index = 0; index < _Len; index++)
    {
        _pBuf->Buf[(_pBuf->Write + index) % _pBuf->BufSize] = *((uint8_t *)_Data + index);
    }
    _pBuf->Write = (_pBuf->Write + _Len) % _pBuf->BufSize;
    _pBuf->Count += _Len;
    return BF_SUCCESS;
}

/**
 * @brief 以字节为单位从缓存区读取数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 存放读取数据的地址
 * @param _Len 要读取的数据长度（以字节为单位）
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Read_Byte(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    if (_Len > _pBuf->Count)
    {
        return BF_EMPTY;
    }
    uint32_t index;
    for (index = 0; index < _Len; index++)
    {
        *((uint8_t *)_Data + index) = _pBuf->Buf[(_pBuf->Read + index) % _pBuf->BufSize];
    }
    _pBuf->Read = (_pBuf->Read + _Len) % _pBuf->BufSize;
    _pBuf->Count -= _Len;
    return BF_SUCCESS;
}

// 以短整型为单位向缓存区写入数据
/**
 * @brief 以短整型为单位向缓存区写入数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 要写入的数据的起始地址
 * @param _Len 要写入的数据长度（以短整型为单位）
 * @return Status 返回写入操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Write_Short(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 1;
    if (len + _pBuf->Count > _pBuf->BufSize)
    {
        return BF_FULL;
    }
    uint32_t index;
    uint16_t *uShortVal;
    for (index = 0; index < _Len; index++)
    {
        uShortVal = (uint16_t *)_Data + index;
        _pBuf->Buf[(_pBuf->Write + (index << 1)) % _pBuf->BufSize] = ((*uShortVal) >> 8) & 0x00FF;
        _pBuf->Buf[(_pBuf->Write + (index << 1) + 1) % _pBuf->BufSize] = (*uShortVal) & 0x00FF;
    }
    _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
    _pBuf->Count += len;
    return BF_SUCCESS;
}

/**
 * @brief 以短整型为单位从缓存区读取数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 存放读取数据的地址
 * @param _Len 要读取的数据长度（以短整型为单位）
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Read_Short(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 1;
    if (len > _pBuf->Count)
    {
        return BF_EMPTY;
    }
    uint32_t index;
    for (index = 0; index < _Len; index++)
    {
        *((uint16_t *)_Data + index) = (_pBuf->Buf[(_pBuf->Read + (index << 1)) % _pBuf->BufSize] << 8) |
                                       _pBuf->Buf[(_pBuf->Read + (index << 1) + 1) % _pBuf->BufSize];
    }
    _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
    _pBuf->Count -= len;
    return BF_SUCCESS;
}

/**
 * @brief 以整型为单位向缓存区写入数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 要写入的数据的起始地址
 * @param _Len 要写入的数据长度（以整型为单位）
 * @return Status 返回写入操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Write_Int(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 2;
    if (len + _pBuf->Count > _pBuf->BufSize)
    {
        return BF_FULL;
    }
    uint32_t index, i;
    uint32_t *uIntVal;
    for (index = 0; index < _Len; index++)
    {
        uIntVal = ((uint32_t *)_Data + index);
        for (i = 0; i < 4; i++)
        {
            _pBuf->Buf[(_pBuf->Write + (index << 2) + i) % _pBuf->BufSize] = (*uIntVal) >> (24 - (i << 3));
        }
    }
    _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
    _pBuf->Count += len;
    return BF_SUCCESS;
}

/**
 * @brief 以整型为单位从缓存区读取数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 存放读取数据的地址
 * @param _Len 要读取的数据长度（以整型为单位）
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Read_Int(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 2;
    if (len > _pBuf->Count)
    {
        return BF_EMPTY;
    }
    uint32_t index, i;
    uint32_t *uIntVal = (uint32_t *)malloc(_Len * sizeof(uint32_t));
    if (!uIntVal)
    {
        return BF_NULL_POINTER;
    }
    for (index = 0; index < _Len; index++)
    {
        uIntVal[index] = 0;
        for (i = 0; i < 4; i++)
        {
            uIntVal[index] |= _pBuf->Buf[(_pBuf->Read + (index << 2) + i) % _pBuf->BufSize] << (24 - (i << 3));
        }
    }
    memcpy(_Data, uIntVal, _Len * sizeof(uint32_t));
    free(uIntVal);
    _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
    _pBuf->Count -= len;
    return BF_SUCCESS;
}

/**
 * @brief 以长整型为单位向缓存区写入数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 要写入的数据的起始地址
 * @param _Len 要写入的数据长度（以长整型为单位）
 * @return Status 返回写入操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Write_Long(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 3;
    if (len + _pBuf->Count > _pBuf->BufSize)
    {
        return BF_FULL;
    }
    uint32_t index, i;
    uint64_t *uLongVal;
    for (index = 0; index < _Len; index++)
    {
        uLongVal = ((uint64_t *)_Data + index);
        for (i = 0; i < 8; i++)
        {
            _pBuf->Buf[(_pBuf->Write + (index << 3) + i) % _pBuf->BufSize] = (*uLongVal) >> (56 - (i << 3));
        }
    }
    _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
    _pBuf->Count += len;
    return BF_SUCCESS;
}

/**
 * @brief 以长整型为单位从缓存区读取数据
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Data 存放读取数据的地址
 * @param _Len 要读取的数据长度（以长整型为单位）
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Read_Long(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    uint32_t len = _Len << 3;
    if (len > _pBuf->Count)
    {
        return BF_EMPTY;
    }
    uint32_t index, i;
    uint64_t *uLongVal = (uint64_t *)malloc(_Len * sizeof(uint64_t));
    if (!uLongVal)
    {
        return BF_NULL_POINTER;
    }
    for (index = 0; index < _Len; index++)
    {
        uLongVal[index] = 0;
        for (i = 0; i < 8; i++)
        {
            uLongVal[index] |= (uint64_t)(_pBuf->Buf[(_pBuf->Read + (index << 3) + i) % _pBuf->BufSize]) << (56 - (i << 3));
        }
    }
    memcpy(_Data, uLongVal, _Len * sizeof(uint64_t));
    free(uLongVal);
    _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
    _pBuf->Count -= len;
    return BF_SUCCESS;
}

/**
 * @brief 设置缓存区大小
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Size 要设置的缓存区大小
 * @return Status 返回设置操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Set_Size(Buffer_t *_pBuf, uint32_t _Size)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    _pBuf->BufSize = _Size;
    return BF_SUCCESS;
}

/**
 * @brief 设置缓存区地址
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Addr 要设置的缓存区地址
 * @return Status 返回设置操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Set_Address(Buffer_t *_pBuf, void *_Addr)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    _pBuf->Buf = (uint8_t *)_Addr;
    return BF_SUCCESS;
}

/**
 * @brief 清空缓存区
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Value 清空后缓存区的填充值
 * @return Status 返回清空操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Clear(Buffer_t *_pBuf, uint8_t _Value)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }
    _pBuf->Count = 0;
    _pBuf->Read = 0;
    _pBuf->Write = 0;
    for (uint32_t i = 0; i < _pBuf->BufSize; i++)
    {
        _pBuf->Buf[i] = _Value;
    }
    return BF_SUCCESS;
}

/**
 * @brief 获取缓存区的总大小
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Size 用于存放缓存区大小的地址
 * @return Status 返回获取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Get_Total_Size(Buffer_t *_pBuf, uint32_t *_Size)
{
    if (!_pBuf || !_Size)
    {
        return BF_NULL_POINTER;
    }
    *_Size = _pBuf->BufSize;
    return BF_SUCCESS;
}

/**
 * @brief 获取缓存区的读指针位置
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Pointer 存放读指针位置的地址
 * @return Status 返回获取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Get_Read_Pointer(Buffer_t *_pBuf, uint32_t *_Pointer)
{
    if (!_pBuf || !_Pointer)
    {
        return BF_NULL_POINTER;
    }
    *_Pointer = _pBuf->Read;
    return BF_SUCCESS;
}

/**
 * @brief 获取缓存区的写指针位置
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Pointer 存放写指针位置的地址
 * @return Status 返回获取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Get_Write_Pointer(Buffer_t *_pBuf, uint32_t *_Pointer)
{
    if (!_pBuf || !_Pointer)
    {
        return BF_NULL_POINTER;
    }
    *_Pointer = _pBuf->Write;
    return BF_SUCCESS;
}

/**
 * @brief 读取缓存区剩余空间
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _SpaceLeft 存放剩余空间大小的地址
 * @return Status 返回读取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Get_Space_Left(Buffer_t *_pBuf, uint32_t *_SpaceLeft)
{
    if (!_pBuf || !_SpaceLeft)
    {
        return BF_NULL_POINTER;
    }
    if (_pBuf->Write > _pBuf->Read)
    {
        *_SpaceLeft = _pBuf->BufSize - (_pBuf->Write - _pBuf->Read);
    }
    else if (_pBuf->Write < _pBuf->Read)
    {
        *_SpaceLeft = _pBuf->BufSize - (_pBuf->Read - _pBuf->Write);
    }
    else
    {
        if (_pBuf->Count == 0)
        {
            *_SpaceLeft = _pBuf->BufSize;
        }
        else
        {
            return BF_FULL;
        }
    }
    return BF_SUCCESS;
}

/**
 * @brief 获取已写入数据的计数
 *
 * @param _pBuf 指向缓冲区结构体的指针
 * @param _Count 存放已写入数据计数的地址
 * @return Status 返回获取操作的状态，BF_SUCCESS表示成功，其他表示失败
 */
Status Buffer_Get_Written_Count(Buffer_t *_pBuf, uint32_t *_Count)
{
    if (!_pBuf || !_Count)
    {
        return BF_NULL_POINTER;
    }
    *_Count = _pBuf->Count;
    return BF_SUCCESS;
}

/**
 * @brief 对环形缓存区执行各种操作。
 *
 * 此函数允许执行诸如向缓存区写入、从缓存区读取、清除和查询等操作。
 *
 * @param _pBuf 指向环形缓存区结构体的指针。
 * @param _Data 指向要从缓存区读取或写入的数据的指针。
 * @param _Len 要处理的数据长度。
 * @param _Cmd 表示要在缓存区上执行的操作的命令。可以使用以下预定义的命令：
 *   - BUFFER_WRITE_BIT: 			以位为单位向缓存区写入数据。
 *   - BUFFER_READ_BIT: 			以位为单位从缓存区读取数据。
 *   - BUFFER_WRITE_BYTE: 			以字节为单位向缓存区写入数据。
 *   - BUFFER_READ_BYTE: 			以字节为单位从缓存区读取数据。
 *   - BUFFER_WRITE_SHORT: 			以短整型为单位向缓存区写入数据。
 *   - BUFFER_READ_SHORT: 			以短整型为单位从缓存区读取数据。
 *   - BUFFER_WRITE_INT: 			以整型为单位向缓存区写入数据。
 *   - BUFFER_READ_INT: 			以整型为单位从缓存区读取数据。
 *   - BUFFER_WRITE_LONG: 			以长整型为单位向缓存区写入数据。
 *   - BUFFER_LONG_REA: 			以长整型为单位从缓存区读取数据。
 *
 *   - BUFFER_SET_SIZE:					设置缓存区的大小
 * 	 - BUFFER_SET_ADDRESS:				设置缓存区的起始地址。
 *
 *   - BUFFER_CLEAR: 				清空缓存区。
 *   - BUFFER_TOTAL_SIZE: 			获取缓存区的总大小。
 *   - BUFFER_READ_POINTER: 		获取缓存区的读指针位置。
 *   - BUFFER_WRITE_POINTER: 		获取缓存区的写指针位置。
 *   - BUFFER_SPACE_LEFT:		 	获取缓存区中剩余空间的大小。
 *   - BUFFER_WRITTEN_COUNT         获取已经写入到缓存区的数据的数量，单位字节
 * @param _Para 用于某些命令的附加参数。具体用法如下：
 *   - 当 `_Cmd` 为 `BUFFER_CLEAR` 时，`_Para` 用于设置清除缓存区的值。
 *   - 当 `_Cmd` 为 `BUFFER_TOTAL_SIZE` 时，`_Para` 用于存储缓存区的总大小。
 *   - 当 `_Cmd` 为 `BUFFER_READ_POINTER` 时，`_Para` 用于存储缓存区的读指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_WRITE_POINTER` 时，`_Para` 用于存储缓存区的写指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_SPACE_LEFT` 时，`_Para` 用于存储缓存区中剩余空间的大小。
 *   - 当 `_Cmd` 为 `BUFFER_SPACE_LEFT` 时，`_Para` 用于存储缓存区中入到缓存区的数据的数量。
 * @return 操作的状态。
 *   - OK：操作成功完成。
 *   - NULL_POINTER：输入时传递了空指针。
 *   - FULL：缓存区已满，无法执行操作。
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。
 */

Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para)
{
    if (!_pBuf)
    {
        return BF_NULL_POINTER;
    }

    switch (_Cmd)
    {
    case BUFFER_WRITE_BIT: // 缓存区以位写入

        return Buffer_Write_Bit(_pBuf, _Data, _Len);

    case BUFFER_READ_BIT: // 缓存区以位读取

        return Buffer_Read_Bit(_pBuf, _Data, _Len);

    case BUFFER_WRITE_BYTE: // 缓存区以字节写入

        return Buffer_Write_Byte(_pBuf, _Data, _Len);

    case BUFFER_READ_BYTE: // 缓存区以字节读取

        return Buffer_Read_Byte(_pBuf, _Data, _Len);

    case BUFFER_WRITE_SHORT: // 缓存区以短整型写入

        return Buffer_Write_Short(_pBuf, _Data, _Len);

    case BUFFER_READ_SHORT: // 缓存区以短整型读取

        return Buffer_Read_Short(_pBuf, _Data, _Len);

    case BUFFER_WRITE_INT: // 缓存区以整型写入

        return Buffer_Write_Int(_pBuf, _Data, _Len);

    case BUFFER_READ_INT: // 缓存区以整型读取

        return Buffer_Read_Int(_pBuf, _Data, _Len);

    case BUFFER_WRITE_LONG: // 缓存区以长整型写入

        return Buffer_Write_Long(_pBuf, _Data, _Len);

    case BUFFER_READ_LONG: // 缓存区以长整型读取

        return Buffer_Read_Long(_pBuf, _Data, _Len);

    case BUFFER_SET_SIZE:

        return Buffer_Set_Size(_pBuf, *_Para);

    case BUFFER_SET_ADDRESS:

        return Buffer_Set_Address(_pBuf, _Para);

    case BUFFER_CLEAR: // 清空缓存区

        return Buffer_Clear(_pBuf, (uint8_t)*_Para);

    case BUFFER_TOTAL_SIZE: // 获取缓存区的总大小。

        return Buffer_Get_Total_Size(_pBuf, _Para);

    case BUFFER_READ_POINTER: // 获取缓存区的读指针位置。

        return Buffer_Get_Read_Pointer(_pBuf, _Para);

    case BUFFER_WRITE_POINTER: // 获取缓存区的写指针位置。

        return Buffer_Get_Write_Pointer(_pBuf, _Para);

    case BUFFER_SPACE_LEFT: // 读取缓存区剩余空间

        return Buffer_Get_Space_Left(_pBuf, _Para);

    case BUFFER_WRITTEN_COUNT:

        return Buffer_Get_Written_Count(_pBuf, _Para);

    default:
        return BF_NOT_SUPPORTED;
    }
}

#if 0
Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para)
{
    if (!_pBuf)
    {
       return BF_NULL_POINTER;
    }
    uint32_t i, index, len;
    uint8_t *uCharVal;
    uint16_t *uShortVal;
    uint32_t *uIntVal;
    uint64_t *uLongVal;

    switch (_Cmd)
    {
    case BUFFER_WRITE_BIT: // 缓存区以位写入
        if (_Len + _pBuf->Count <= _pBuf->BufSize)
        {
            uCharVal = (uint8_t *)_Data;
            for (index = 0; index < _Len; index++)
            {
                _pBuf->Buf[(_pBuf->Write + index) % _pBuf->BufSize] = (((*uCharVal) >> (index % 8)) & 0x01);
                if (!((index + 1) % 8))
                {
                    uCharVal++;
                }
            }
            _pBuf->Write = (_pBuf->Write + _Len) % _pBuf->BufSize;
            _pBuf->Count += _Len;
        }
        else
        {
           return BF_FULL;
        }
        break;

    case BUFFER_READ_BIT: // 缓存区以位读取
        _Len = (_Len >= 8) ? (_Len >> 3) : 1;
        if (_Len <= _pBuf->Count)
        {
            for (index = 0; index < _Len; index++)
            {
                uCharVal = &_pBuf->Buf[(_pBuf->Read + index) % _pBuf->BufSize];
                for (i = 0; i < 8; i++)
                {
                    *((uint8_t *)_Data + (index << 3) + i) = (((*uCharVal) >> i) & 0x01);
                }
            }
            _pBuf->Read = (_pBuf->Read + _Len) % _pBuf->BufSize;
            _pBuf->Count -= _Len;
        }
        else
        {
           return BF_EMPTY;
        }
        break;

    case BUFFER_WRITE_BYTE: // 缓存区以字节写入
        if (_Len + _pBuf->Count <= _pBuf->BufSize)
        {
            for (index = 0; index < _Len; index++)
            {
                _pBuf->Buf[(_pBuf->Write + index) % _pBuf->BufSize] = *((uint8_t *)_Data + index);
            }
            _pBuf->Write = (_pBuf->Write + _Len) % _pBuf->BufSize;
            _pBuf->Count += _Len;
        }
        else
        {
           return BF_FULL;
        }
        break;

    case BUFFER_READ_BYTE: // 缓存区以字节读取
        if (_Len <= _pBuf->Count)
        {
            for (index = 0; index < _Len; index++)
            {
                *((uint8_t *)_Data + index) = _pBuf->Buf[(_pBuf->Read + index) % _pBuf->BufSize];
            }
            _pBuf->Read = (_pBuf->Read + _Len) % _pBuf->BufSize;
            _pBuf->Count -= _Len;
        }
        else
        {
           return BF_EMPTY;
        }
        break;

    case BUFFER_WRITE_SHORT: // 缓存区以短整型写入
        len = _Len << 1;
        if (len + _pBuf->Count <= _pBuf->BufSize)
        {
            for (index = 0; index < _Len; index++)
            {
                uShortVal = (uint16_t *)_Data + index;
                _pBuf->Buf[(_pBuf->Write + (index << 1)) % _pBuf->BufSize] = ((*uShortVal) >> 8) & 0x00FF;
                _pBuf->Buf[(_pBuf->Write + (index << 1) + 1) % _pBuf->BufSize] = (*uShortVal) & 0x00FF;
            }
            _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
            _pBuf->Count += len;
        }
        else
        {
           return BF_FULL;
        }
        break;

    case BUFFER_READ_SHORT: // 缓存区以短整型读取
        len = _Len << 1;
        if (len + _pBuf->Count <= _pBuf->BufSize)
        {
            for (index = 0; index < _Len; index++)
            {
                *((uint16_t *)_Data + index) = (_pBuf->Buf[(_pBuf->Read + (index << 1)) % _pBuf->BufSize] << 8) |
                                               _pBuf->Buf[(_pBuf->Read + (index << 1) + 1) % _pBuf->BufSize];
            }
            _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
            _pBuf->Count -= len;
        }
        else
        {
           return BF_EMPTY;
        }
        break;

    case BUFFER_WRITE_INT: // 缓存区以整型写入
        len = _Len << 2;
        if (len + _pBuf->Count <= _pBuf->BufSize)
        {
            for (index = 0; index < _Len; index++)
            {
                uIntVal = ((uint32_t *)_Data + index);
                for (i = 0; i < 4; i++)
                {
                    _pBuf->Buf[(_pBuf->Write + (index << 2) + i) % _pBuf->BufSize] = (*uIntVal) >> (24 - (i << 3));
                }
            }
            _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
            _pBuf->Count += len;
        }
        else
        {
           return BF_FULL;
        }
        break;

    case BUFFER_READ_INT: // 缓存区以整型读取
        len = _Len << 2;
        if (len <= _pBuf->Count)
        {
            uint32_t *uIntVal = (uint32_t *)malloc(_Len * sizeof(uint32_t));
            if (uIntVal == NULL)
            {
               return BF_NULL_POINTER;
            }
            for (index = 0; index < _Len; index++)
            {
                uIntVal[index] = 0;
                for (i = 0; i < 4; i++)
                {
                    uIntVal[index] |= _pBuf->Buf[(_pBuf->Read + (index << 2) + i) % _pBuf->BufSize] << (24 - (i << 3));
                }
            }
            memcpy(_Data, uIntVal, _Len * sizeof(uint32_t));
            free(uIntVal);

            _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
            _pBuf->Count -= len;
           return BF_SUCCESS;
        }
        else
        {
           return BF_EMPTY; // 缓存区中的数据不足
        }

    case BUFFER_WRITE_LONG: // 缓存区以长整型写入
        len = _Len << 3;
        if (len + _pBuf->Count <= _pBuf->BufSize)
        {
            for (index = 0; index < _Len; index++)
            {
                uLongVal = ((uint64_t *)_Data + index);
                for (i = 0; i < 8; i++)
                {
                    _pBuf->Buf[(_pBuf->Write + (index << 3) + i) % _pBuf->BufSize] = (*uLongVal) >> (56 - (i << 3));
                }
            }
            _pBuf->Write = (_pBuf->Write + len) % _pBuf->BufSize;
            _pBuf->Count += len;
        }
        else
        {
           return BF_FULL;
        }
        break;

    case BUFFER_READ_LONG: // 缓存区以长整型读取
        len = _Len << 3;
        if (len <= _pBuf->Count)
        {
            uLongVal = (uint64_t *)malloc(_Len * sizeof(uint64_t));
            if (!uLongVal)
            {
               return BF_NULL_POINTER;
            }
            for (index = 0; index < _Len; index++)
            {
                uLongVal[index] = 0;
                for (i = 0; i < 8; i++)
                {
                    uLongVal[index] |= (uint64_t)(_pBuf->Buf[(_pBuf->Read + (index << 3) + i) % _pBuf->BufSize]) << (56 - (i << 3));
                }
            }
            memcpy(_Data, uLongVal, _Len * sizeof(uint64_t));
            free(uLongVal);
            _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
            _pBuf->Count -= len;
        }
        else
        {
           return BF_EMPTY;
        }
        break;
    case BUFFER_SET_SIZE:
        _pBuf->BufSize = *_Para;
        break;
    case BUFFER_SET_ADDRESS:
        _pBuf->Buf = (uint8_t *)_Para;
        break;
    case BUFFER_CLEAR: // 清空缓存区
        _pBuf->Count = 0;
        _pBuf->Read = 0;
        _pBuf->Write = 0;
        for (i = 0; i < _pBuf->BufSize; i++)
        {
            _pBuf->Buf[i] = *_Para;
        }
        break;

    case BUFFER_TOTAL_SIZE: // 获取缓存区的总大小。
        *_Para = _pBuf->BufSize;
        break;

    case BUFFER_READ_POINTER: // 获取缓存区的读指针位置。
        *_Para = _pBuf->Read;
        break;

    case BUFFER_WRITE_POINTER: // 获取缓存区的写指针位置。
        *_Para = _pBuf->Write;
        break;

    case BUFFER_SPACE_LEFT: // 读取缓存区剩余空间
        if (_pBuf->Write > _pBuf->Read)
        {
            *_Para = _pBuf->BufSize - (_pBuf->Write - _pBuf->Read);
        }
        else if (_pBuf->Write < _pBuf->Read)
        {
            *_Para = _pBuf->BufSize - (_pBuf->Read - _pBuf->Write);
        }
        else
        {
            if (_pBuf->Count == 0)
            {
                *_Para = _pBuf->BufSize;
            }
            else
            {
               return BF_FULL;
            }
        }
        break;
    case BUFFER_WRITTEN_COUNT:
        *_Para = _pBuf->Count;
        break;
    default:
        // 处理未知命令
        break;
    }

   return BF_SUCCESS;
}

#endif