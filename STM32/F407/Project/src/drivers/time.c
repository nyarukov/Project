/*
 * 项目名称: time
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 定时器驱动
 */

#include "time.h"

// C 文件内容...

TIM_TypeDef *Get_Time(TIM_ID _IDx, FunctionalState NewState)
{
    switch (_IDx)
    {
    case TIM_1:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,
                               (NewState) ? ENABLE : DISABLE);
        return TIM1;
    case TIM_2:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,
                               (NewState) ? ENABLE : DISABLE);
        return TIM2;
    case TIM_3:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,
                               (NewState) ? ENABLE : DISABLE);
        return TIM3;
    case TIM_4:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,
                               (NewState) ? ENABLE : DISABLE);
        return TIM4;
    case TIM_5:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,
                               (NewState) ? ENABLE : DISABLE);
        return TIM5;
    case TIM_6:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,
                               (NewState) ? ENABLE : DISABLE);
        return TIM6;
    case TIM_7:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,
                               (NewState) ? ENABLE : DISABLE);
        return TIM7;
    case TIM_8:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,
                               (NewState) ? ENABLE : DISABLE);
        return TIM8;
    case TIM_9:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,
                               (NewState) ? ENABLE : DISABLE);
        return TIM9;
    case TIM_10:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,
                               (NewState) ? ENABLE : DISABLE);
        return TIM10;
    case TIM_11:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11,
                               (NewState) ? ENABLE : DISABLE);
        return TIM11;
    case TIM_12:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12,
                               (NewState) ? ENABLE : DISABLE);
        return TIM12;
    case TIM_13:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,
                               (NewState) ? ENABLE : DISABLE);
        return TIM13;
    case TIM_14:
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,
                               (NewState) ? ENABLE : DISABLE);
        return TIM14;
    default:
        break;
    }
    return BF_NULL;
}
static void TIM_Basic_Init(TIMRE_Config *_TimConfig)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = _TimConfig->prescaler;
    TIM_TimeBaseStructure.TIM_CounterMode = _TimConfig->counterMode;
    TIM_TimeBaseStructure.TIM_Period = _TimConfig->period;
    TIM_TimeBaseStructure.TIM_ClockDivision = _TimConfig->clockDivision;
    TIM_TimeBaseInit(Get_Time(_TimConfig->ID, ENABLE), &TIM_TimeBaseStructure);
    if (_TimConfig->interruptEnable)
    {
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
        // 根据定时器ID设置相应的中断通道
        switch (_TimConfig->ID)
        {
        case TIM_1:
            NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
            break;
        case TIM_2:
            NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
            break;
        case TIM_3:
            NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
            break;
        case TIM_4:
            NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
            break;
        case TIM_5:
            NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
            break;
        case TIM_6:
            NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
            break;
        case TIM_7:
            NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
            break;
        case TIM_8:
            NVIC_InitStructure.NVIC_IRQChannel = TIM8_BRK_TIM12_IRQn;
            break;
        case TIM_9:
            NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
            break;
        case TIM_10:
            NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
            break;
        case TIM_11:
            NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;
            break;
        case TIM_12:
            NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;
            break;
        case TIM_13:
            NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;
            break;
        case TIM_14:
            NVIC_InitStructure.NVIC_IRQChannel = TIM8_TRG_COM_TIM14_IRQn;
            break;
        default:
            // 错误处理
            break;
        }
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);
        TIM_ITConfig(Get_Time(_TimConfig->ID, ENABLE), TIM_IT_Update, ENABLE);
    }
    TIM_Cmd(Get_Time(_TimConfig->ID, ENABLE), ENABLE);
}

static void TIM_PWM_Init(TIMRE_Config *_TimConfig, PWMConfig *_PwmConfig)
{
}

static void TIM_InputCapture_Init(TIMRE_Config *_TimConfig, InputCaptureConfig *_IcConfig)
{
}

static void TIM_OutputCompare_Init(TIMRE_Config *_TimConfig, OutputCompareConfig *_OcConfig)
{
}

static void TIM_Encoder_Init(TIMRE_Config *_TimConfig, EncoderConfig *_EncoderConfig)
{
}

static void TIM_Watchdog_Init(TIMRE_Config *_TimConfig, WatchdogConfig *_WatchdogConfig)
{
}

