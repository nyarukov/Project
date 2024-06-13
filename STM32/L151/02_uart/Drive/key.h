#ifndef __KEY_H
#define __KEY_H

#include "stm32l1xx.h"

enum key_id{
	key_en		= 0x20,
	key_down	= 0x40,
	key_up		= 0x80,
};
#define key_read(id)		((GPIOB->IDR)&id)	

void key_init(enum key_id id);
#endif