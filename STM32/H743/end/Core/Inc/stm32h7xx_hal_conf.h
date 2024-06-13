#ifndef STM32H7xx_HAL_CONF_H
#define STM32H7xx_HAL_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

/* ########################## Module Selection ############################## */
/**
*@brief 这是 HAL 驱动程序中要使用的模块列表
*/
#define HAL_MODULE_ENABLED

/* #define HAL_ADC_MODULE_ENABLED   */
/* #define HAL_FDCAN_MODULE_ENABLED   */
/* #define HAL_FMAC_MODULE_ENABLED   */
/* #define HAL_CEC_MODULE_ENABLED   */
/* #define HAL_COMP_MODULE_ENABLED   */
/* #define HAL_CORDIC_MODULE_ENABLED   */
/* #define HAL_CRC_MODULE_ENABLED   */
/* #define HAL_CRYP_MODULE_ENABLED   */
/* #define HAL_DAC_MODULE_ENABLED   */
/* #define HAL_DCMI_MODULE_ENABLED   */
#define HAL_DMA2D_MODULE_ENABLED
/* #define HAL_ETH_MODULE_ENABLED   */
/* #define HAL_ETH_LEGACY_MODULE_ENABLED   */
/* #define HAL_NAND_MODULE_ENABLED   */
/* #define HAL_NOR_MODULE_ENABLED   */
/* #define HAL_OTFDEC_MODULE_ENABLED   */
/* #define HAL_SRAM_MODULE_ENABLED   */
#define HAL_SDRAM_MODULE_ENABLED
/* #define HAL_HASH_MODULE_ENABLED   */
/* #define HAL_HRTIM_MODULE_ENABLED   */
/* #define HAL_HSEM_MODULE_ENABLED   */
/* #define HAL_GFXMMU_MODULE_ENABLED   */
/* #define HAL_JPEG_MODULE_ENABLED   */
/* #define HAL_OPAMP_MODULE_ENABLED   */
/* #define HAL_OSPI_MODULE_ENABLED   */
/* #define HAL_OSPI_MODULE_ENABLED   */
/* #define HAL_I2S_MODULE_ENABLED   */
/* #define HAL_SMBUS_MODULE_ENABLED   */
/* #define HAL_IWDG_MODULE_ENABLED   */
/* #define HAL_LPTIM_MODULE_ENABLED   */
#define HAL_LTDC_MODULE_ENABLED
#define HAL_QSPI_MODULE_ENABLED
/* #define HAL_RAMECC_MODULE_ENABLED   */
/* #define HAL_RNG_MODULE_ENABLED   */
/* #define HAL_RTC_MODULE_ENABLED   */
/* #define HAL_SAI_MODULE_ENABLED   */
#define HAL_SD_MODULE_ENABLED
/* #define HAL_MMC_MODULE_ENABLED   */
/* #define HAL_SPDIFRX_MODULE_ENABLED   */
#define HAL_SPI_MODULE_ENABLED
/* #define HAL_SWPMI_MODULE_ENABLED   */
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
/* #define HAL_USART_MODULE_ENABLED	*/
/* #define HAL_IRDA_MODULE_ENABLED   */
/* #define HAL_SMARTCARD_MODULE_ENABLED   */
/* #define HAL_WWDG_MODULE_ENABLED   */
#define HAL_PCD_MODULE_ENABLED
/* #define HAL_HCD_MODULE_ENABLED   */
/* #define HAL_DFSDM_MODULE_ENABLED   */
/* #define HAL_DSI_MODULE_ENABLED   */
/* #define HAL_JPEG_MODULE_ENABLED   */
/* #define HAL_MDIOS_MODULE_ENABLED   */
/* #define HAL_PSSI_MODULE_ENABLED   */
/* #define HAL_DTS_MODULE_ENABLED   */
#define HAL_GPIO_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_MDMA_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_HSEM_MODULE_ENABLED

/*########################## 振荡器值自适应 ######################*/
/**
  * @brief 调整应用中使用的外部高速振荡器 (HSE) 的值.
  *        RCC HAL模块使用该值来计算系统频率
  *        (当 HSE 用作系统时钟源时，直接或通过 PLL).
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE    (25000000UL)                 /*!< 外部振荡器的值（以 Hz 为单位）：FPGA 情况固定为 60MHZ*/
#endif /* HSE_VALUE */