static void TIM_RTC_Init(TIMRE_Config *_TimConfig, RTCConfig *_RtcConfig)
{
}

/**
 * @brief 初始化定时器
 *
 * 根据传入的定时器配置和特定配置，初始化相应的定时器模式。
 *
 * @param _TimConfig 定时器配置结构体指针，包含定时器的基本配置信息
 *                  可以包括定时器的ID、模式、预分频器值、计数模式、自动重载值、时钟分频等信息。
 * @param _SpecificConfig 配置结构体指针。
 *                        PWMConfig结构体指针，PWM模式；
 *                        InputCaptureConfig结构体指针，输入捕获模式；
 *                        OutputCompareConfig结构体指针，输出比较模式；
 *                        EncoderConfig结构体指针，编码器模式；
 *                        WatchdogConfig结构体指针，看门狗模式；
 *                        RTCConfig结构体指针，RTC模式；
 *                        LPTIMConfig结构体指针，低功耗定时器模式。
 *
 * @note 此函数根据定时器配置的模式选择相应的初始化函数进行初始化。如果模式不匹配或者未定义的模式，将不执行任何操作。
 *       在调用此函数之前，请确保已经正确填充了定时器配置结构体和特定配置结构体，并分配了相应的内存空间。
 *       如果有错误发生，需要在函数外部进行处理。
 */

void TIM_Init(TIMRE_Config *_TimConfig, void *_SpecificConfig)
{
    switch (_TimConfig->Mode)
    {
    case TIMER_MODE_BASIC:
        TIM_Basic_Init(_TimConfig);
        break;
    case TIMER_MODE_PWM:
        TIM_PWM_Init(_TimConfig, (PWMConfig *)_SpecificConfig);
        break;
    case TIMER_MODE_INPUT_CAPTURE:
        TIM_InputCapture_Init(_TimConfig, (InputCaptureConfig *)_SpecificConfig);
        break;
    case TIMER_MODE_OUTPUT_COMPARE:
        TIM_OutputCompare_Init(_TimConfig, (OutputCompareConfig *)_SpecificConfig);
        break;
    case TIMER_MODE_ENCODER:
        TIM_Encoder_Init(_TimConfig, (EncoderConfig *)_SpecificConfig);
        break;
    case TIMER_MODE_WATCHDOG:
        TIM_Watchdog_Init(_TimConfig, (WatchdogConfig *)_SpecificConfig);
        break;
    case TIMER_MODE_RTC:
        TIM_RTC_Init(_TimConfig, (RTCConfig *)_SpecificConfig);
        break;
    default:
        // 错误处理
        break;
    }
}

void TIM1_BRK_TIM9_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM1, TIM_IT_Break) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_Break);
        _LOG("TIM1_BRK_TIM9_IRQHandler\r\n");
    }
}
void TIM1_UP_TIM10_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
        _LOG("TIM1_UP_TIM10_IRQHandler\r\n");
    }
}
void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM1, TIM_IT_Trigger) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_Trigger);
        _LOG("TIM1_TRG_COM_TIM11_IRQHandler\r\n");
    }
}
void TIM1_CC_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM1, TIM_IT_CC1) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);
        _LOG("TIM_IT_CC1\r\n");
    }
    if (TIM_GetITStatus(TIM1, TIM_IT_CC2) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_CC2);
        _LOG("TIM_IT_CC2\r\n");
    }
    if (TIM_GetITStatus(TIM1, TIM_IT_CC3) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_CC3);
        _LOG("TIM_IT_CC3\r\n");
    }
    if (TIM_GetITStatus(TIM1, TIM_IT_CC4) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM1 中断标志位
        TIM_ClearITPendingBit(TIM1, TIM_IT_CC4);
        _LOG("TIM_IT_CC4\r\n");
    }
}
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM2 中断标志位
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        _LOG("TIM2_IRQHandler\r\n");
    }
}
void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM3 中断标志位
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
        _LOG("TIM3_IRQHandler\r\n");
    }
}
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM4 中断标志位
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        _LOG("TIM4_IRQHandler\r\n");
    }
}
void TIM6_DAC_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)
    {
        // 在这里进行你的操作
        // 清除 TIM6 中断标志位
        TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
        _LOG("TIM4_IRQHandler\r\n");
    }
}