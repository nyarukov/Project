#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// 缓冲区操作命令
#define BUFFER_BIT_WRITE 0x00	// 以位为单位向缓冲区写入数据
#define BUFFER_BIT_READ 0x01	// 以位为单位从缓冲区读取数据
#define BUFFER_BYTE_WRITE 0x02	// 以字节为单位向缓冲区写入数据
#define BUFFER_BYTE_READ 0x03	// 以字节为单位从缓冲区读取数据
#define BUFFER_SHORT_WRITE 0x04 // 以短整型为单位向缓冲区写入数据
#define BUFFER_SHORT_READ 0x05	// 以短整型为单位从缓冲区读取数据
#define BUFFER_INT_WRITE 0x06	// 以整型为单位向缓冲区写入数据
#define BUFFER_INT_READ 0x07	// 以整型为单位从缓冲区读取数据
#define BUFFER_LONG_WRITE 0x08	// 以长整型为单位向缓冲区写入数据
#define BUFFER_LONG_READ 0x09	// 以长整型为单位从缓冲区读取数据

#define BUFFER_SIZE 0x0A	// 设置缓冲区大小
#define BUFFER_ADDRESS 0x0B // 设置缓冲区地址

#define BUFFER_CLEAR 0x0C		  // 清空缓冲区
#define BUFFER_TOTAL_SIZE 0x0D	  // 获取缓冲区的总大小
#define BUFFER_READ_POINTER 0x0E  // 获取缓冲区的读指针位置
#define BUFFER_WRITE_POINTER 0x0F // 获取缓冲区的写指针位置
#define BUFFER_SPACE_LEFT 0x10	  // 获取缓冲区中剩余空间的大小

#define __IO volatile

typedef struct
{
	uint8_t *Buf;
	uint32_t BufSize;

	__IO uint32_t Write;
	__IO uint32_t Read;
	__IO uint32_t Count;
} Buffer_t;

typedef enum
{
	OK = 1,		   // 成功
	FAILURE,	   // 失败
	ERROR,		   // 错误
	FULL,		   // 空间满
	EMPTY,		   // 空间空或读取值过大
	INVALID_PARAM, // 无效的参数
	NULL_POINTER,  // 空指针
	TOO_SMALL,	   // 过小
	TOO_LARGE,	   // 过大
	NOT_FOUND,	   // 未找到
	TIMEOUT,	   // 超时
} Status;

#define bufsize (1024 * 8)
uint8_t uart_tx_buf[bufsize];
uint8_t uart_rx_buf[bufsize];

Status BUffer_Config(Buffer_t *_pBuf, void *_Data, uint32_t _Size);
Status Buffer_Operation(Buffer_t *_pBuf,
						void *_Data,
						uint32_t _Len,
						uint32_t _Cmd,
						uint32_t *_Para);

uint32_t i;

// 测试位写入和读取
void testBufferBit()
{
	Buffer_t *uart1 = (Buffer_t *)malloc(sizeof(Buffer_t));
	BUffer_Config(uart1, uart_tx_buf, bufsize);

	uint8_t testDataBit[] = {0xAA, 0x55, 0xF0, 0x0F}; // 10101010, 01010101, 11110000, 00001111
	uint8_t readDataBit[1024];

	printf("Testing bit write and read:\n");
	Buffer_Operation(uart1, testDataBit, 8 * 8, BUFFER_BIT_WRITE, NULL);
	Buffer_Operation(uart1, readDataBit, 200, BUFFER_BIT_READ, NULL);
	printf("Read data (hex):");
	for (i = 0; i < 200; i++)
	{
		if ((i % 8) == 0)
		{
			printf("\r\n[%d]: ", i >> 3);
		}
		printf("%d\t", readDataBit[i]);
	}

	free(uart1);
}

