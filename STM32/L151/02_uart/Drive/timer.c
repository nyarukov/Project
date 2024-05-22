// /*
//  * timer.c
//  *
//  *  Created on: 2023��11��12��
//  *      Author: Yusaka
//  */
// #include <drive_timer.h>


// void Tim_Config(void){
//     TIM_TimeBaseInitTypeDef TIM_InitStruct;
//     RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
//     NVIC_InitTypeDef Nvic_InitStruct;

//     TIM_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
//     TIM_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
//     TIM_InitStruct.TIM_Period=(1000000/1000)-1;
//     TIM_InitStruct.TIM_Prescaler=(SystemCoreClock/1000000)-1;
//     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
//     TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
//     TIM_Cmd(TIM6, ENABLE);

//     Nvic_InitStruct.NVIC_IRQChannel=TIM6_IRQn;
//     Nvic_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//     Nvic_InitStruct.NVIC_IRQChannelPreemptionPriority=0;    //��ռ���ȼ�
//     Nvic_InitStruct.NVIC_IRQChannelSubPriority=3;           //�����ȼ�
//     NVIC_Init(&Nvic_InitStruct);
// }

// void TIM6_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

// void TIM6_IRQHandler(void){
//     if(TIM_GetITStatus(TIM6, TIM_IT_Update)!=RESET){

//     }
//     TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
// }
