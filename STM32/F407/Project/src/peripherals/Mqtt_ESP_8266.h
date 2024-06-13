/*
 * 项目名称: Mqtt_ESP_8266
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-13 21:14:23
 * 最后修改日期: 2024-06-13 21:14:23
 * 描述: ESP_8266 MQTT数据
 */

#ifndef __MQTT_ESP_8266_H
#define __MQTT_ESP_8266_H

// 头文件内容...
#include "middle.h"
#include "gpio.h"
#include "uart.h"

#define EC80_PWR PB1
#define EC80_IGT PB2
#define EC80_RST PB3

// clang-format off
#define GPRS_DEBUG                  1

#define MQTT_BROKER_ADDRESS         "1.92.126.91"                     // MQTT 服务器地址
#define MQTT_PORT                   "1883"                            // MQTT 服务器端口

#define MQTT_CLIENT_ID              "AMKN7517"                        // MQTT 客户端ID
#define MQTT_USERNAME               "yhsw"                            // MQTT 用户名
#define MQTT_PASSWORD               "YHSWyehoo1"                      // MQTT 密码

#define MQTT_CLIENT_IDX             '0'                               // MQTT 客户端标识符。 范围： 0~5
#define MQTT_MSGID                  '1'                               // 数据包标识符。 范围： 0~65535
#define MQTT_QOS                    '0'                               // 发布消息的 QoS 等级
#define MQTT_RETAIN                 '0'                               // 服务器是否保存该消息
#define MQTT_TOPIC                  "device/para/post/"               // MQTT 主题
#define MQTT_TOPIC_S                "device/para/guanguanpost/"       // MQTT 主题发布地址

#define GPRS_Delay(n)          Delay_Ms(n)

#define GPRS_CMD_NORMAL 	0
#define GPRS_CMD_RESET 		1

// 命令超时
#define GPRS_TIME_SHORT 	3000
#define GPRS_TIME_NORMAL 	8000
#define GPRS_TIME_LONG 		15000

#define GPRS_TRY_ONCE 		1
#define GPRS_TRY_NORMAL 	3
#define GPRS_TRY_MORE 		5

#if GPRS_DEBUG
#define LOG(status)   _LOG("--> %s OK!\n", #status);
#define ERROR(status) _LOG(" ***%s Error!\n", #status);
#else
#define LOG(status)
#define ERROR(status)
#endif

// clang-format on
typedef enum
{
    GPRS_PwrON,
    GPRS_PwrOFF,
    GPRS_Reset
} GPRS_PwrStatus;

typedef enum
{
    // 初始化配置
    GPRS_INIT,

    // 电源打开
    GPRS_PowerOn,

    // 电源关闭
    GPRS_PowerOff,

    // 模块复位
    GPRS_SoftReset,


    // 测试AT
    GPRS_AT,
    // 关闭回显
    GPRS_ATE0,

    // SIM卡状态
    GPRS_CPIN,
    // SIM卡IMEI
    GPRS_CGSN,
    // SIM卡ICCID
    GPRS_CCID,

    // 功能模式0
    GPRS_CFUN_0,
    // 功能模式1
    GPRS_CFUN_1,

    // 运营商
    GPRS_COPS,

    // GPRS注册状态
    GPRS_CGREG,
    // GPRS注册
    GPRS_CGATT,

    // 接入点
    GPRS_QICSGP,
    // 移动APN接入点
    GPRS_QICSGP_CM,
    // 联通APN接入点
    GPRS_QICSGP_UN,

    // 激活GPRS
    GPRS_QIACT,
    // 取消激活GPRS
    GPRS_QIDEACT,

    // 网络链接状态
    GPRS_CIPSTATUS,
    // IP地址
    GPRS_CGPADDR,
    // DNS
    GPRS_CDNSGIP,

    // 时钟
    GPRS_QLTS,
    // 信号
    GPRS_CSQ,

    MQTT_OpenNetwork,          // 打开 MQTT 客户端网络
    MQTT_CloseNetwork,         // 关闭 MQTT 客户端网络
    MQTT_ConnectToServer,      // 连接客户端到 MQTT 服务器
    MQTT_DisconnectFromServer, // 客户端断开与 MQTT 服务器的连接
    MQTT_SubscribeTopic,       // 订阅主题
    MQTT_UnsubscribeTopic,     // 退订主题
    MQTT_PublishMessage,       // 发布消息
    MQTT_StatusError           // 连接被服务器器断开连接
} GPRS_Status;

typedef struct
{
    char broker_address[16]; // 服务器地址，IP地址格式为字符串，长度为15+1
    char port[6];            // 端口号，最大长度为5+1
    char client_id[16];      // 客户端ID
    char username[32];       // 用户名
    char password[32];       // 密码
    char client_idx;         // 客户端标识符
    char msgid;              // 数据包标识符
    char qos;                // QoS 等级
    char retain;             // 是否保留消息
    char topic[64];          // MQTT 主题
    char topic_s[64];        // MQTT 主题发布地址
} MQTT_Config;

typedef struct
{
    GPRS_Status Status;
    uint8_t MInfo[10]; // 制造商信息
    uint8_t MID[10];   // 型号 ID
    uint8_t FVID[30];  // 固件版本 ID
    uint8_t IMSI[30];  // 国际移动用户识别码（IMSI）
    uint8_t IMEI[30];  // 国际移动设备识别码（IMEI 号）
    uint8_t ICCID[30]; // QCCID
    uint8_t CSQ;       // 网络状态
    // TimeStruct time;
} GPRS_Para;

extern Queue Gprs_Queue;

void GPRS_Threads(void);
#endif
