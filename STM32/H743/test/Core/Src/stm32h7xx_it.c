#include "bsp.h"
#include "stm32h7xx_it.h"

void NMI_Handler(void)
{
  while (1)
  {
  }
}

void HardFault_Handler(void)
{
  printf("HardFault_Handler\r\n");
  while (1)
  {
  }
}

void MemManage_Handler(void)
{

  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}




void DebugMon_Handler(void)
{

}


void SysTick_Handler(void)
{

  HAL_IncTick();

}

// void EXTI0_IRQHandler(void){
//   /*  SW  */
//   if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0)!=RESET){

//     __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
//   }
// }

// void EXTI1_IRQHandler(void){
//   /*  CLK */
//   if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1)!=RESET){
//     ech11_num();
//     __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
//   }
// }
// void EXTI2_IRQHandler(void){
//   /*  DT  */
//   if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_2)!=RESET){
//     ech11_num();
//     __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
//   }
// }


void EXTI4_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

