#ifndef __BSP_SDRAM_H
#define __BSP_SDRAM_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"

#define SDRAM_ADDR                  ((uint32_t)(0XC0000000))     //SDRAM开始地址
#define SDRAM_SIZE		            (32 * 1024 * 1024)

/*LCD显存，�??一页，2M字节*/
#define SDRAM_LCD_BUF1              ((uint16_t*)SDRAM_ADDR)

/* LCD显存,�?2�?, 分配4M字节 */
#define SDRAM_LCD_BUF2		(SDRAM_ADDR + SDRAM_LCD_SIZE)

#define SDRAM_LCD_SIZE		(4 * 1024 * 1024)		/* 每层4M */
#define SDRAM_LCD_LAYER		2						/* 2�? */

#define SDRAM_APP_BUF		(SDRAM_ADDR + SDRAM_LCD_SIZE * SDRAM_LCD_LAYER)
#define SDRAM_APP_SIZE		(SDRAM_SIZE - SDRAM_LCD_SIZE * SDRAM_LCD_LAYER)


#define SDRAM_TIMEOUT               ((uint32_t)0x1000)

#define FMC_COMMAND_TARGET_BANK     FMC_SDRAM_CMD_TARGET_BANK1	 

//SDRAM配置参数
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


void SDRAM_Init(void);
void Clear_SDRAM(uint16_t Width,uint16_t Height,uint32_t data);
void SDRAM_WriteBuffer(uint8_t *pBuffer,uint32_t WriteAddr,uint32_t n);
void SDRAM_ReadBuffer(uint8_t *pBuffer,uint32_t ReadAddr,uint32_t n);
#endif // !__BSP_SDRAM_H
