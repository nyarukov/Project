#include "main.h"

uint8_t ota_flag;

#define Ymodem_SOH 0x01	   // 128 字节数据包的开始
#define Ymodem_STX 0x02	   // 1024 字节数据包的开始
#define Ymodem_EOT 0x04	   // 传输结束
#define Ymodem_ACK 0x06	   // 应答
#define Ymodem_NAK 0x15	   // 不应答
#define Ymodem_CA 0x18	   // 其中两个连续中止传输
#define Ymodem_C 0x43	   // 'C' == 0x43，请求传输
#define Ymodem_ABORT1 0x41 // 'A' == 0x41，由用户中止
#define Ymodem_ABORT2 0x61 // 'a' == 0x61，由用户中止

typedef struct
{
	uint8_t File_Name[10];
	uint8_t File_Size;
	uint8_t File_Buf[1024];
	uint8_t File_NB;
	uint8_t File_Start;
	uint16_t File_CRC;
} Ymodem_TCB;

Ymodem_TCB file_data = {0};

uint16_t CRC_Check(uint8_t *_crc, uint16_t _len);

int main(void)
{
	MPU_Config();
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	Uart_Init();

	printf("STM32H743IIT6_V1.2\r\n");

	// Command_List();
	// Led_Init();
	// Start_Boot();
	ota_flag = 0;
	while (1)
	{
		if (ota_flag == 0)
		{
			printf("%c", Ymodem_C);
			HAL_Delay(1000);
		}
		if (Uart1.Rxbuf[0] != 0)
		{
			ota_flag = 1;
			switch (Uart1.Rxbuf[0])
			{
			case Ymodem_SOH:
				if (file_data.File_Start == 0)
				{
					if ((Uart1.Rxbuf[1] == file_data.File_NB) && (Uart1.Rxbuf[2] == 0xFF ))
					{
						file_data.File_CRC = (Uart1.Rxbuf[131] << 8) | Uart1.Rxbuf[132];
						if (file_data.File_CRC == CRC_Check(&Uart1.Rxbuf[3], 128))
						{
							strncpy((char *)file_data.File_Name, (char *)&Uart1.Rxbuf[3], strlen((char *)&Uart1.Rxbuf[3]));
							file_data.File_Size = Uart1.Rxbuf[3 + strlen((char *)&Uart1.Rxbuf[3]) + 1];
						}
					}
				}
				else
				{
				}

				break;
			case Ymodem_STX:

				break;
			case Ymodem_EOT:

				break;
			case Ymodem_CA:

				break;
			}
		}

		// switch (Uart1.Rxbuf[0])
		// {
		// case SOH:
		// 	/* code */
		// 	break;

		// default:
		// 	break;
		// }

		// Match_Cmd((char *)Uart1.Rxbuf);
	}
}

uint16_t CRC_Check(uint8_t *_crc, uint16_t _len)
{
	uint8_t i;
	uint16_t CrcInit = 0x0000;
	uint16_t CrcPdly = 0x1021;

	while (_len--)
	{
		CrcInit = (*_crc << 8) ^ CrcInit;
		for (i = 0; i < 8; i++)
		{
			if (CrcInit & 0x8000)
				CrcInit = (CrcInit << 1) ^ CrcPdly;
			else
				CrcInit = (CrcInit << 1);
		}
		_crc++;
	}
	return CrcInit;
}