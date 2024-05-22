#include "bsp.h"

systime sys_time = {0};
uint8_t alarm_flag = 0;
uint8_t Judge = 10;
void MDV_Init(void);

void WIFI_Init(void)
{
  OLED_ShowString(5, 30, "error code:", 12, 1);
  do
  {
    OLED_ShowNumber(95, 30, Judge, 2, 12);
    OLED_Refresh_Gram();
    Judge = ESP8266_Init();
  } while (Judge); // 连接阿里云直到成功
}

void Hard_Init(void)
{
  USART1_Init();
  USART3_Init();

  OLED_Init();
  OLED_Clear();

  // PWM_Init();
  ADC1_Init();
  Beep_Init();
  Soft_I2C_Init();
  // MDV_Init();
}

void BSP_Init(void)
{
  uint8_t ret = 0;
  Button_Init();
  BH1750_Init();
  DH11_Init();
  ret = BMP280_Init();
  if (ret != 0x58)
  {
    ERROR_HANDLE("BMP280\r\n");
  }
  else
  {
    DEBUG_PRINT("BMP280_Init!\r\n");
  }
  DEBUG_PRINT("BH1750_Init!\r\n");
  BMP280GetData();
}

void main_loop_function(void);
void loop_time_check(void);
void boot_sequence(void);
void check_threshold_and_alert();

int main(void)
{

  Hard_Init();
  DEBUG_PRINT("\r\n");
  DEBUG_PRINT("SSTM32F103RCT6!\r\n");
  DEBUG_PRINT("SysCoreCLK: %dMHZ\r\n",
              SystemCoreClock / 1000000);
  DEBUG_PRINT("Hard_Init!\r\n");

  BSP_Init();
  DEBUG_PRINT("BSP_Init!\r\n");

  boot_sequence();
  WIFI_Init();
  MEnu_Init();
  ReadStructFromFlash();

  while (1)
  {
    Delay_ms(1);
    loop_time_check();
    main_loop_function();
  }
}

void main_loop_function(void)
{
  sys_time.c1ms++;
  if (sys_time.c1ms % 5 == 0)
  {
    button_ticks();
    DQ_0();

    if (sys_time.c1ms % 20 == 0)
    {
      DHT11_ReadData();
    }
    if (sys_time.c1ms % 100 == 0)
    {
      sys_time.c100ms++;

      if (sys_time.c100ms % 3 == 0)
      {
        MQx_Read_Data();
      }

      if (sys_time.c100ms % 5 == 0)
      {
        BH1750_ReadLight();
        BMP280GetData();
        GuiDataDisplayRefresh();
      }

      if (sys_time.c100ms % 10 == 0)
      {
        sys_time.c1s++;

        ESP8266_PUSH();

        if (sys_time.c1s % 1 == 0)
        {
          if (sys_time.c1s > 5)
          {
            check_threshold_and_alert();
          }
        }
#if 0
        DEBUG_PRINT("\r\n");
        DEBUG_PRINT("lx:%.2f\r\n", user_data.lux);
        DEBUG_PRINT("temp:%.2f\thumi:%.2f\r\n", user_data.temp, user_data.humi);
        DEBUG_PRINT("P:%.2f\tALT:%.2f\r\n", user_data.Pa, user_data.ALT);
        DEBUG_PRINT("MQ2 %.2f\r\n", user_data.MQ2);
        DEBUG_PRINT("MQ4 %.2f\r\n", user_data.MQ4);
        DEBUG_PRINT("MQ7 %.2f\r\n", user_data.MQ7);
        DEBUG_PRINT("MQ135 %.2f\r\n", user_data.MQ135);
#endif
      }
    }
  }
}

void boot_sequence(void)
{
  OLED_DrawLine(10, 20, 110, 20);
  OLED_DrawLine(10, 35, 110, 35);
  OLED_DrawLine(10, 20, 10, 35);
  OLED_DrawLine(110, 20, 110, 35);
  OLED_ShowString(25, 45, "Loading", 12, 1);

  char dots[4][4] = {".  ", ".. ", "...", "   "};
  int num_dots = 4;
  int dot_index = 0;

  for (int i = 0; i <= 97; i++)
  {
    progress_right(12, 22, 80, 12, i);

    if (i % 5 == 0)
    {
      OLED_ShowString(85, 45, dots[dot_index], 12, 1);
      dot_index = (dot_index + 1) % num_dots;
      OLED_Refresh_Gram();
    }
    OLED_Refresh_Gram();
    Delay_ms(20);
  }
  Delay_ms(50);
  OLED_Clear();
}

