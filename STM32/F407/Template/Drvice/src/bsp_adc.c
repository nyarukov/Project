#include "bsp_adc.h"

void ADC1_Init(void)
{
    ADC_InitTypeDef ADCx_config;
    GPIO_InitTypeDef GPIOx_config;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    // 配置GPIOC引脚为模拟输入模式
    GPIOx_config.GPIO_Pin = GPIO_Pin_0;        // 使用PC0作为模拟输入引脚
    GPIOx_config.GPIO_Mode = GPIO_Mode_AN;     // 设置为模拟模式
    GPIOx_config.GPIO_PuPd = GPIO_PuPd_NOPULL; // 禁用上拉/下拉电阻
    GPIO_Init(GPIOC, &GPIOx_config);

    // 配置ADC1
    ADCx_config.ADC_Resolution = ADC_Resolution_12b;                      // 设置分辨率为12位
    ADCx_config.ADC_ScanConvMode = DISABLE;                               // 关闭扫描模式
    ADCx_config.ADC_ContinuousConvMode = ENABLE;                          // 启用连续转换模式
    ADCx_config.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None; // 禁用外部触发
    ADCx_config.ADC_DataAlign = ADC_DataAlign_Right;                      // 数据右对齐
    ADCx_config.ADC_NbrOfConversion = 1;                                  // 仅配置1个通道
    ADC_Init(ADC1, &ADCx_config);

    // 配置ADC1通道0
    ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles);

    // 启动ADC1
    ADC_Cmd(ADC1, ENABLE);

    // 启动ADC1连续转换
    ADC_SoftwareStartConv(ADC1);
}

uint16_t ADC_Read(void)
{
    // 等待转换完成
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
        ;

    // 读取转换结果
    //uint16_t adc_value = ADC_GetConversionValue(ADC1);

    // 清除转换结束标志
    ADC_ClearFlag(ADC1, ADC_FLAG_EOC);

    return 0;
}

