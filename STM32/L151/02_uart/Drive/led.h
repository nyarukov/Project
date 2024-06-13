#ifndef __LED_H
#define __LED_H

#include "stm32l1xx.h"
#include <stdbool.h>

enum led_id{
	led_g=0x1,
	led_r=0x2,
	led_b=0x4
};

void led_init(enum led_id id);
void led_set(enum led_id id,bool value);
#endif