void loop_time_check(void)
{
  if (sys_time.c1ms == UINT32_MAX)
  {
    sys_time.c1ms = 0;
  }
  if (sys_time.c100ms == UINT32_MAX)
  {
    sys_time.c100ms = 0;
  }
  if (sys_time.c1s == UINT32_MAX)
  {
    sys_time.c1s = 0;
  }
}

void check_threshold_and_alert()
{

  if (user_data.temp > MDV_Flash.tempVpt ||
      user_data.humi > MDV_Flash.humiVpt ||
      user_data.lux > MDV_Flash.luxVpt ||
      user_data.Fire < MDV_Flash.fireVpt ||
      user_data.MQ2 > MDV_Flash.mq2Vpt ||
      user_data.MQ4 > MDV_Flash.mq4Vpt ||
      user_data.MQ7 > MDV_Flash.mq7Vpt ||
      user_data.MQ135 > MDV_Flash.mq135Vpt)
  {
    alarm_flag = 1;
    if (user_data.temp > MDV_Flash.tempVpt)
    {
      DEBUG_PRINT("温度过高报警: 当前温度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.temp, MDV_Flash.tempVpt, user_data.temp - MDV_Flash.tempVpt);
    }
    if (user_data.humi > MDV_Flash.humiVpt)
    {
      DEBUG_PRINT("湿度过高报警: 当前湿度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.humi, MDV_Flash.humiVpt, user_data.humi - MDV_Flash.humiVpt);
    }
    if (user_data.lux > MDV_Flash.luxVpt)
    {
      DEBUG_PRINT("光照强度过高报警: 当前光照强度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.lux, MDV_Flash.luxVpt, user_data.lux - MDV_Flash.luxVpt);
    }
    if (user_data.Fire < MDV_Flash.fireVpt)
    {
      DEBUG_PRINT("火焰检测异常报警: 当前火焰强度 %.1f, 设定阈值 %d, 低于 %.1f\n", user_data.Fire, MDV_Flash.fireVpt, MDV_Flash.fireVpt - user_data.Fire);
    }
    if (user_data.MQ2 > MDV_Flash.mq2Vpt)
    {
      DEBUG_PRINT("MQ2浓度超标报警: 当前浓度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.MQ2, MDV_Flash.mq2Vpt, user_data.MQ2 - MDV_Flash.mq2Vpt);
    }
    if (user_data.MQ4 > MDV_Flash.mq4Vpt)
    {
      DEBUG_PRINT("MQ4浓度超标报警: 当前浓度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.MQ4, MDV_Flash.mq4Vpt, user_data.MQ4 - MDV_Flash.mq4Vpt);
    }
    if (user_data.MQ7 > MDV_Flash.mq7Vpt)
    {
      DEBUG_PRINT("MQ7浓度超标报警: 当前浓度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.MQ7, MDV_Flash.mq7Vpt, user_data.MQ7 - MDV_Flash.mq7Vpt);
    }
    if (user_data.MQ135 > MDV_Flash.mq135Vpt)
    {
      DEBUG_PRINT("MQ135浓度超标报警: 当前浓度 %.1f, 设定阈值 %d, 超过 %.1f\n", user_data.MQ135, MDV_Flash.mq135Vpt, user_data.MQ135 - MDV_Flash.mq135Vpt);
    }
  }
  else
  {
    alarm_flag = 0;
  }
  if (alarm_flag)
  {
    Beep_Variable(50, 1);
  }
}

void MDV_Init(void)
{
  MDV_Flash.tempVpt = 40;
  MDV_Flash.humiVpt = 90;
  MDV_Flash.fireVpt = 50;
  MDV_Flash.luxVpt = 10000;
  MDV_Flash.mq2Vpt = 50;
  MDV_Flash.mq4Vpt = 50;
  MDV_Flash.mq7Vpt = 50;
  MDV_Flash.mq135Vpt = 50;
  WriteStructToFlash();
}