#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT    (100UL)          /*!< HSE 启动超时，以毫秒为单位*/
#endif /* HSE_STARTUP_TIMEOUT */

/**
  * @brief 内部振荡器 (CSI) 默认值.
  *        该值为复位后的默认CSI值.
  */
#if !defined  (CSI_VALUE)
  #define CSI_VALUE    (4000000UL)                /*!< 内部振荡器的值（以 Hz 为单位）*/
#endif /* CSI_VALUE */

/**
* @brief 内部高速振荡器 (HSI) 值。
*        RCC HAL模块使用该值来计算系统频率
*       (当HSI用作系统时钟源时，直接或通过PLL)。
*/
#if !defined  (HSI_VALUE)
  #define HSI_VALUE    (64000000UL)               /*!< 内部振荡器的值（以 Hz 为单位）*/
#endif /* HSI_VALUE */

/**
* @brief 外部低速振荡器 (LSE) 值。
*        该值被UART、RTC HAL模块用来计算系统频率
*/
#if !defined  (LSE_VALUE)
  #define LSE_VALUE    (32768UL)                /*!< 外部振荡器的值（以 Hz 为单位）*/
#endif /* LSE_VALUE */

#if !defined  (LSE_STARTUP_TIMEOUT)
  #define LSE_STARTUP_TIMEOUT    (5000UL)       /*!< LSE 启动超时，以毫秒为单位*/
#endif /* LSE_STARTUP_TIMEOUT */

#if !defined  (LSI_VALUE)
  #define LSI_VALUE  (32000UL)                  /*!< LSI 典型值（以 Hz 为单位）*/
#endif                                          /*LSI_VALUE *//*!< 内部低速振荡器的值（以 Hz 为单位）
                                                实际值可能会因变化而有所不同
                                                在电压和温度方面。*/

/**
* @brief I2S 外设的外部时钟源
*        I2S HAL模块使用该值来计算I2S时钟源
*        频率，该源直接通过 I2S_CKIN 焊盘插入。
*/
#if !defined  (EXTERNAL_CLOCK_VALUE)
  #define EXTERNAL_CLOCK_VALUE    12288000UL    /*!< 外部时钟的值（以 Hz 为单位）*/
#endif /* EXTERNAL_CLOCK_VALUE */

/*提示：为避免每次需要使用不同的 HSE 时都修改此文件，
=== 您可以在工具链编译器预处理器中定义 HSE 值。*/

/* ########################### System Configuration ######################### */
/**
  * @brief This is the HAL system configuration section
  */
#define  VDD_VALUE                    (3300UL)  /*!< VDD 值（以 mv 为单位）*/
#define  TICK_INT_PRIORITY            (15UL)    /*!<tick中断优先级*/
#define  USE_RTOS                     0
#define  USE_SD_TRANSCEIVER           0U               /*!< use uSD Transceiver */
#define  USE_SPI_CRC	                0U               /*!< use CRC in SPI */

