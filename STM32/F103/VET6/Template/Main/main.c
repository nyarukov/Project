#include "stm32f10x.h"
#include "bsp_uart.h"
#include "bsp_systick.h"
#include "bsp_gpio.h"

#define Version "STM32F103 V1.0"

uint8_t _val = 0;
int main(void)
{   
    Uart_Init();
   
    IO_Init(PB2,IO_Mode_Out_PP,IO_Mode_NoPull, IO_Speed_2MHz);
	  _LOG("%s\r\n",Version);

    while (1) 
	{
        IO_Wrtie(PB2, _val = ~_val);
        Delay_Ms(1000);
		
    }
}