void testBufferByte()
{
	// 创建一个缓冲区结构体指针，并分配内存
	Buffer_t *uart1 = (Buffer_t *)malloc(sizeof(Buffer_t));
	// 配置缓冲区参数，例如缓冲区地址和大小
	BUffer_Config(uart1, uart_tx_buf, bufsize);

	// 定义测试用的字节数据
	uint8_t testDataByte[] = {0xAF, 0xF0, 0xEF, 0x12, 0xAF, 0xF0, 0xEF, 0x12};
	uint64_t readDataLong[2];
	uint32_t readDataint[4];
	uint16_t readDatshort[8];
	uint8_t readDatbyte[16];

	printf("\nTesting byte write and read:\n");
	// 向缓冲区写入字节数据
	Buffer_Operation(uart1, testDataByte, 8, BUFFER_BYTE_WRITE, NULL);
	// 从缓冲区读取数据
	Buffer_Operation(uart1, readDatbyte, 8, BUFFER_BYTE_READ, NULL);

	printf("Read data (hex):");
	// 输出读取到的数据
	for (int i = 0; i < 8; i++)
	{
		if ((i % 8) == 0)
		{
			printf("\r\n [%d]:", i >> 3);
		}
		printf(" 0x%llx", readDatbyte[i]);
	}
	printf("\n");

	// 释放分配的内存
	free(uart1);
}

// 测试短整型写入和读取
void testBufferShort()
{
	Buffer_t *uart1 = (Buffer_t *)malloc(sizeof(Buffer_t));
	BUffer_Config(uart1, uart_tx_buf, bufsize);

	uint16_t testDataShort[] = {0xABCD, 0x1234, 0xEF56, 0x789A, 0x1234, 0xABCD, 0xEF56, 0x789A};
	uint64_t readDataLong[2];
	uint32_t readDataint[4];
	uint16_t readDatshort[8];
	uint8_t readDatbyte[16];

	printf("\nTesting short write and read:\n");
	Buffer_Operation(uart1, testDataShort, 8, BUFFER_SHORT_WRITE, NULL);
	Buffer_Operation(uart1, readDatbyte, 8, BUFFER_SHORT_READ, NULL);

	printf("Read data (hex):");
	// 输出读取到的数据
	for (int i = 0; i < 8; i++)
	{
		if ((i % 8) == 0)
		{
			printf("\r\n [%d]:", i >> 3);
		}

		printf(" 0x%llx", readDatbyte[i]);
	}
	printf("\n");

	free(uart1);
}

// 测试整型写入和读取
void testBufferInt()
{
	Buffer_t *uart1 = (Buffer_t *)malloc(sizeof(Buffer_t));
	BUffer_Config(uart1, uart_tx_buf, bufsize);

	uint32_t testDataInt[] = {0xABCDEF12, 0x12345678, 0x9ABCDEF0, 0x87654321};
	uint64_t readDataLong[2];
	uint32_t readDataint[4];
	uint16_t readDatshort[8];
	uint8_t readDatbyte[16];

	printf("\nTesting int write and read:\n");
	Buffer_Operation(uart1, testDataInt, 4, BUFFER_INT_WRITE, NULL);
	Buffer_Operation(uart1, readDatbyte, 16, BUFFER_BYTE_READ, NULL);

	printf("Read data (hex):");
	// 输出读取到的数据
	for (int i = 0; i < 16; i++)
	{
		if ((i % 8) == 0)
		{
			printf("\r\n [%d]:", i >> 3);
		}

		printf(" 0x%x", readDatbyte[i]);
	}
	printf("\n");

	free(uart1);
}

