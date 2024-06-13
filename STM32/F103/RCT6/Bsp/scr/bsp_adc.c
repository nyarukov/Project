#include "bsp_adc.h"

void ADC1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;

	// 使能GPIOA的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	// 配置GPIOA0-4为模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// 使能ADC1的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	// 初始化ADC1
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);

	// 配置ADC1的通道0-4
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_55Cycles5);

	// 启动ADC1校准
	ADC_Cmd(ADC1, ENABLE);
	ADC_ResetCalibration(ADC1);
	while (ADC_GetResetCalibrationStatus(ADC1))
		;
	ADC_StartCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1))
		;
}

uint16_t ADC_Read(ADC_Chx_ID channel)
{
	ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC))
		;
	return ADC_GetConversionValue(ADC1);
}
