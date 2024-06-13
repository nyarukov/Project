#include "stm32f4xx.h"
#include "bsp_uart.h"
#include "bsp_systick.h"
#include "bsp_gpio.h"


#define Version "STM32F407 V1.0"

uint8_t _val = 0;
int main(void)
{   
    Uart_Init();

    
    IO_Init(PF9, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_2MHz);
    IO_Init(PF10, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_2MHz);

    _LOG("%s\r\n", Version);

    while (1) {

        IO_Wrtie(PF9, _val);
        IO_Wrtie(PF10, _val = ~_val);
        Delay_Ms(250);
    }
}
