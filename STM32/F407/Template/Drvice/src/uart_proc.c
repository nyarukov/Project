#include "uart_proc.h"

// 处理 COM1 的函数
void Process_COM1(uint8_t *_pBuf, uint32_t _Len)
{
	_LOG("_pBuf[%d]:%s\r\n", _Len,_pBuf);
}

// 处理 COM2 的函数
void Process_COM2(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM3 的函数
void Process_COM3(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM4 的函数
void Process_COM4(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM5 的函数
void Process_COM5(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM6 的函数
void Process_COM6(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM7 的函数
void Process_COM7(uint8_t *_pBuf, uint32_t _Len)
{
	
}

// 处理 COM8 的函数
void Process_COM8(uint8_t *_pBuf, uint32_t _Len)
{

}

// 主处理函数，根据串口 ID 分发处理
void Uart_Process_Function(uint8_t _Id, uint8_t *_pBuf, uint32_t _Len)
{
	switch (_Id)
	{
	case COM1:
		Process_COM1(_pBuf, _Len);
		break;
	case COM2:
		Process_COM2(_pBuf, _Len);
		break;
	case COM3:
		Process_COM3(_pBuf, _Len);
		break;
	case COM4:
		Process_COM4(_pBuf, _Len);
		break;
	case COM5:
		Process_COM5(_pBuf, _Len);
		break;
	case COM6:
		Process_COM6(_pBuf, _Len);
		break;
	case COM7:
		Process_COM7(_pBuf, _Len);
		break;
	case COM8:
		Process_COM8(_pBuf, _Len);
		break;
	default:
		// 其他未知串口的处理逻辑（如果需要）
		break;
	}
}
