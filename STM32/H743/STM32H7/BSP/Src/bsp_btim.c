#include "bsp_btim.h"

TIM_HandleTypeDef htim1;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;

// DMA_HandleTypeDef hdma_tim2_ch1;

// uint16_t tim2_oc1_dmabuff[4] __attribute__((section(".ARM.__at_0x24000000"))) = {200 - 1, 300 - 1, 400 - 1, 500 - 1};

/**##################################TIM_Init######################################**/
void TIM1_Init(uint16_t _Arr, uint16_t _Psc, uint8_t _Count, uint32_t _Pulse)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};
	// TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

	htim1.Instance = TIM1;
	htim1.Init.Prescaler = _Arr;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = _Psc;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = _Count;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_PWM_Init(&htim1);
	// HAL_TIM_OC_Init(&htim1);
	__HAL_TIM_CLEAR_FLAG(&htim1, TIM_FLAG_UPDATE);
	
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig);

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = _Pulse;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
	// HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);

	// sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	// sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	// sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	// sBreakDeadTimeConfig.DeadTime = 0xFF;
	// sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	// sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	// sBreakDeadTimeConfig.BreakFilter = 0;
	// sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
	// sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
	// sBreakDeadTimeConfig.Break2Filter = 0;
	// sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	// HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig);

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	// HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);
	// HAL_TIMEx_OCN_Start(&htim1, TIM_CHANNEL_1);
}

void TIM2_Init(uint32_t _Arr, uint32_t _Psc)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	// TIM_IC_InitTypeDef sConfigIC = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	htim2.Instance = TIM2;
	htim2.Init.Period = _Arr;
	htim2.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED3;
	htim2.Init.Prescaler = _Psc;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_OC_Init(&htim2);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);

	sConfigOC.OCMode = TIM_OCMODE_TOGGLE;
	sConfigOC.Pulse = 60; //(ARR-Pulse)/ARR
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);

	HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_1);

	// HAL_TIM_OC_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)tim2_oc1_dmabuff, 4);
}

void TIM3_Init(uint16_t _Arr, uint16_t _Psc)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_IC_InitTypeDef sConfigIC1 = {0};
	TIM_IC_InitTypeDef sConfigIC2 = {0};

	htim3.Instance = TIM3;
	htim3.Init.Period = _Arr;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Prescaler = _Psc;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_IC_Init(&htim3);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

	sConfigIC1.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC1.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC1.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC1.ICFilter = 0x08;
	HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC1, TIM_CHANNEL_1);

	sConfigIC2.ICPolarity = TIM_INPUTCHANNELPOLARITY_FALLING;
	sConfigIC2.ICSelection = TIM_ICSELECTION_INDIRECTTI;
	sConfigIC2.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC2.ICFilter = 0x08;
	HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC2, TIM_CHANNEL_2);

	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
	__HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_UPDATE);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
}

void BaseTIM6_Init(uint16_t _Arr, uint16_t _Psc, uint8_t _Count)
{

	htim6.Instance = TIM6;
	htim6.Init.Period = _Arr;
	htim6.Init.Prescaler = _Psc;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim6.Init.RepetitionCounter = _Count;

	HAL_TIM_Base_Init(&htim6);
	__HAL_TIM_CLEAR_FLAG(&htim6, TIM_FLAG_UPDATE);
	// HAL_TIM_Base_Start_IT(&htim6);
}
void BaseTIM7_Init(uint16_t _Arr, uint16_t _Psc, uint8_t _Count)
{
	htim7.Instance = TIM7;
	htim7.Init.Period = _Arr;
	htim7.Init.Prescaler = _Psc;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim7.Init.RepetitionCounter = _Count;

	HAL_TIM_Base_Init(&htim7);
	__HAL_TIM_CLEAR_FLAG(&htim6, TIM_FLAG_UPDATE);
	HAL_TIM_Base_Start(&htim7);
}
/**#############################IRQHandler############################################**/

void TIM1_UP_IRQHandler(void){
	HAL_TIM_IRQHandler(&htim1);
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim2);
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim3);
}

void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim6);
}

void TIM7_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim7);
}

