#include "gpio.h"
#include "systick.h"
#include "uart.h"
#include "soft_i2c.h"
#include "oled_096.h"
#include "mpu6050.h"
#include "DI.h"
#include "Struct_Para.h"
#include "time.h"
#include "modbus_slave.h"
#include "modbus_master.h"
#include "Basic_Tim.h"

#define Version "STM32F407 V1.0"

ModbusSlave Salve1;

void I2C_Test(void)
{
}
void test_modbus_functions(void);

uint8_t _val = 0;
int main(void)
{

	// clang-format off
	inti_systemtick();
	#if (UART_COUNT > 0)
		COM_Init();
	#endif
	// init_basic_tim();
	#if DI_NUM > 0
		init_di();
	#endif

	#if DO_NUM > 0
		init_do();
	#endif

	#if (I2C_COUNT > 0)
		Soft_I2C_Init();
	#endif
	// clang-format on

	init_modbus_slave(&Salve1,
					  COM2,
					  0x01,
					  &Uart_SendData,
					  16,
					  16,
					  16,
					  16);

	Soft_I2C_SacnBus(I2C_1);

	_LOG("%s\r\n", Version);

	// OLED_Init();

	// OLED_Clear(0x00);

	// OLED_ShowString(10, 2, "HHD Hello!", 16);
	// OLED_ShowCHinese(0, 0, 0);
	// test_modbus_functions();
	while (1)
	{
		// I2C_Test();
		DI_Read();
		DO_Proc();
		Delay_Ms(500);
		IO_Write(PF9, _val);
		IO_Write(PF10, _val = ~_val);
		
	}
}

void test_modbus_functions(void)
{
	ModbusMaster Master1;

	init_modbus_master(&Master1,
					   COM2,
					   0x01,
					   1000,
					   &Uart_SendData);

	uint8_t read_buf[256];
	uint16_t holding_buf[10] = {1234, 2345, 3456, 4567, 5678, 6789, 7891, 8912, 9123, 1011};

	modbus_master_read_coils(&Master1, 0x01, 0x0000, read_buf, 10);
	Delay_Ms(200);
	modbus_master_write_single_coil(&Master1, 0x01, 0x0000, 1);
	Delay_Ms(200);
	modbus_master_read_discretes(&Master1, 0x01, 0x0000, read_buf, 10);
	Delay_Ms(200);
	modbus_master_read_single_holding(&Master1, 0x01, 0x0000, holding_buf, 10);
	Delay_Ms(200);
	modbus_master_write_single_holding(&Master1, 0x01, 0x0000, 0x1234);
	Delay_Ms(200);
	modbus_master_write_multiple_holdings(&Master1, 0x01, 0x0000, holding_buf, 10);
	Delay_Ms(200);
	modbus_master_read_input(&Master1, 0x01, 0x0000, holding_buf, 10);
}
