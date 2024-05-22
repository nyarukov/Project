/*
 * @Author: Yusaka
 * @Date: 2023-11-16 03:55:45
 * @LastEditors: Yusaka
 * @LastEditTime: 2023-11-20 11:20:35
 * @FilePath: /02_beep/project/main.c
 * @Description: 
 */
#include "common.h"
#include "clk.h"
#include "beep.h"
#include "led.h"

void delay(__O u32 val){
	while (val--);
}

int main(){

	clk_enable();
	beep_init();

	while (1)
	{
		beep_set(true);
		delay(1000000);
		beep_set(false);
		delay(1000000);
	}
	return 0;
}