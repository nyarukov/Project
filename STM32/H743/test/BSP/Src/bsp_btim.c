#include "bsp_btim.h"

TIM_HandleTypeDef tim6_struct;
TIM_HandleTypeDef tim7_struct;
TIM_HandleTypeDef htim3;
/**############################################################################**/
void BaseTIM6_Init(uint16_t arr, uint16_t psc, uint8_t count)
{

	tim6_struct.Instance = TIM6;
	tim6_struct.Init.Period = arr;
	tim6_struct.Init.Prescaler = psc;
	tim6_struct.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim6_struct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim6_struct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim6_struct.Init.RepetitionCounter = count;

	HAL_TIM_Base_Init(&tim6_struct);
	__HAL_TIM_CLEAR_FLAG(&tim6_struct, TIM_FLAG_UPDATE);
	// HAL_TIM_Base_Start_IT(&tim6_struct);
}
void BaseTIM7_Init(uint16_t arr, uint16_t psc, uint8_t count)
{
	tim7_struct.Instance = TIM7;
	tim7_struct.Init.Period = arr;
	tim7_struct.Init.Prescaler = psc;
	tim7_struct.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim7_struct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim7_struct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim7_struct.Init.RepetitionCounter = count;

	HAL_TIM_Base_Init(&tim7_struct);
	__HAL_TIM_CLEAR_FLAG(&tim6_struct, TIM_FLAG_UPDATE);
	HAL_TIM_Base_Start_IT(&tim7_struct);
}
/**############################################################################**/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if (htim->Instance == TIM6)
	{
		__HAL_RCC_TIM6_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 3, 0);
		HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	}
	else if (htim->Instance == TIM7)
	{
		__HAL_RCC_TIM7_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM7_IRQn, 3, 0);
		HAL_NVIC_EnableIRQ(TIM7_IRQn);
	}
	else if (htim->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		__HAL_RCC_TIM6_CLK_DISABLE();
		HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
	}
	else if (htim->Instance == TIM7)
	{
		__HAL_RCC_TIM7_CLK_DISABLE();
		HAL_NVIC_DisableIRQ(TIM7_IRQn);
	}
	else if (htim->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_DISABLE();
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5);
		HAL_NVIC_DisableIRQ(TIM3_IRQn);
	}
}

/**############################################################################**/
void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim6_struct);
}

void TIM7_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim7_struct);
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim3);
	u1_printf("TIM3_IRQHandler\r\n");
}
/**############################################################################**/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim->Instance == TIM6)
	{
		HAL_TIM_Base_Stop(&tim6_struct);
		__HAL_TIM_SetCounter(&tim6_struct, 0);
		Uart1.Flag = 1;
	}
	else if (htim->Instance == TIM7)
	{
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM3)
	{
		u1_printf("AAAAA\r\n");
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
			u1_printf("AAAAA\r\n");
	}
}
/**############################################################################**/

void TIM3_Init(uint16_t arr, uint16_t psc)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_IC_InitTypeDef sConfigIC = {0};

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = psc;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = arr;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_IC_Init(&htim3);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;
	HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, TIM_CHANNEL_2);

	// HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
}
