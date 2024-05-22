#include "freertos_demo.h"

static void MX_FREERTOS_Init(void);

void System_Task(void)
{
  osKernelInitialize();
  MX_FREERTOS_Init();
  osKernelStart();
}

TaskHandle_t CMD_Handle;
void CMDTask(void *argument);

TaskHandle_t LED_Handle;
void LEDTask(void *argument);

void MX_FREERTOS_Init(void)
{
  taskENTER_CRITICAL();
  printf("Create_Task\r\n");
  xTaskCreate(CMDTask,
              "CMDTask",
              128,
              NULL,
              osPriorityBelowNormal,
              &CMD_Handle);
  xTaskCreate(LEDTask,
              "LEDTask",
              128,
              NULL,
              osPriorityBelowNormal,
              &LED_Handle);
  taskEXIT_CRITICAL();
}

void CMDTask(void *argument)
{
  for (;;)
  {
    //printf("CMDTask\r\n");
    Match_Cmd((char *)Uart1.Rxbuf);
    vTaskDelay(100);
  }
}

void LEDTask(void *argument)
{
  for (;;)
  {
    //printf("LEDTask\r\n");
    vTaskDelay(100);
  }
}
