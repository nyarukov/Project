#ifndef __BSP_CPU_FLASH_H
#define __BSP_CPU_FLASH_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"

void CPU_Flash_ErasePage(uint32_t _Addr);
void CPU_Flash_Write(uint32_t _Addr, uint32_t *_pbuf, uint32_t _len);
void CPU_Flash_Read(uint32_t _Addr, uint32_t *_pbuf, uint32_t _len);

#endif