#define  USE_HAL_ADC_REGISTER_CALLBACKS             0U              /* ADC register callback disabled     */
#define  USE_HAL_CEC_REGISTER_CALLBACKS             0U              /* CEC register callback disabled     */
#define  USE_HAL_COMP_REGISTER_CALLBACKS            0U              /* COMP register callback disabled    */
#define  USE_HAL_CORDIC_REGISTER_CALLBACKS          0U              /* CORDIC register callback disabled  */
#define  USE_HAL_CRYP_REGISTER_CALLBACKS            0U              /* CRYP register callback disabled    */
#define  USE_HAL_DAC_REGISTER_CALLBACKS             0U              /* DAC register callback disabled     */
#define  USE_HAL_DCMI_REGISTER_CALLBACKS            0U              /* DCMI register callback disabled    */
#define  USE_HAL_DFSDM_REGISTER_CALLBACKS           0U              /* DFSDM register callback disabled   */
#define  USE_HAL_DMA2D_REGISTER_CALLBACKS           0U              /* DMA2D register callback disabled   */
#define  USE_HAL_DSI_REGISTER_CALLBACKS             0U              /* DSI register callback disabled     */
#define  USE_HAL_DTS_REGISTER_CALLBACKS             0U              /* DTS register callback disabled     */
#define  USE_HAL_ETH_REGISTER_CALLBACKS             0U              /* ETH register callback disabled     */
#define  USE_HAL_FDCAN_REGISTER_CALLBACKS           0U              /* FDCAN register callback disabled   */
#define  USE_HAL_FMAC_REGISTER_CALLBACKS            0U              /* FMAC register callback disabled  */
#define  USE_HAL_NAND_REGISTER_CALLBACKS            0U              /* NAND register callback disabled    */
#define  USE_HAL_NOR_REGISTER_CALLBACKS             0U              /* NOR register callback disabled     */
#define  USE_HAL_SDRAM_REGISTER_CALLBACKS           0U              /* SDRAM register callback disabled   */
#define  USE_HAL_SRAM_REGISTER_CALLBACKS            0U              /* SRAM register callback disabled    */
#define  USE_HAL_HASH_REGISTER_CALLBACKS            0U              /* HASH register callback disabled    */
#define  USE_HAL_HCD_REGISTER_CALLBACKS             0U              /* HCD register callback disabled     */
#define  USE_HAL_GFXMMU_REGISTER_CALLBACKS          0U              /* GFXMMU register callback disabled  */
#define  USE_HAL_HRTIM_REGISTER_CALLBACKS           0U              /* HRTIM register callback disabled   */
#define  USE_HAL_I2C_REGISTER_CALLBACKS             0U              /* I2C register callback disabled     */
#define  USE_HAL_I2S_REGISTER_CALLBACKS             0U              /* I2S register callback disabled     */
#define  USE_HAL_IRDA_REGISTER_CALLBACKS            0U              /* IRDA register callback disabled    */
#define  USE_HAL_JPEG_REGISTER_CALLBACKS            0U              /* JPEG register callback disabled    */
#define  USE_HAL_LPTIM_REGISTER_CALLBACKS           0U              /* LPTIM register callback disabled   */
#define  USE_HAL_LTDC_REGISTER_CALLBACKS            0U              /* LTDC register callback disabled    */
#define  USE_HAL_MDIOS_REGISTER_CALLBACKS           0U              /* MDIO register callback disabled    */
#define  USE_HAL_MMC_REGISTER_CALLBACKS             0U              /* MMC register callback disabled     */
#define  USE_HAL_OPAMP_REGISTER_CALLBACKS           0U              /* MDIO register callback disabled    */
#define  USE_HAL_OSPI_REGISTER_CALLBACKS            0U              /* OSPI register callback disabled    */
#define  USE_HAL_OTFDEC_REGISTER_CALLBACKS          0U              /* OTFDEC register callback disabled  */
#define  USE_HAL_PCD_REGISTER_CALLBACKS             0U              /* PCD register callback disabled     */
#define  USE_HAL_QSPI_REGISTER_CALLBACKS            0U              /* QSPI register callback disabled    */
#define  USE_HAL_RNG_REGISTER_CALLBACKS             0U              /* RNG register callback disabled     */
#define  USE_HAL_RTC_REGISTER_CALLBACKS             0U              /* RTC register callback disabled     */
#define  USE_HAL_SAI_REGISTER_CALLBACKS             0U              /* SAI register callback disabled     */
#define  USE_HAL_SD_REGISTER_CALLBACKS              0U              /* SD register callback disabled      */
#define  USE_HAL_SMARTCARD_REGISTER_CALLBACKS       0U              /* SMARTCARD register callback disabled */
#define  USE_HAL_SPDIFRX_REGISTER_CALLBACKS         0U              /* SPDIFRX register callback disabled */
#define  USE_HAL_SMBUS_REGISTER_CALLBACKS           0U              /* SMBUS register callback disabled   */
#define  USE_HAL_SPI_REGISTER_CALLBACKS             0U              /* SPI register callback disabled     */
#define  USE_HAL_SWPMI_REGISTER_CALLBACKS           0U              /* SWPMI register callback disabled   */
#define  USE_HAL_TIM_REGISTER_CALLBACKS             0U              /* TIM register callback disabled     */
#define  USE_HAL_UART_REGISTER_CALLBACKS            0U              /* UART register callback disabled    */
#define  USE_HAL_USART_REGISTER_CALLBACKS           0U              /* USART register callback disabled   */
#define  USE_HAL_WWDG_REGISTER_CALLBACKS            0U              /* WWDG register callback disabled    */

