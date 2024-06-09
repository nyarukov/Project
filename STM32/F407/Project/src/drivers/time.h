/*
 * 项目名称: time
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 定时器驱动
 */

#ifndef __TIME_H
#define __TIME_H

// 头文件内容...

#include "middle.h"

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
    TIM_11,
    TIM_12,
    TIM_13,
    TIM_14
} TIM_ID;

typedef enum
{
    TIMER_MODE_BASIC = 0,
    TIMER_MODE_PWM,
    TIMER_MODE_INPUT_CAPTURE,
    TIMER_MODE_OUTPUT_COMPARE,
    TIMER_MODE_ENCODER,
    TIMER_MODE_WATCHDOG,
    TIMER_MODE_RTC
} TIMER_Mode;
// 基本配置
typedef struct
{
    TIM_ID ID;               // 定时器ID
    uint8_t Mode;            // 定时器模式(PWM,输入捕获,输出比较,编码器接口,看门狗,RTC,低功耗,中断和DMA)
    uint8_t interruptEnable; // 中断使能
    uint8_t dmaEnable;       // DMA 使能
    uint32_t prescaler;      // 预分频器值
    uint32_t counterMode;    // 计数模式（向上、向下、中心对齐）
    uint32_t period;         // 自动重装载值
    uint32_t clockDivision;  // 时钟分频
    uint32_t dmaRequest;     // DMA 请求源
} TIMRE_Config;

// PWM 配置
typedef struct
{
    uint32_t pulse;     // PWM 脉冲宽度
    uint32_t polarity;  // PWM 极性
    uint32_t idleState; // 空闲状态
    uint32_t channel;   // 通道选择
} PWMConfig;

// 输入捕获配置
typedef struct
{
    uint32_t channel;   // 通道选择
    uint32_t polarity;  // 极性（上升沿、下降沿）
    uint32_t selection; // 输入捕获选择
    uint32_t prescaler; // 捕获预分频
    uint32_t filter;    // 输入滤波
} InputCaptureConfig;

// 输出比较配置
typedef struct
{
    uint32_t channel;      // 通道选择
    uint32_t compareValue; // 比较值
    uint32_t mode;         // 输出比较模式
    uint32_t polarity;     // 极性
} OutputCompareConfig;

// 编码器接口配置
typedef struct
{
    uint32_t mode;         // 编码器模式
    uint32_t IC1Polarity;  // 输入捕获1极性
    uint32_t IC2Polarity;  // 输入捕获2极性
    uint32_t IC1Selection; // 输入捕获1选择
    uint32_t IC2Selection; // 输入捕获2选择
    uint32_t IC1Prescaler; // 输入捕获1预分频
    uint32_t IC2Prescaler; // 输入捕获2预分频
    uint32_t IC1Filter;    // 输入捕获1滤波
    uint32_t IC2Filter;    // 输入捕获2滤波
} EncoderConfig;

// 看门狗配置
typedef struct
{
    uint32_t prescaler; // 预分频器
    uint32_t reload;    // 重载值
    uint32_t window;    // 窗口值
} WatchdogConfig;

// RTC 配置
typedef struct
{
    uint32_t hourFormat;     // 小时格式
    uint32_t asynchPrediv;   // 异步预分频
    uint32_t synchPrediv;    // 同步预分频
    uint32_t output;         // 输出配置
    uint32_t outputPolarity; // 输出极性
} RTCConfig;

// 低功耗定时器配置
typedef struct
{
    uint32_t clockSource;  // 时钟源
    uint32_t prescaler;    // 预分频器
    uint32_t wave;         // 波形选择
    uint32_t wavePolarity; // 波形极性
    uint32_t updateMode;   // 更新模式
} LPTIMConfig;

void TIM_Init(TIMRE_Config *_TimConfig, void *_SpecificConfig);

#endif
