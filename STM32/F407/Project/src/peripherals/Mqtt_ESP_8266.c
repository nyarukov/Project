/*
 * 项目名称: Mqtt_ESP_8266
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-13 21:14:23
 * 最后修改日期: 2024-06-13 21:14:23
 * 描述: ESP_8266 MQTT数据
 */

#include "Mqtt_ESP_8266.h"

// C 文件内容...

MQTT_Config Config;
Queue Gprs_Queue;

GPRS_Para ESP8266;

void Init_Mqtt_Config(MQTT_Config *config)
{
    strcpy(config->broker_address, MQTT_BROKER_ADDRESS);
    strcpy(config->port, MQTT_PORT);
    strcpy(config->client_id, MQTT_CLIENT_ID);
    strcpy(config->username, MQTT_USERNAME);
    strcpy(config->password, MQTT_PASSWORD);
    config->client_idx = MQTT_CLIENT_IDX;
    config->msgid = MQTT_MSGID;
    config->qos = MQTT_QOS;
    config->retain = MQTT_RETAIN;
    strcpy(config->topic, MQTT_TOPIC);
    strcpy(config->topic_s, MQTT_TOPIC_S);

    LOG(Init_Mqtt_Config);
}

void GPRS_IoInit(void)
{
    LOG(GPRS_IoInit);
}

void GPRS_PowerStart(GPRS_PwrStatus _Status)
{
    switch (_Status)
    {
    case GPRS_PwrON:

        GPRS_Delay(800);
        IO_Write(EC80_PWR, 1);
        GPRS_Delay(800);
        IO_Write(EC80_IGT, 1);
        GPRS_Delay(800);
        IO_Write(EC80_IGT, 0);

        LOG(GPRS_PwrON);
        break;
    case GPRS_PwrOFF:

        GPRS_Delay(800);
        IO_Write(EC80_IGT, 0);
        GPRS_Delay(800);
        IO_Write(EC80_IGT, 1);
        GPRS_Delay(800);
        IO_Write(EC80_PWR, 0);

        LOG(GPRS_PwrOFF);
        break;
    case GPRS_Reset:

        IO_Write(EC80_RST, 1);
        GPRS_Delay(800);
        IO_Write(EC80_IGT, 1);
        GPRS_Delay(2000);
        IO_Write(EC80_RST, 0);
        GPRS_Delay(800);
        IO_Write(EC80_IGT, 0);

        LOG(GPRS_Reset);

        break;

    default:
        break;
    }
}

typedef void (*ResponseParser)(uint8_t *, uint32_t);

/**
 * @brief 发送命令并等待特定响应或超时
 *
 * @param _Command 发送的命令字符串
 * @param _ResponseStr 期望的响应字符串
 * @param _Response 响应解析函数指针，可以为NULL
 * @param _nTimeout 超时时间（毫秒）
 * @param _nTryCount 尝试次数
 * @param _nReset 是否在尝试次数超过后进行复位操作
 * @return int 返回值为0表示成功找到期望的响应字符串，返回1表示超时或者其他错误
 */
int Command_Wait_Response(const char *_Command,
                          const char *_ResponseStr,
                          ResponseParser _Response,
                          uint32_t _nTimeout,
                          uint32_t _nTryCount,
                          uint8_t _nReset)

{
    uint8_t data[512];
    uint32_t len;
    uint32_t try_count = 0;
    uint8_t response_found = 0;

    while (try_count < _nTryCount && !response_found)
    {
        if (_Command != NULL)
        {
            Uart_SendData(COM2, (uint8_t *)_Command, strlen(_Command));
        }

        uint32_t start_time = Get_Tick();
        uint32_t onTime = 0;

        while (onTime < _nTimeout)
        {
            onTime = Get_Tick() - start_time;
            if (dequeue_line(&Gprs_Queue, data, &len))
            {
                if (strncmp((char *)data, _ResponseStr, strlen(_ResponseStr)) == 0)
                {
                    LOG(_ResponseStr);
                    if (_Response != NULL)
                    {
                        _Response(data, len);
                    }
                    queue_init(&Gprs_Queue);
                    response_found = 1;
                    break;
                }
            }
        }

        if (!response_found && onTime >= _nTimeout)
        {
            ERROR(AT_Timeout);
            queue_init(&Gprs_Queue);
        }

        try_count++;
    }

    if (!response_found && try_count >= _nTryCount && _nReset)
    {
        ERROR(GPRS_RESET);
        GPRS_PowerStart(GPRS_Reset);
        queue_init(&Gprs_Queue);
        return 1;
    }

    return response_found ? 0 : 1;
}