void testBufferLong()
{
	// 创建一个缓冲区结构体指针，并分配内存
	Buffer_t *uart1 = (Buffer_t *)malloc(sizeof(Buffer_t));
	// 配置缓冲区参数，例如缓冲区地址和大小
	BUffer_Config(uart1, uart_tx_buf, bufsize);

	printf("\nTesting Long write and read:\n");
	// 定义测试用的长整型数据
	uint64_t testDataLong[] = {0xABCDEF1234567890, 0x123456789ABCDEF0};
	// 定义用于读取数据的缓冲区
	uint64_t readDataLong[2];
	uint32_t readDataint[4];
	uint16_t readDatshort[8];
	uint8_t readDatbyte[16];

	// 向缓冲区写入长整型数据
	Buffer_Operation(uart1, testDataLong, 2, BUFFER_LONG_WRITE, NULL);
	// 从缓冲区读取数据
	Buffer_Operation(uart1, readDatbyte, 16, BUFFER_BIT_READ, NULL);

	printf("Read data (hex):");
	// 输出读取到的数据
	for (int i = 0; i < 16; i++)
	{
		if ((i % 8) == 0)
		{
			printf("\r\n [%d]:", i >> 3);
		}

		printf(" 0x%llx", readDatbyte[i]);
	}
	printf("\n");

	
	// 释放分配的内存
	free(uart1);
}

int main()
{
	Status flag;
	// testBufferBit();
	// testBufferByte();
	// testBufferShort();
	// testBufferInt();
	 testBufferLong();
	return 0;
}

Status BUffer_Config(Buffer_t *_pBuf, void *_Data, uint32_t _Size)
{
	if (!_pBuf || !_Data)
	{
		return NULL_POINTER;
	}
	_pBuf->Buf = _Data;
	_pBuf->BufSize = _Size;
	_pBuf->Count = 0;
	_pBuf->Write = 0;
	_pBuf->Read = 0;
	return OK;
}

/**
 * @brief 对环形缓冲区执行各种操作。
 *
 * 此函数允许执行诸如向缓冲区写入、从缓冲区读取、清除和查询等操作。
 *
 * @param _pBuf 指向环形缓冲区结构体的指针。
 * @param _Data 指向要从缓冲区读取或写入的数据的指针。
 * @param _Len 要处理的数据长度。
 * @param _Cmd 表示要在缓冲区上执行的操作的命令。可以使用以下预定义的命令：
 *   - BUFFER_BIT_WRITE: 			以位为单位向缓冲区写入数据。
 *   - BUFFER_BIT_READ: 			以位为单位从缓冲区读取数据。
 *   - BUFFER_BYTE_WRITE: 			以字节为单位向缓冲区写入数据。
 *   - BUFFER_BYTE_READ: 			以字节为单位从缓冲区读取数据。
 *   - BUFFER_SHORT_WRITE: 			以短整型为单位向缓冲区写入数据。
 *   - BUFFER_SHORT_READ: 			以短整型为单位从缓冲区读取数据。
 *   - BUFFER_INT_WRITE: 			以整型为单位向缓冲区写入数据。
 *   - BUFFER_INT_READ: 			以整型为单位从缓冲区读取数据。
 *   - BUFFER_LONG_WRITE: 			以长整型为单位向缓冲区写入数据。
 *   - BUFFER_LONG_REA: 			以长整型为单位从缓冲区读取数据。
 *
 *   - BUFFER_SIZE:					设置缓冲区的大小
 * 	 - BUFFER_ADDRESS:				设置缓冲区的起始地址。
 *
 *   - BUFFER_CLEAR: 				清空缓冲区。
 *   - BUFFER_TOTAL_SIZE: 			获取缓冲区的总大小。
 *   - BUFFER_READ_POINTER: 		获取缓冲区的读指针位置。
 *   - BUFFER_WRITE_POINTER: 		获取缓冲区的写指针位置。
 *   - BUFFER_SPACE_LEFT:		 	获取缓冲区中剩余空间的大小。
 * @param _Para 用于某些命令的附加参数。具体用法如下：
 *   - 当 `_Cmd` 为 `BUFFER_CLEAR` 时，`_Para` 用于设置清除缓冲区的值。
 *   - 当 `_Cmd` 为 `BUFFER_TOTAL_SIZE` 时，`_Para` 用于存储缓冲区的总大小。
 *   - 当 `_Cmd` 为 `BUFFER_READ_POINTER` 时，`_Para` 用于存储缓冲区的读指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_WRITE_POINTER` 时，`_Para` 用于存储缓冲区的写指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_SPACE_LEFT` 时，`_Para` 用于存储缓冲区中剩余空间的大小。
 * @return 操作的状态。
 *   - OK：操作成功完成。
 *   - NULL_POINTER：输入时传递了空指针。
 *   - FULL：缓冲区已满，无法执行操作。
 *   - EMPTY：缓冲区为空或值为空(读取过多)，无法执行操作。
 */
