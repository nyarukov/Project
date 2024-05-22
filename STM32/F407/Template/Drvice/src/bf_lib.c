#include "bf_lib.h"
/**
 * @brief 计算字符串长度
 *
 * @param _str 缓存区
 * @return int 个数
 */
int str_len(char *_str)
{
    int len = 0;

    while (*_str++)
        len++;
    return len;
}

/**
 * @brief 复制字符串
 *
 * @param _tar 目标缓存区
 * @param _src 源缓存区
 */
void str_cpy(char *_tar, char *_src)
{
    do
    {
        *_tar++ = *_src;
    } while (*_src++);
}

/**
 * @brief 字符串比较
 *
 * @param _s1 字符串1
 * @param _s2 字符串2
 * @return int 0 表示相等 非0表示不等
 */
int str_cmp(char *_s1, char *_s2)
{
    while ((*_s1 != 0) && (*_s2 != 0) && (*_s1 == *_s2))
    {
        _s1++;
        _s2++;
    }
    return *_s1 - *_s2;
}

/**
 * @brief 将内存块的内容设置为指定的值
 *
 * @param _ptr 要设置的内存块的指针
 * @param _value 要设置的值
 * @param _len 要设置的字节数
 */
void mem_set(void *_ptr, int _value, int _len)
{
    char *p = (char *)_ptr;
    while (_len--)
    {
        *p++ = (char)_value;
    }
}

/**
 * @brief 将一个内存块的内容复制到另一个内存块
 *
 * @param _dest 目标内存块的指针
 * @param _src 源内存块的指针
 * @param _len 要复制的字节数
 */
void mem_cpy(void *_dest, const void *_src, int _len)
{
    char *d = (char *)_dest;
    const char *s = (const char *)_src;

    while (_len--)
    {
        *d++ = *s++;
    }
}

/**
 * @brief CRC-8 校验函数
 *
 * @param buf 缓存区
 * @param len 长度
 * @return uint16_t
 */
uint16_t Check_CRC8(uint8_t *buf, uint16_t len)
{
    uint8_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= buf[i];
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x01)
            {
                crc = (crc >> 1) ^ 0x8C;
            }
            else
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}

/**
 * @brief Modbus CRC-16 校验函数
 *
 * @param data 缓存区
 * @param length 长度
 * @return uint16_t
 */
uint16_t Check_Modbus_CRC16(uint8_t *data, uint16_t length)
{
    uint16_t crc = 0xFFFF; // 初始CRC值设为0xFFFF
    for (uint16_t i = 0; i < length; i++)
    {
        crc ^= data[i]; // 与当前字节进行XOR操作
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x0001)
            {                  // 如果最低位为1
                crc >>= 1;     // 右移一位
                crc ^= 0xA001; // 与多项式0xA001进行异或
            }
            else
            {
                crc >>= 1; // 右移一位
            }
        }
    }

    return crc;
}

/**
 * @brief Xmodem CRC-16 校验函数
 *
 * @param buf 缓存区
 * @param len 长度
 * @return uint16_t
 */
uint16_t Check_Xmodeme_CRC16(uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= ((uint16_t)buf[i] << 8);
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x1021;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

/**
 * @brief Ymodem CRC-16 校验函数
 *
 * @param buf 缓存区
 * @param len 长度
 * @return uint16_t
 */
uint16_t Check_Ymodeme_CRC16(uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= (uint16_t)buf[i] << 8;
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x8408;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

Status BUffer_Config(Buffer_t *_pBuf, void *_Data, uint32_t _Size)
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
   return BF_OK;
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
                        uint32_t _Cmd,
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
        if (len <= _pBuf->Count)
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
           return BF_OK;
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

   return BF_OK;
}
