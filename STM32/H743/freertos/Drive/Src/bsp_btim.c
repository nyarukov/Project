#include "bsp_btim.h"

TIM_HandleTypeDef tim6_struct;
TIM_HandleTypeDef tim7_struct;

void BaseTIM6_Init(uint16_t arr,uint16_t psc,uint8_t count){
	
	tim6_struct.Instance=TIM6;
	tim6_struct.Init.Period=arr;
	tim6_struct.Init.Prescaler=psc;
	tim6_struct.Init.CounterMode=TIM_COUNTERMODE_UP;
	tim6_struct.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	tim6_struct.Init.AutoReloadPreload=TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim6_struct.Init.RepetitionCounter=count;
	
	HAL_TIM_Base_Init(&tim6_struct);
	__HAL_TIM_CLEAR_FLAG(&tim6_struct,TIM_FLAG_UPDATE);
	HAL_TIM_Base_Start_IT(&tim6_struct);
}
void BaseTIM7_Init(uint16_t arr,uint16_t psc,uint8_t count){
	tim7_struct.Instance=TIM7;
	tim7_struct.Init.Period=arr;
	tim7_struct.Init.Prescaler=psc;
	tim7_struct.Init.CounterMode=TIM_COUNTERMODE_UP;
	tim7_struct.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	tim7_struct.Init.AutoReloadPreload=TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim7_struct.Init.RepetitionCounter=count;
	
	HAL_TIM_Base_Init(&tim7_struct);
	__HAL_TIM_CLEAR_FLAG(&tim6_struct,TIM_FLAG_UPDATE);
	HAL_TIM_Base_Start_IT(&tim7_struct);
}
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM6){
		__HAL_RCC_TIM6_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM6_DAC_IRQn,3,0);
		HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	}else if(htim->Instance==TIM7){
		__HAL_RCC_TIM7_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM7_IRQn,3,0);
		HAL_NVIC_EnableIRQ(TIM7_IRQn);
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM6){
	}
	else if(htim->Instance==TIM7){

	}
}
