#include "bsp.h"
#include "stm32h7xx_it.h"
#if 1
#include "FreeRTOS.h"
#include "task.h"
#endif

/**
*@brief �ú��������������жϡ�
*/
void NMI_Handler(void)
{

   while (1)
  {

  }
}

/**
*@brief �ú�������Ӳ�����жϡ�
*/
void HardFault_Handler(void)
{

  printf("HardFault_Handler\r\n");
  
  while (1)
  {

  }
}

/**
*@brief �ú��������ڴ������ϡ�
*/
void MemManage_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief �ú�������Ԥȡ�����ڴ���ʴ���
*/
void BusFault_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief �ú�������δ�����ָ���Ƿ�״̬��
*/
void UsageFault_Handler(void)
{

  while (1)
  {

  }
}

/**
*@brief �ú���������Լ�������
*/
void DebugMon_Handler(void)
{

}
#if 0
/**
*@brief �ú���ͨ�� SWI ָ���ϵͳ������á�
*/
voidSVC_Handler��void��
{

}

/**
*@brief �ú�������ϵͳ����Ŀɹ�������
*/
void PendSV_Handler(void)
{

}
#endif
/**
*@brief �ú�������ϵͳ�δ��ʱ����
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
/*��� */
if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0)!=RESET){

__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}
}


void EXTI1_IRQHandler��void��{
/*ʱ�� */
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


void TIM7_IRQHandler��void��{
HAL_TIM_IRQHandler(&tim7_struct);
}
void EXTI4_IRQHandler��void��{
HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
#endif