/*########################### 以太网配置 ##################### ####*/
#define ETH_TX_DESC_CNT         4U                  /*以太网 Tx DMA 描述符的数量*/
#define ETH_RX_DESC_CNT         4U                  /*以太网 Rx DMA 描述符的数量*/

#define ETH_MAC_ADDR0    (0x02UL)
#define ETH_MAC_ADDR1    (0x00UL)
#define ETH_MAC_ADDR2    (0x00UL)
#define ETH_MAC_ADDR3    (0x00UL)
#define ETH_MAC_ADDR4    (0x00UL)
#define ETH_MAC_ADDR5    (0x00UL)

/* ########################## Assert Selection ############################## */
/**
* @brief 取消注释下面的行以扩展“assert_param”宏
*        HAL驱动代码
*/
/* #define USE_FULL_ASSERT    1U */

/* Includes ------------------------------------------------------------------*/
/**
* @brief 包含模块的头文件
*/

#ifdef HAL_RCC_MODULE_ENABLED
  #include "stm32h7xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
  #include "stm32h7xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
  #include "stm32h7xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_MDMA_MODULE_ENABLED
 #include "stm32h7xx_hal_mdma.h"
#endif /* HAL_MDMA_MODULE_ENABLED */

#ifdef HAL_HASH_MODULE_ENABLED
  #include "stm32h7xx_hal_hash.h"
#endif /* HAL_HASH_MODULE_ENABLED */

#ifdef HAL_DCMI_MODULE_ENABLED
  #include "stm32h7xx_hal_dcmi.h"
#endif /* HAL_DCMI_MODULE_ENABLED */

#ifdef HAL_DMA2D_MODULE_ENABLED
  #include "stm32h7xx_hal_dma2d.h"
#endif /* HAL_DMA2D_MODULE_ENABLED */

#ifdef HAL_DSI_MODULE_ENABLED
  #include "stm32h7xx_hal_dsi.h"
#endif /* HAL_DSI_MODULE_ENABLED */

#ifdef HAL_DFSDM_MODULE_ENABLED
  #include "stm32h7xx_hal_dfsdm.h"
#endif /* HAL_DFSDM_MODULE_ENABLED */

#ifdef HAL_DTS_MODULE_ENABLED
 #include "stm32h7xx_hal_dts.h"
#endif /* HAL_DTS_MODULE_ENABLED */

#ifdef HAL_ETH_MODULE_ENABLED
  #include "stm32h7xx_hal_eth.h"
#endif /* HAL_ETH_MODULE_ENABLED */

#ifdef HAL_ETH_LEGACY_MODULE_ENABLED
  #include "stm32h7xx_hal_eth_legacy.h"
#endif /* HAL_ETH_LEGACY_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
  #include "stm32h7xx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_CORTEX_MODULE_ENABLED
  #include "stm32h7xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
  #include "stm32h7xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_FDCAN_MODULE_ENABLED
  #include "stm32h7xx_hal_fdcan.h"
#endif /* HAL_FDCAN_MODULE_ENABLED */

#ifdef HAL_CEC_MODULE_ENABLED
  #include "stm32h7xx_hal_cec.h"
#endif /* HAL_CEC_MODULE_ENABLED */

#ifdef HAL_COMP_MODULE_ENABLED
  #include "stm32h7xx_hal_comp.h"
#endif /* HAL_COMP_MODULE_ENABLED */

#ifdef HAL_CORDIC_MODULE_ENABLED
  #include "stm32h7xx_hal_cordic.h"
#endif /* HAL_CORDIC_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
  #include "stm32h7xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
  #include "stm32h7xx_hal_cryp.h"
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_DAC_MODULE_ENABLED
  #include "stm32h7xx_hal_dac.h"
#endif /* HAL_DAC_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
  #include "stm32h7xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_GFXMMU_MODULE_ENABLED
  #include "stm32h7xx_hal_gfxmmu.h"
#endif /* HAL_GFXMMU_MODULE_ENABLED */

#ifdef HAL_FMAC_MODULE_ENABLED
  #include "stm32h7xx_hal_fmac.h"
#endif /* HAL_FMAC_MODULE_ENABLED */

#ifdef HAL_HRTIM_MODULE_ENABLED
  #include "stm32h7xx_hal_hrtim.h"
