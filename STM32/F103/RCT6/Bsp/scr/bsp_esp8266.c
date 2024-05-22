#include "bsp_esp8266.h"

char RECS[250];
unsigned char i;

// 需要手机开wifi热点
const char *WIFI = "DESKTOP";           // WIFI热点名称
const char *WIFIASSWORD = "75U565x1";   // WIFI热点密码

const char *ClintID = "k16bpQAqSBT.g2024-4-22|securemode=2\\,signmethod=hmacsha256\\,timestamp=1714056881708|";
const char *username = "g2024-4-22&k16bpQAqSBT";
const char *passwd = "ab1c57ac7eb7521836310a5900429cb4af073ecba036ede8775d5c3a785c0f58";
const char *Url = "iot-06z00i6gzw24b67.mqtt.iothub.aliyuncs.com";

const char *pubtopic = "/sys/k16bpQAqSBT/g2024-4-22/thing/event/property/post";
const char *subtopic = "/sys/k16bpQAqSBT/g2024-4-22/thing/event/property/post_reply";

const char *func1 = "temperature"; // 温度
const char *func2 = "Humidity";    // 湿度
const char *func3 = "LightLux";    // 光照值
const char *func4 = "Atmosphere";  // 大气压
const char *func5 = "Altitude";    // 海拔
const char *func6 = "Flame_State"; // 燃烧火焰
const char *func7 = "MQ2";         // 烟雾检测
const char *func8 = "MQ7";         // 一氧化碳
const char *func9 = "MQ4";         // 甲烷
const char *func10 = "MQ135";      // 空气质量

char ESP8266_Init(void)
{

    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "AT+RST\r\n"); // 重启
    Delay_ms(2000);

    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "ATE0\r\n"); // 关闭回显
    Delay_ms(10);
    if (strcmp(RECS, "OK"))
        return 1;

    UsartPrintf(USART3, "AT+CWMODE=1\r\n"); // Station模式
    Delay_ms(1000);
    if (strcmp(RECS, "OK"))
        return 2;

    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "AT+CWJAP=\"%s\",\"%s\"\r\n", WIFI, WIFIASSWORD); // 连接热点
    Delay_ms(2000);
    if (strcmp(RECS, "OK"))
        return 3;

    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n", ClintID, username, passwd); // 用户信息配置
    Delay_ms(10);
    if (strcmp(RECS, "OK"))
        return 4;

    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "AT+MQTTCONN=0,\"%s\",1883,1\r\n", Url); // 连接服务器
    Delay_ms(1000);
    if (strcmp(RECS, "OK"))
        return 5;

    UsartPrintf(USART3, "AT+MQTTSUB=0,\"%s\",1\r\n", subtopic); // 订阅消息
    Delay_ms(500);
    if (strcmp(RECS, "OK"))
        return 5;
    memset(RECS, 0, sizeof(RECS));
    return 0;
}

int ESP8266_PUSH(void)
{
    memset(RECS, 0, sizeof(RECS));
    UsartPrintf(USART3, "AT+MQTTPUB=0,\"%s\",\"{\\\"method\\\":\\\"thing.event.property.post\\\"\\,\\\"params\\\":{\\\"%s\\\":%.1f\\,\\\"%s\\\":%.1f\\,\\\"%s\\\":%.1f\\,\\\"%s\\\":%.1f}}\",0,0\r\n", pubtopic, func1, user_data.temp, func2, user_data.humi, func3, user_data.lux, func4, user_data.Pa);

    UsartPrintf(USART3, "AT+MQTTPUB=0,\"%s\",\"{\\\"method\\\":\\\"thing.event.property.post\\\"\\,\\\"params\\\":{\\\"%s\\\":%.1f\\,\\\"%s\\\":%f\\,\\\"%s\\\":%.1f\\,\\\"%s\\\":%.1f}}\",0,0\r\n", pubtopic, func5, user_data.ALT, func6, user_data.Fire, func7, user_data.MQ2, func8, user_data.MQ7);

    UsartPrintf(USART3, "AT+MQTTPUB=0,\"%s\",\"{\\\"method\\\":\\\"thing.event.property.post\\\"\\,\\\"params\\\":{\\\"%s\\\":%.1f\\,\\\"%s\\\":%.1f}}\",0,0\r\n", pubtopic, func9, user_data.MQ4, func10, user_data.MQ135);

    Delay_ms(200);
    if (strcmp(RECS, "ERROR") == 0)
        return 1;
    return 0;
}

void CommandAnalyse(void)
{
    if (strncmp(RECS, "+MQTTSUBRECV:", 13) == 0)
    {
        uint8_t i = 0;
        while (RECS[i++] != '\0')
        {
            if (strncmp((RECS + i), func3, 12) == 0)
            {
                while (RECS[i++] != ':')
                    ;
                // Lock = RECS[i];
            }
            if (strncmp((RECS + i), func4, 12) == 0)
            {
                while (RECS[i++] != ':')
                    ;
                // Switch2 = RECS[i];
            }
        }
    }
}

void USART3_IRQHandler(void)
{

    if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) // 接收中断
    {
        RECS[i++] = USART_ReceiveData(USART3);
        if ((RECS[i - 2] == '\r') | (RECS[i - 1] == '\n'))
        {
            RECS[i - 2] = '\0';
            i = 0;
            CommandAnalyse();
        }
    }
}
