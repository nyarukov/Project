/*
 * ��Ŀ����: time
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-01
 * ����޸�����: 2024-06-01 18:09:50
 * ����: ��ʱ������
 */

#ifndef __TIME_H
#define __TIME_H

// ͷ�ļ�����...

typedef enum
{
    TIM_1 = 0,
    TIM_2,
    TIM_3,
    TIM_4,
    TIM_5,
    TIM_6,
    TIM_7,
    TIM_8,
    TIM_9,
    TIM_10,
} TIM_ID;

// clang-format off
#define TIM1_EN         1
#define TIM2_EN         1
#define TIM3_EN         1
#define TIM4_EN         1
#define TIM5_EN         1
#define TIM6_EN         1
#define TIM7_EN         1
#define TIM8_EN         1
#define TIM9_EN         1
#define TIM10_EN        1

#if TIM1_EN == 1
// #ifdef TIM1_EN
//     #error  "This is a custom warning message."
// #endif

#endif

#if TIM2_EN == 1


#endif

#if TIM3_EN == 1


#endif

#if TIM4_EN == 1


#endif

#if TIM5_EN == 1


#endif

#if TIM6_EN == 1


#endif

#if TIM7_EN == 1


#endif

#if TIM8_EN == 1


#endif

#if TIM9_EN == 1


#endif

#if TIM10_EN == 1


#endif

// clang-format on

#endif
