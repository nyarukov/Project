#ifndef __BSP_I2C_APP_H
#define __BSP_I2C_APP_H

#include "bsp_soft_i2c.h"
#include "bsp.h"
#include <math.h>

#define BMP280_SLAVE_ADDRESS 0x77 /* I2C从机地址 */

/*calibration parameters */
#define BMP280_DIG_T1_LSB_REG 0x88
#define BMP280_DIG_T1_MSB_REG 0x89
#define BMP280_DIG_T2_LSB_REG 0x8A
#define BMP280_DIG_T2_MSB_REG 0x8B
#define BMP280_DIG_T3_LSB_REG 0x8C
#define BMP280_DIG_T3_MSB_REG 0x8D
#define BMP280_DIG_P1_LSB_REG 0x8E
#define BMP280_DIG_P1_MSB_REG 0x8F
#define BMP280_DIG_P2_LSB_REG 0x90
#define BMP280_DIG_P2_MSB_REG 0x91
#define BMP280_DIG_P3_LSB_REG 0x92
#define BMP280_DIG_P3_MSB_REG 0x93
#define BMP280_DIG_P4_LSB_REG 0x94
#define BMP280_DIG_P4_MSB_REG 0x95
#define BMP280_DIG_P5_LSB_REG 0x96
#define BMP280_DIG_P5_MSB_REG 0x97
#define BMP280_DIG_P6_LSB_REG 0x98
#define BMP280_DIG_P6_MSB_REG 0x99
#define BMP280_DIG_P7_LSB_REG 0x9A
#define BMP280_DIG_P7_MSB_REG 0x9B
#define BMP280_DIG_P8_LSB_REG 0x9C
#define BMP280_DIG_P8_MSB_REG 0x9D
#define BMP280_DIG_P9_LSB_REG 0x9E
#define BMP280_DIG_P9_MSB_REG 0x9F

#define BMP280_CHIPID_REG 0xD0           /*Chip ID Register */
#define BMP280_RESET_REG 0xE0            /*Softreset Register */
#define BMP280_STATUS_REG 0xF3           /*Status Register */
#define BMP280_CTRLMEAS_REG 0xF4         /*Ctrl Measure Register */
#define BMP280_CONFIG_REG 0xF5           /*Configuration Register */
#define BMP280_PRESSURE_MSB_REG 0xF7     /*Pressure MSB Register */
#define BMP280_PRESSURE_LSB_REG 0xF8     /*Pressure LSB Register */
#define BMP280_PRESSURE_XLSB_REG 0xF9    /*Pressure XLSB Register */
#define BMP280_TEMPERATURE_MSB_REG 0xFA  /*Temperature MSB Reg */
#define BMP280_TEMPERATURE_LSB_REG 0xFB  /*Temperature LSB Reg */
#define BMP280_TEMPERATURE_XLSB_REG 0xFC /*Temperature XLSB Reg */

#define BMP280_SLEEP_MODE (0x00)
#define BMP280_FORCED_MODE (0x01)
#define BMP280_NORMAL_MODE (0x03)

#define BMP280_TEMPERATURE_CALIB_DIG_T1_LSB_REG (0x88)
#define BMP280_PRESSURE_TEMPERATURE_CALIB_DATA_LENGTH (24)
#define BMP280_DATA_FRAME_SIZE (6)

#define BMP280_OVERSAMP_SKIPPED (0x00)
#define BMP280_OVERSAMP_1X (0x01)
#define BMP280_OVERSAMP_2X (0x02)
#define BMP280_OVERSAMP_4X (0x03)
#define BMP280_OVERSAMP_8X (0x04)
#define BMP280_OVERSAMP_16X (0x05)

#define BMP280_PRESSURE_OSR (BMP280_OVERSAMP_8X)
#define BMP280_TEMPERATURE_OSR (BMP280_OVERSAMP_16X)
#define BMP280_MODE (BMP280_PRESSURE_OSR << 2 | BMP280_TEMPERATURE_OSR << 5 | BMP280_NORMAL_MODE)

/* 定义GPIO端口 */
#define RCC_DQ RCC_APB2Periph_GPIOC
#define PORT_DQ GPIOC
#define PIN_DQ GPIO_Pin_13

#define DQ_0() PORT_DQ->BRR = PIN_DQ
#define DQ_1() PORT_DQ->BSRR = PIN_DQ

/* 判断DQ输入是否为低 */
#define DQ_IS_LOW() ((PORT_DQ->IDR & PIN_DQ) == 0)

typedef struct
{
    u16 dig_T1; /* calibration T1 data */
    s16 dig_T2; /* calibration T2 data */
    s16 dig_T3; /* calibration T3 data */
    u16 dig_P1; /* calibration P1 data */
    s16 dig_P2; /* calibration P2 data */
    s16 dig_P3; /* calibration P3 data */
    s16 dig_P4; /* calibration P4 data */
    s16 dig_P5; /* calibration P5 data */
    s16 dig_P6; /* calibration P6 data */
    s16 dig_P7; /* calibration P7 data */
    s16 dig_P8; /* calibration P8 data */
    s16 dig_P9; /* calibration P9 data */
    s32 t_fine; /* calibration t_fine data */
} bmp280Calib;

uint8_t BMP280_Init(void);
void BMP280GetData(void);

void BH1750_Init(void);
void BH1750_ReadLight(void);

// void AHT20_Read_init(void);
// uint8_t ATH20_Read_Status(void);
// uint8_t ATH20_Read_Cal_Enable(void);
// void ATH20_Read_data(void);
// uint8_t ATH20_Init(void);

void DH11_Init(void);
uint8_t DHT11_ReadData(void);
#endif
