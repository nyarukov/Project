#ifndef __BSP_CPU_FLASH_H
#define __BSP_CPU_FLASH_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp.h"

#define ADDR_FLASH_SIZE             (2*1024*1024)
#define ADDR_FLASH_BANK_SIZE 		(128*8*1024)
#define ADDR_FLASH_SECTOR_SIZE 		(128*1024)
#define ADDR_FLASH_START            (ADDR_FLASH_SECTOR_0_BANK1)
#define ADDR_FLASH_END              (ADDR_FLASH_SECTOR_7_BANK2+ADDR_FLASH_SECTOR_SIZE-1)


#define ADDR_FLASH_SECTOR_0_BANK1 	((uint32_t)0x08000000)
#define ADDR_FLASH_SECTOR_1_BANK1 	((uint32_t)0x08020000)
#define ADDR_FLASH_SECTOR_2_BANK1 	((uint32_t)0x08040000)
#define ADDR_FLASH_SECTOR_3_BANK1 	((uint32_t)0x08060000)
#define ADDR_FLASH_SECTOR_4_BANK1 	((uint32_t)0x08080000)
#define ADDR_FLASH_SECTOR_5_BANK1 	((uint32_t)0x080A0000)
#define ADDR_FLASH_SECTOR_6_BANK1 	((uint32_t)0x080C0000)
#define ADDR_FLASH_SECTOR_7_BANK1 	((uint32_t)0X080E0000)

#define ADDR_FLASH_SECTOR_0_BANK2 	((uint32_t)0x08100000)
#define ADDR_FLASH_SECTOR_1_BANK2 	((uint32_t)0X08120000)
#define ADDR_FLASH_SECTOR_2_BANK2 	((uint32_t)0X08140000)
#define ADDR_FLASH_SECTOR_3_BANK2 	((uint32_t)0X08160000)
#define ADDR_FLASH_SECTOR_4_BANK2 	((uint32_t)0X08180000)
#define ADDR_FLASH_SECTOR_5_BANK2 	((uint32_t)0X081A0000)
#define ADDR_FLASH_SECTOR_6_BANK2 	((uint32_t)0X081C0000)
#define ADDR_FLASH_SECTOR_7_BANK2 	((uint32_t)0X081E0000)


void CPU_Flash_EraseSector(uint32_t _Addr);
void CPU_Flash_Write(uint32_t _Addr, uint32_t *_pbuf,uint32_t _len);
void CPU_Flash_Read(uint32_t _Addr, uint32_t *_pbuf,uint32_t _len);

#endif
