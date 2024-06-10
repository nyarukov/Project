#include "gpio.h"
#include "systick.h"
#include "uart.h"
#include "DI.h"
#include "DO.h"
#include "soft_i2c.h"
// #include "oled_096.h"
// #include "mpu6050.h"

#include "Struct_Para.h"
// #include "time.h"
#include "modbus_rtu.h"
// #include "Basic_Tim.h"

#define Version "STM32F407 V1.0"

void I2C_Test(void)
{
}
void test_modbus_functions(void);

uint8_t coil, _val = 0;
int main(void)
{

	// clang-format off
	Inti_Systemtick();
	#if (UART_COUNT > 0)
		Init_Com();
	#endif
	// init_basic_tim();
	#if DI_NUM > 0
		Init_DI();
	#endif

	#if DO_NUM > 0
		Init_DO();
	#endif

	#if (I2C_COUNT > 0)
		Soft_I2C_Init();
		Soft_I2C_SacnBus(I2C_3);
	#endif
	// clang-format on

	_LOG("%s\r\n", Version);

	// OLED_Init();

	// OLED_Clear(0x00);

	// OLED_ShowString(10, 2, "HHD Hello!", 16);
	// OLED_ShowCHinese(0, 0, 0);
	// test_modbus_functions();

	while (1)
	{
		modbus_rtu_read_coils(COM2, 0x02, 00, 8, &coil, 100);
		Delay_Ms(1000);
		// I2C_Test();
		// clang-format off
		#if DI_NUM > 0
			DI_Read();
		#endif
		#if DO_NUM > 0
			DO_Proc();

			IO_Write(PF9, _val);
			IO_Write(PF10, _val = ~_val);
		#endif
		// clang-format on
	}
}

void test_modbus_functions(void)
{
	// ModbusMaster Master1;

	// init_modbus_master(&Master1,
	// 				   COM2,
	// 				   0x01,
	// 				   1000,
	// 				   &Uart_SendData);

	// uint8_t read_buf[256];
	// uint16_t holding_buf[10] = {1234, 2345, 3456, 4567, 5678, 6789, 7891, 8912, 9123, 1011};

	// modbus_master_read_coils(&Master1, 0x01, 0x0000, read_buf, 10);
	// Delay_Ms(200);
	// modbus_master_write_single_coil(&Master1, 0x01, 0x0000, 1);
	// Delay_Ms(200);
	// modbus_master_read_discretes(&Master1, 0x01, 0x0000, read_buf, 10);
	// Delay_Ms(200);
	// modbus_master_read_single_holding(&Master1, 0x01, 0x0000, holding_buf, 10);
	// Delay_Ms(200);
	// modbus_master_write_single_holding(&Master1, 0x01, 0x0000, 0x1234);
	// Delay_Ms(200);
	// modbus_master_write_multiple_holdings(&Master1, 0x01, 0x0000, holding_buf, 10);
	// Delay_Ms(200);
	// modbus_master_read_input(&Master1, 0x01, 0x0000, holding_buf, 10);
}