// void DMA1_Stream0_IRQHandler(void)
// {
// 	HAL_DMA_IRQHandler(&hdma_tim2_ch1);
// }

/**############################# HAL_TIM_Base############################################**/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
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
}

/**#############################HAL_TIM_IC############################################**/
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *tim_icHandle)
{

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if (tim_icHandle->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
	}
	else if (tim_icHandle->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_4;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	}
}

void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *tim_icHandle)
{

	if (tim_icHandle->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_DISABLE();

		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);
		HAL_NVIC_DisableIRQ(TIM2_IRQn);
	}
	else if (tim_icHandle->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_DISABLE();

		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);
	}
}

/**#############################HAL_TIM_OC############################################**/
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *tim_ocHandle)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if (tim_ocHandle->Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOE_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	}
	else if (tim_ocHandle->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		//__HAL_RCC_DMA1_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_15;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		// hdma_tim2_ch1.Instance = DMA1_Stream0;
		// hdma_tim2_ch1.Init.Request = DMA_REQUEST_TIM2_CH1;
		// hdma_tim2_ch1.Init.Direction = DMA_PERIPH_TO_MEMORY;
		// hdma_tim2_ch1.Init.PeriphInc = DMA_PINC_DISABLE;
		// hdma_tim2_ch1.Init.MemInc = DMA_MINC_ENABLE;
		// hdma_tim2_ch1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
		// hdma_tim2_ch1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
		// hdma_tim2_ch1.Init.Mode = DMA_NORMAL;
		// hdma_tim2_ch1.Init.Priority = DMA_PRIORITY_LOW;
		// hdma_tim2_ch1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

		// HAL_DMA_Init(&hdma_tim2_ch1);

		// __HAL_LINKDMA(tim_ocHandle, hdma[TIM_DMA_ID_CC1], hdma_tim2_ch1);

		// HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
		// HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);
	}
}

void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *tim_ocHandle)
{
	if (tim_ocHandle->Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_DISABLE();
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);
		HAL_GPIO_DeInit(GPIOE, GPIO_PIN_9);
	}
	else if (tim_ocHandle->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_DISABLE();
		//__HAL_RCC_DMA1_CLK_DISABLE();

		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_15);
		// HAL_DMA_DeInit(tim_ocHandle->hdma[TIM_DMA_ID_CC1]);
	}
}

/**#############################HAL_TIM_PWM############################################**/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if (htim->Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_ENABLE();
		__HAL_RCC_GPIOE_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	}
}

void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_DISABLE();
		HAL_GPIO_DeInit(GPIOE, GPIO_PIN_9);
	}
}

uint16_t _Counter;
uint32_t sw2_start, sw2_end;

/**##################################Callback#################################**/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim->Instance == TIM6)
	{
		HAL_TIM_Base_Stop(&htim6);
		__HAL_TIM_SetCounter(&htim6, 0);
		//Uart1.Flag = 1;
	}
	else if (htim->Instance == TIM7)
	{
		Com_printf(COM1,"TIM7_UPDATE\r\n");
	}
	else if (htim->Instance == TIM2)
	{
		Com_printf(COM1,"TIM2_UPDATE\r\n");
	}
	else if (htim->Instance == TIM3)
	{
		Com_printf(COM1,"TIM3_UPDATE: %d\r\n", ++_Counter);
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			Com_printf(COM1,"HAL_TIM_ACTIVE_CHANNEL_2%d\r\n", __HAL_TIM_GET_COUNTER(&htim2));
		}
	}
	else if (htim->Instance == TIM3)
	{
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			sw2_end = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1) + _Counter * 65536;
			Com_printf(COM1,"SW2_Time: %dms\r\n", (sw2_end - sw2_start) / 10);
		}
		else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			sw2_start = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2) + _Counter * 65536;
			Com_printf(COM1,"SW2_Down\r\n");
		}
	}
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			Com_printf(COM1,"TIM1_CHANNEL_1\r\n");
		}
		else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			Com_printf(COM1,"TIM1_CHANNEL_2\r\n");
		}
		else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
		{
			Com_printf(COM1,"TIM1_CHANNEL_3\r\n");
		}
		else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
		{
			Com_printf(COM1,"TIM1_CHANNEL_4\r\n");
		}
	}
}