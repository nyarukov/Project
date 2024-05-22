#include "bsp_adc_app.h"

#define ADC_MAX_VALUE 4095
#define ADC_MIN_VALUE 0
#define PERCENTAGE_MAX 100.0f
#define PERCENTAGE_MIN 0.0f

typedef struct
{
	uint16_t MQ2;	// 烟雾
	uint16_t MQ4;	// 甲烷
	uint16_t MQ7;	// 一氧化碳
	uint16_t MQ135; // 空气污染
	uint16_t Fire;
} MQ_Value;

MQ_Value mq_temp;

void MQ7_Read_Data(void)
{
	mq_temp.MQ7 = ADC_Read(ADC_Ch1);
	float percentage = ((float)mq_temp.MQ7 - ADC_MIN_VALUE) / (ADC_MAX_VALUE - ADC_MIN_VALUE) * PERCENTAGE_MAX;
	percentage -= 47;
	if (percentage > PERCENTAGE_MAX)
	{
		user_data.MQ7 = PERCENTAGE_MAX;
	}
	else if (percentage < PERCENTAGE_MIN)
	{
		user_data.MQ7 = PERCENTAGE_MIN;
	}
	else
	{
		user_data.MQ7 = percentage;
	}
}

void MQ2_Read_Data(void)
{
	mq_temp.MQ2 = ADC_Read(ADC_Ch4);
	float percentage = ((float)mq_temp.MQ2 - ADC_MIN_VALUE) / (ADC_MAX_VALUE - ADC_MIN_VALUE) * PERCENTAGE_MAX;
	if (percentage > PERCENTAGE_MAX)
	{
		user_data.MQ2 = PERCENTAGE_MAX;
	}
	else if (percentage < PERCENTAGE_MIN)
	{
		user_data.MQ2 = PERCENTAGE_MIN;
	}
	else
	{
		user_data.MQ2 = percentage;
	}
}

void MQ4_Read_Data(void)
{
	mq_temp.MQ4 = ADC_Read(ADC_Ch3);
	float percentage = ((float)mq_temp.MQ4 - ADC_MIN_VALUE) / (ADC_MAX_VALUE - ADC_MIN_VALUE) * PERCENTAGE_MAX;
	if (percentage >= PERCENTAGE_MIN)
	{
		user_data.MQ4 = percentage;
	}
	else
	{
		user_data.MQ4 = PERCENTAGE_MIN;
	}
}

void MQ135_Read_Data(void)
{
	mq_temp.MQ135 = ADC_Read(ADC_Ch2);
	float percentage = ((float)mq_temp.MQ135 - ADC_MIN_VALUE) / (ADC_MAX_VALUE - ADC_MIN_VALUE) * PERCENTAGE_MAX;
	if (percentage > PERCENTAGE_MAX)
	{
		user_data.MQ135 = PERCENTAGE_MAX;
	}
	else if (percentage < PERCENTAGE_MIN)
	{
		user_data.MQ135 = PERCENTAGE_MIN;
	}
	else
	{
		user_data.MQ135 = percentage;
	}
}

void Fire_Read_Data(void)
{
	mq_temp.Fire = ADC_Read(ADC_Ch0);

	float raw_percentage = ((float)mq_temp.Fire / 4095) * 100;
	if (raw_percentage > 100.0f)
	{
		user_data.Fire = 100.0f;
	}
	else if (raw_percentage < 0.0f)
	{
		user_data.Fire = 0.0f;
	}
	else
	{
		user_data.Fire = raw_percentage;
	}
}

void MQx_Read_Data(void)
{
	MQ2_Read_Data();
	MQ4_Read_Data();
	MQ7_Read_Data();
	MQ135_Read_Data();
	Fire_Read_Data();
}
