#include "bsp.h"
#include "stm32h7xx_it.h"
#if 1
#include "FreeRTOS.h"
#include "task.h"
#endif

/**
*@brief 该函数处理不可屏蔽中断。
*/
void NMI_Handler(void)
{

   while (1)
  {

  }
}

/**
*@brief 该函数处理硬故障中断。
*/
void HardFault_Handler(void)
{

  printf("HardFault_Handler\r\n");
  
  while (1)
  {

  }
}

/**
*@brief 该函数处理内存管理故障。
*/
void MemManage_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief 该函数处理预取错误、内存访问错误。
*/
void BusFault_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief 该函数处理未定义的指令或非法状态。
*/
void UsageFault_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief 该函数处理调试监视器。
*/
void DebugMon_Handler(void)
{

}
#if 0
/**
*@brief 该函数通过 SWI 指令处理系统服务调用。
*/
voidSVC_Handler（void）
{

}

/**
*@brief 该函数处理系统服务的可挂起请求。
*/
void PendSV_Handler(void)
{

}
#endif
/**
*@brief 该函数处理系统滴答计时器。
*/
void SysTick_Handler(void)
{

  HAL_IncTick();
	
	#if (INCLUDE_xTaskGetSchedulerState == 1 )
	if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	{
	#endif /*INCLUDE_xTaskGetSchedulerState */
		xPortSysTickHandler();
	#if (INCLUDE_xTaskGetSchedulerState == 1 )
	}
	#endif
}

void USART1_IRQHandler(void){
  HAL_UART_IRQHandler(&huart1);
}

void TIM6_DAC_IRQHandler(void){
  HAL_TIM_IRQHandler(&tim6_struct);
}

#if 0
void EXTI0_IRQHandler(void){
/*软件 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0)!=RESET){

__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}
}


void EXTI1_IRQHandler（void）{
/*时钟 */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1)!=RESET){
ech11_num();
__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}
}
void EXTI2_IRQHandler(void){
/*DT */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_2)!=RESET){
ech11_num();
__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
}
}


void TIM7_IRQHandler（void）{
HAL_TIM_IRQHandler(&tim7_struct);
}
void EXTI4_IRQHandler（void）{
HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
#endif