Status Buffer_Operation(Buffer_t *_pBuf,
						void *_Data,
						uint32_t _Len,
						uint32_t _Cmd,
						uint32_t *_Para)
{
	if (!_pBuf)
	{
		return NULL_POINTER;
	}
	uint32_t i, index, len;
	uint8_t *uCharVal;
	uint16_t *uShortVal;
	uint32_t *uIntVal;
	uint64_t *uLongVal;

	switch (_Cmd)
	{
	case BUFFER_BIT_WRITE: // 缓冲区以位写入
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
			return FULL;
		}
		break;

	case BUFFER_BIT_READ: // 缓冲区以位读取
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
			return EMPTY;
		}
		break;

	case BUFFER_BYTE_WRITE: // 缓冲区以字节写入
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
			return FULL;
		}
		break;

	case BUFFER_BYTE_READ: // 缓冲区以字节读取
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
			return EMPTY;
		}
		break;

	case BUFFER_SHORT_WRITE: // 缓冲区以短整型写入
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
			return FULL;
		}
		break;

	case BUFFER_SHORT_READ: // 缓冲区以短整型读取
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
			return EMPTY;
		}
		break;
		break;

	case BUFFER_INT_WRITE: // 缓冲区以整型写入
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
			return FULL;
		}
		break;

	case BUFFER_INT_READ: // 缓冲区以整型读取
		len = _Len << 2;
		if (len <= _pBuf->Count)
		{
			uint32_t *uIntVal = (uint32_t *)malloc(_Len * sizeof(uint32_t));
			if (uIntVal == NULL)
			{
				return NULL_POINTER;
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
			return OK;
		}
		else
		{
			return EMPTY; // 缓冲区中的数据不足
		}
		break;

	case BUFFER_LONG_WRITE: // 缓冲区以长整型写入
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
			return FULL;
		}
		break;

	case BUFFER_LONG_READ: // 缓冲区以长整型读取
		len = _Len << 3;
		if (len <= _pBuf->Count)
		{
			uLongVal = (uint64_t *)malloc(_Len * sizeof(uint64_t));
			if (!uLongVal)
			{
				return 0;
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
			return EMPTY;
		}
		break;
	case BUFFER_SIZE:
		_pBuf->BufSize = *_Para;
		break;
	case BUFFER_ADDRESS:
		_pBuf->Buf = (uint8_t*)_Para;
		break;
	case BUFFER_CLEAR: // 清空缓冲区
		_pBuf->Count = 0;
		_pBuf->Read = 0;
		_pBuf->Write = 0;
		for (i = 0; i < _pBuf->BufSize; i++)
		{
			_pBuf->Buf[i] = *_Para;
		}
		break;

	case BUFFER_TOTAL_SIZE: // 获取缓冲区的总大小。
		*_Para = _pBuf->BufSize;
		break;

	case BUFFER_READ_POINTER: // 获取缓冲区的读指针位置。
		*_Para = _pBuf->Read;
		break;

	case BUFFER_WRITE_POINTER: // 获取缓冲区的写指针位置。
		*_Para = _pBuf->Write;
		break;

	case BUFFER_SPACE_LEFT: // 读取缓冲区剩余空间
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
				return FULL;
			}
		}
		break;
	default:
		// 处理未知命令
		break;
	}

	return OK;
}
