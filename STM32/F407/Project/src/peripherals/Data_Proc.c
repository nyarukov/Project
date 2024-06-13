/*
 * 项目名称: Data_Proc
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-08 10:36:22
 * 最后修改日期: 2024-06-08 10:36:22
 * 描述: 中间数据处理
 */

#include "Data_Proc.h"
#include "Mqtt_ESP_8266.h"
// C 文件内容...

void COM1_Proc(uint8_t *_pBuf, uint32_t _Len)
{

    _LOG("--> COM1:[%d]= ", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("-[%#X]-", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
    Buffer_Clear(&COM_OF(COM1).RxBuf, 0);
}
void COM2_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM2:[%d]= ", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("-[%#X]-", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
    for (uint32_t i = 0; i < _Len; ++i)
    {
        if (!enqueue(&Gprs_Queue, _pBuf[i]))
        {
            _LOG("Gprs_Queue Full!\r\n");
            break;
        }
    }
    Buffer_Clear(&COM_OF(COM2).RxBuf, 0);
}
void COM3_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM3:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}
void COM4_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM4:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}
void COM5_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM5:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}
void COM6_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM6:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}
void COM7_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM7:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}
void COM8_Proc(uint8_t *_pBuf, uint32_t _Len)
{
    _LOG("--> COM8:[%d]\r\n", _Len);
    // clang-format off
    #if 1
        _LOG("%s\r\n", _pBuf);
    #else
        for (size_t i = 0; i < _Len; i++)
        {
            _LOG("%#X\t", _pBuf[i]);
        }
        _LOG("\r\n");
    #endif
    // clang-format on
}

void Com_DataProc(void)
{
    uint32_t size;
    for (size_t i = 0; i < COM8_IDX; i++)
    {
        if ((Buffer_Get_Written_Count(&COM_OF(i).RxBuf, &size) == BF_SUCCESS) && (size > 0))
        {
            switch (i)
            {
            case 0:
                COM1_Proc(COM_OF(COM1).RxBuf.Buf, size);
                break;
            case 1:
                COM2_Proc(COM_OF(COM2).RxBuf.Buf, size);
                break;
            case 2:
                COM3_Proc(COM_OF(COM3).RxBuf.Buf, size);
                break;
            case 3:
                COM4_Proc(COM_OF(COM4).RxBuf.Buf, size);
                break;
            case 4:
                COM5_Proc(COM_OF(COM5).RxBuf.Buf, size);
                break;
            case 5:
                COM6_Proc(COM_OF(COM6).RxBuf.Buf, size);
                break;
            case 6:
                COM7_Proc(COM_OF(COM7).RxBuf.Buf, size);
                break;
            case 7:
                COM8_Proc(COM_OF(COM8).RxBuf.Buf, size);
                break;

            default:
                break;
            }
        }
    }
}