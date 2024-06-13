#include "bf_buffer.h"

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
   return BF_OK;
}

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