void Init_ESP_8266(void)
{
    Init_Mqtt_Config(&Config);
    GPRS_IoInit();
}

// 测试AT
int OnGprsCmd_AT(void)
{
    return Command_Wait_Response((const char *)"AT\r\n",
                                 (const char *)"OK",
                                 NULL,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_ONCE,
                                 GPRS_CMD_RESET);
}
// 关闭回显
int OnGprsCmd_ATE0(void)
{
    return Command_Wait_Response((const char *)"ATE0\r\n",
                                 (const char *)"OK",
                                 NULL,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_ONCE,
                                 GPRS_CMD_RESET);
}
// 获取SIM卡状态
int OnGprsCmd_CPIN(void)
{
    return Command_Wait_Response((const char *)"AT+CPIN?\r\n",
                                 (const char *)"OK",
                                 NULL,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

void IMEI_Get(uint8_t *_pBuf, uint32_t _Len)
{
}

// SIM卡IMEI
int OnGprsCmd_IMEI(void)
{
    return Command_Wait_Response((const char *)"AT+CGSN\r\n",
                                 (const char *)"OK",
                                 IMEI_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

void ICCID_Get(uint8_t *_pBuf, uint32_t _Len)
{
}

// SIM卡ICCID
int OnGprsCmd_ICCID(void)
{
    return Command_Wait_Response((const char *)"AT+CCID\r\n",
                                 (const char *)"OK",
                                 ICCID_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 解析信号
void CSQ_Get(uint8_t *_pBuf, uint32_t _Len)
{
}
// 网络质量
int OnGprsCmd_CSQ(void)
{
    return Command_Wait_Response((const char *)"AT+CSQ\r\n",
                                 (const char *)"OK",
                                 CSQ_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 解析时钟
void QLTS_Get(uint8_t *_pBuf, uint32_t _Len)
{
}
// 时钟
int OnGprsCmd_QLTS(void)
{
    return Command_Wait_Response((const char *)"AT+QLTS=1\r\n",
                                 (const char *)"OK",
                                 QLTS_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_NORMAL);
}

// 1 全功能模式
int OnGprsCmd_CFUN_1(void)
{
    return Command_Wait_Response((const char *)"AT+CFUN=1\r\n",
                                 (const char *)"OK",
                                 NULL,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 解析运营商
void COPS_Get(uint8_t *_pBuf, uint32_t _Len)
{
}
// 查询运营商
int OnGprsCmd_COPS(void)
{
    return Command_Wait_Response((const char *)"AT+COPS?\r\n",
                                 (const char *)"OK",
                                 COPS_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 解析GPRS注册状态
void CGREG_Get(uint8_t *_pBuf, uint32_t _Len)
{
}
// 注册PS业务
int OnGprsCmd_CGREG(void)
{
    return Command_Wait_Response((const char *)"AT+CGREG?\r\n",
                                 (const char *)"OK",
                                 CGREG_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 激活PDP场景
int OnGprsCmd_QIACT(void)
{
    return Command_Wait_Response((const char *)"AT+QIACT=1\r\n",
                                 (const char *)"OK",
                                 NULL,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}

// 解析IP
void CGPADDR_Get(uint8_t *_pBuf, uint32_t _Len)
{
}
// 获取IP地址
int OnGprsCmd_CGPADDR(void)
{
    return Command_Wait_Response((const char *)"AT+CGPADDR=1\r\n",
                                 (const char *)"OK",
                                 CGPADDR_Get,
                                 GPRS_TIME_SHORT,
                                 GPRS_TRY_NORMAL,
                                 GPRS_CMD_RESET);
}
void GPRS_Threads(void)
{
    switch (ESP8266.Status)
    {
    case GPRS_INIT:
        Init_ESP_8266();
        ESP8266.Status = GPRS_PowerOn;
        break;
    case GPRS_PowerOn:
        GPRS_PowerStart(GPRS_PwrON);
        ESP8266.Status = GPRS_AT;
        break;
    case GPRS_PowerOff:
        GPRS_PowerStart(GPRS_PwrOFF);
        break;
    case GPRS_SoftReset:
        GPRS_PowerStart(GPRS_Reset);
        ESP8266.Status = GPRS_PowerOn;
        break;
    case GPRS_AT: // 测试AT
        if (OnGprsCmd_AT())
        {
            ERROR(GPRS_AT);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_AT);
            ESP8266.Status = GPRS_ATE0;
        }

        break;
    case GPRS_ATE0: // 关闭回显
        if (OnGprsCmd_ATE0())
        {
            ERROR(GPRS_ATE0);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_ATE0);
            ESP8266.Status = GPRS_CPIN;
        }

        break;
    case GPRS_CPIN: // SIM卡状态
        if (OnGprsCmd_CPIN())
        {
            ERROR(GPRS_CPIN);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CPIN);
            ESP8266.Status = GPRS_CGSN;
        }
        break;
    case GPRS_CGSN: // SIM卡IMEI
        if (OnGprsCmd_IMEI())
        {
            ERROR(GPRS_CGSN);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CGSN);
            ESP8266.Status = GPRS_CCID;
        }
        break;
    case GPRS_CCID: // SIM卡ICCID
        if (OnGprsCmd_ICCID())
        {
            ERROR(GPRS_CCID);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CCID);
            ESP8266.Status = GPRS_CSQ; // 信号
        }
        break;
    case GPRS_CSQ: // 信号
        if (OnGprsCmd_CSQ())
        {
            ERROR(GPRS_CSQ);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CSQ);
            ESP8266.Status = GPRS_QLTS;
        }
        break;
    case GPRS_QLTS: // 时钟
        if (OnGprsCmd_QLTS())
        {
            ERROR(GPRS_QLTS);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_QLTS);
            ESP8266.Status = GPRS_CFUN_1;
        }
        break;
    case GPRS_CFUN_1: // 功能模式1
        if (OnGprsCmd_CFUN_1())
        {
            ERROR(GPRS_CFUN_1);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CFUN_1);
            ESP8266.Status = GPRS_COPS;
        }
        break;
    case GPRS_COPS: // 运营商
        if (OnGprsCmd_COPS())
        {
            ERROR(GPRS_COPS);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_COPS);
            ESP8266.Status = GPRS_CGREG;
        }
        break;
    case GPRS_CGREG: // GPRS注册状态
        if (OnGprsCmd_CGREG())
        {
            ERROR(GPRS_CGREG);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CGREG);
            ESP8266.Status = GPRS_CGATT;
        }
        break;
    case GPRS_CGATT: // GPRS注册
        if (OnGprsCmd_QIACT())
        {
            ERROR(GPRS_CGATT);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CGATT);
            ESP8266.Status = GPRS_QICSGP;
        }
        break;
    case GPRS_QICSGP: // 接入点
        if (OnGprsCmd_CPIN())
        {
            ERROR(GPRS_QICSGP);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_QICSGP);
            ESP8266.Status = GPRS_QIACT;
        }
        break;
    case GPRS_QIACT: // 激活GPRS
        if (OnGprsCmd_QIACT())
        {
            ERROR(GPRS_QIACT);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_QIACT);
            ESP8266.Status = GPRS_CGPADDR;
        }
        break;
    case GPRS_CGPADDR: // IP地址
        if (OnGprsCmd_CGPADDR())
        {
            ERROR(GPRS_CGPADDR);
            ESP8266.Status = GPRS_SoftReset;
        }
        else
        {
            LOG(GPRS_CGPADDR);
            ESP8266.Status = MQTT_OpenNetwork;
        }
        break;

    default:
        break;
    }
}