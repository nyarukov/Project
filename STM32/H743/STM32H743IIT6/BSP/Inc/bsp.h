#ifndef __BSP_H
#define __BSP_H

#include "stm32h7xx_hal.h"
#include "bsp_systick.h"
#include "bsp_control.h"

#include "freertos_demo.h"

#define LVGL 0

#if LVGL 
// #include "ui.h"
// #include "lvgl.h"
// #include "lv_port_disp.h"
// #include "lv_port_indev.h"
#endif

#define USE_BSP_CMD                 1      // Cmd 模块

#define USE_BSP_RCC                 1      // RCC 模块

#define USE_BSP_MPU                 1      // MPU 模块

#define USE_BSP_LED                 1      // LED 模块

#define USE_BSP_UART                1      // UART 模块

#define USE_BSP_KEY                 0      // KEY 模块

#define USE_BSP_LTDC_DRAW           1      // LTDC_DRAW 模块

#define USE_BSP_SOFT_I2C            0      // SOFT_I2C 模块

#define USE_BSP_HARD_I2C            0      // HARD_I2C 模块

#define USE_BSP_SOFT_SPI            0      // SOFT_SPI 模块

#define USE_BSP_HARD_SPI            0      // HARD_SPI 模块

#define USE_BSP_BTIM                1      // BTIM 模块

#define USE_BSP_FT5426              1      // FT5426 模块

#define USE_BSP_MPU6050             0      // MPU6050 模块

#define USE_BSP_W25Q128             0      // W25Q128 模块

#define USE_BSP_QSPI_W25Q128        0      // QSPI_W25Q128 模块

#define USE_BSP_SDIO_SD             0      // SDIO_SD 模块

#define USE_BSP_CPU_FLASH           0      // CPU_FLASH 模块


#if USE_BSP_CMD
#include "bsp_cmd.h"
#endif

#if USE_BSP_RCC
#include "bsp_rcc.h"
#endif

#if USE_BSP_MPU
#include "bsp_mpu.h"
#endif

#if USE_BSP_LED
#include "bsp_led.h"
#endif

#if USE_BSP_UART
#include "bsp_uart.h"
#endif

#if USE_BSP_KEY
#include "bsp_key.h"
#endif

#if USE_BSP_LTDC_DRAW
#include "bsp_ltdc_draw.h"
#endif

#if USE_BSP_SOFT_I2C
#include "bsp_soft_i2c.h"
#endif

#if USE_BSP_HARD_I2C
#include "bsp_hard_i2c.h"
#endif

#if USE_BSP_SOFT_SPI
#include "bsp_soft_spi.h"
#endif

#if USE_BSP_HARD_SPI
#include "bsp_hard_spi.h"
#endif

#if USE_BSP_BTIM
#include "bsp_btim.h"
#endif

#if USE_BSP_FT5426
#include "bsp_ft5426.h"
#endif

#if USE_BSP_MPU6050
#include "bsp_mpu6050.h"
#endif

#if USE_BSP_W25Q128
#include "bsp_w25q128.h"
#endif

#if USE_BSP_QSPI_W25Q128
#include "bsp_qspi_w25q128.h"
#endif

#if USE_BSP_SDIO_SD
#include "bsp_sdio_sd.h"
#endif

#if USE_BSP_CPU_FLASH
#include "bsp_cpu_flash.h"
#endif




extern const uint16_t _acmickey[] ;
extern const uint16_t _ac1[];

void Bsp_Init(void);
void Bsp_Loop(void);
void Error_Handler(char *file, uint32_t line);
#endif /* __BSP_H */