#endif /* HAL_HRTIM_MODULE_ENABLED */

#ifdef HAL_HSEM_MODULE_ENABLED
  #include "stm32h7xx_hal_hsem.h"
#endif /* HAL_HSEM_MODULE_ENABLED */

#ifdef HAL_SRAM_MODULE_ENABLED
  #include "stm32h7xx_hal_sram.h"
#endif /* HAL_SRAM_MODULE_ENABLED */

#ifdef HAL_NOR_MODULE_ENABLED
  #include "stm32h7xx_hal_nor.h"
#endif /* HAL_NOR_MODULE_ENABLED */

#ifdef HAL_NAND_MODULE_ENABLED
  #include "stm32h7xx_hal_nand.h"
#endif /* HAL_NAND_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
 #include "stm32h7xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_I2S_MODULE_ENABLED
 #include "stm32h7xx_hal_i2s.h"
#endif /* HAL_I2S_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
 #include "stm32h7xx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_JPEG_MODULE_ENABLED
 #include "stm32h7xx_hal_jpeg.h"
#endif /* HAL_JPEG_MODULE_ENABLED */

#ifdef HAL_MDIOS_MODULE_ENABLED
 #include "stm32h7xx_hal_mdios.h"
#endif /* HAL_MDIOS_MODULE_ENABLED */

#ifdef HAL_MMC_MODULE_ENABLED
 #include "stm32h7xx_hal_mmc.h"
#endif /* HAL_MMC_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32h7xx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_LTDC_MODULE_ENABLED
#include "stm32h7xx_hal_ltdc.h"
#endif /* HAL_LTDC_MODULE_ENABLED */

#ifdef HAL_OPAMP_MODULE_ENABLED
#include "stm32h7xx_hal_opamp.h"
#endif /* HAL_OPAMP_MODULE_ENABLED */

#ifdef HAL_OSPI_MODULE_ENABLED
 #include "stm32h7xx_hal_ospi.h"
#endif /* HAL_OSPI_MODULE_ENABLED */

#ifdef HAL_OTFDEC_MODULE_ENABLED
#include "stm32h7xx_hal_otfdec.h"
#endif /* HAL_OTFDEC_MODULE_ENABLED */

#ifdef HAL_PSSI_MODULE_ENABLED
 #include "stm32h7xx_hal_pssi.h"
#endif /* HAL_PSSI_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
 #include "stm32h7xx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_QSPI_MODULE_ENABLED
 #include "stm32h7xx_hal_qspi.h"
#endif /* HAL_QSPI_MODULE_ENABLED */

#ifdef HAL_RAMECC_MODULE_ENABLED
 #include "stm32h7xx_hal_ramecc.h"
#endif /* HAL_RAMECC_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
 #include "stm32h7xx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
 #include "stm32h7xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
 #include "stm32h7xx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SD_MODULE_ENABLED
 #include "stm32h7xx_hal_sd.h"
#endif /* HAL_SD_MODULE_ENABLED */

#ifdef HAL_SDRAM_MODULE_ENABLED
 #include "stm32h7xx_hal_sdram.h"
#endif /* HAL_SDRAM_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
 #include "stm32h7xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_SPDIFRX_MODULE_ENABLED
 #include "stm32h7xx_hal_spdifrx.h"
#endif /* HAL_SPDIFRX_MODULE_ENABLED */

#ifdef HAL_SWPMI_MODULE_ENABLED
 #include "stm32h7xx_hal_swpmi.h"
#endif /* HAL_SWPMI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
 #include "stm32h7xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
 #include "stm32h7xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
 #include "stm32h7xx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
 #include "stm32h7xx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
 #include "stm32h7xx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
 #include "stm32h7xx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
 #include "stm32h7xx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
 #include "stm32h7xx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_HCD_MODULE_ENABLED
 #include "stm32h7xx_hal_hcd.h"
#endif /* HAL_HCD_MODULE_ENABLED */

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
* @brief assert_param 宏用于函数的参数检查。
* @param expr：如果expr为假，则调用assert_failed函数
*        报告源文件的名称和来源
*        失败呼叫的行号。
*        如果 expr 为 true，则不返回任何值。
*@retval 无
*/
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t *file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_HAL_CONF_H */
