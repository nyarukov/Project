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


Status Buffer_WriteBit(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t index;
    uint8_t *uCharVal;

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
        
        return BF_OK;
    }
    else
    {
        return BF_FULL;
    }

}

Status Buffer_ReadBit(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t i, index;
    uint8_t *uCharVal;
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
        
        return BF_OK;
    }
    else
    {
        return BF_EMPTY;
    }
}


Status Buffer_WriteByte(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t index;

    if (_Len + _pBuf->Count <= _pBuf->BufSize)
    {
        for (index = 0; index < _Len; index++)
        {
            _pBuf->Buf[(_pBuf->Write + index) % _pBuf->BufSize] = *((uint8_t *)_Data + index);
        }
        _pBuf->Write = (_pBuf->Write + _Len) % _pBuf->BufSize;
        _pBuf->Count += _Len;
        
        return BF_OK;
    }
    else
    {
        return BF_FULL;
    }

}

Status Buffer_ReadByte(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t index;

    if (_Len <= _pBuf->Count)
    {
        for (index = 0; index < _Len; index++)
        {
            *((uint8_t *)_Data + index) = _pBuf->Buf[(_pBuf->Read + index) % _pBuf->BufSize];
        }
        _pBuf->Read = (_pBuf->Read + _Len) % _pBuf->BufSize;
        _pBuf->Count -= _Len;

        return BF_OK;
    }
    else
    {
        return BF_EMPTY;
    }

}


Status Buffer_WriteShort(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t index, len;
    uint16_t *uShortVal;
   

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

        return BF_OK;
    }
    else
    {
        return BF_FULL;
    }

}

Status Buffer_ReadShort(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t index, len;

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

        return BF_OK;
    }
    else
    {
        return BF_EMPTY;
    }
}


Status Buffer_WriteInt(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t i, index, len;
    uint32_t *uIntVal;

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

        return BF_OK;
    }
    else
    {
        return BF_FULL;
    }

}

Status Buffer_ReadInt(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t i, index, len;

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
        mem_cpy(_Data, uIntVal, _Len * sizeof(uint32_t));
        free(uIntVal);

        _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
        _pBuf->Count -= len;
        return BF_OK;
    }
    else
    {
        return BF_EMPTY; // 缓存区中的数据不足
    }

}

Status Buffer_WriteLong(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t i, index, len;
    uint64_t *uLongVal;

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

        return BF_OK;
    }
    else
    {
        return BF_FULL;
    }

}

Status Buffer_ReadLong(Buffer_t *_pBuf, void *_Data, uint32_t _Len)
{
    uint32_t i, index, len;
    uint64_t *uLongVal;

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
        mem_cpy(_Data, uLongVal, _Len * sizeof(uint64_t));
        free(uLongVal);
        _pBuf->Read = (_pBuf->Read + len) % _pBuf->BufSize;
        _pBuf->Count -= len;

        return BF_OK;
    }
    else
    {
        return BF_EMPTY;
    }

}

uint32_t Buffer_GetTotalSize(Buffer_t *_pBuf) 
{  
    return _pBuf->BufSize;  
}  
  
uint32_t Buffer_GetReadPointer(Buffer_t *_pBuf) 
{  
    return _pBuf->Read;  
}  
  
uint32_t Buffer_GetWritePointer(Buffer_t *_pBuf) 
{  
    return _pBuf->Write;  
}  
  
uint32_t Buffer_GetSpaceLeft(Buffer_t *_pBuf) 
{  
    if (_pBuf->Write > _pBuf->Read) 
    {  
        return _pBuf->BufSize - (_pBuf->Write - _pBuf->Read);  
    } 
    else if (_pBuf->Write < _pBuf->Read) 
    {  
        return _pBuf->BufSize - (_pBuf->Read - _pBuf->Write);  
    } 
    else 
    {  
        if (_pBuf->Count == 0) 
        {  
            return _pBuf->BufSize;  
        } 
        else 
        {  
            return 0; 
        }  
    }  
}  
  
uint32_t Buffer_GetWrittenCount(Buffer_t *_pBuf) 
{  
    return _pBuf->Count;  
}



Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para)
{
		uint32_t i;
	
    if (!_pBuf)
    {
       return BF_NULL_POINTER;
    }
    switch (_Cmd)
    {
    case BUFFER_WRITE_BIT: // 缓存区以位写入
        return Buffer_WriteBit(_pBuf, _Data, _Len);
        
    case BUFFER_READ_BIT: // 缓存区以位读取
        return Buffer_ReadBit(_pBuf, _Data, _Len);

    case BUFFER_WRITE_BYTE: // 缓存区以字节写入
        return Buffer_WriteByte(_pBuf, _Data, _Len);

    case BUFFER_READ_BYTE: // 缓存区以字节读取
        return Buffer_ReadByte(_pBuf, _Data, _Len);

    case BUFFER_WRITE_SHORT: // 缓存区以短整型写入
        return Buffer_WriteShort(_pBuf, _Data, _Len);

    case BUFFER_READ_SHORT: // 缓存区以短整型读取
        return Buffer_ReadShort(_pBuf, _Data, _Len);

    case BUFFER_WRITE_INT: // 缓存区以整型写入
        return Buffer_WriteInt(_pBuf, _Data, _Len);

    case BUFFER_READ_INT: // 缓存区以整型读取
        return Buffer_ReadInt(_pBuf, _Data, _Len);

    case BUFFER_WRITE_LONG: // 缓存区以长整型写入
        return Buffer_WriteLong(_pBuf, _Data, _Len);

    case BUFFER_READ_LONG: // 缓存区以长整型读取
        return Buffer_ReadLong(_pBuf, _Data, _Len);
    
    case BUFFER_CLEAR: // 清空缓存区
        _pBuf->Count = 0;
        _pBuf->Read = 0;
        _pBuf->Write = 0;
        for (i = 0; i < _pBuf->BufSize; i++)
        {
            _pBuf->Buf[i] = *_Para;
        }
        

    case BUFFER_TOTAL_SIZE: // 获取缓存区的总大小。
        *_Para =  Buffer_GetTotalSize(_pBuf); 
        return BF_OK;
       
    case BUFFER_READ_POINTER: // 获取缓存区的读指针位置。
        *_Para =  Buffer_GetReadPointer(_pBuf);  
        return BF_OK;
       
    case BUFFER_WRITE_POINTER: // 获取缓存区的写指针位置。
        *_Para =  Buffer_GetWritePointer(_pBuf); 
        return BF_OK;
       
    case BUFFER_SPACE_LEFT: // 读取缓存区剩余空间
        *_Para =  Buffer_GetSpaceLeft(_pBuf);  
        return BF_OK;
       
    case BUFFER_WRITTEN_COUNT:  // 读取已写入的数据长度，单位：字节
        *_Para =  Buffer_GetWrittenCount(_pBuf);
        return BF_OK;

    default:
        return BF_NOT_SUPPORTED;
    }
}

