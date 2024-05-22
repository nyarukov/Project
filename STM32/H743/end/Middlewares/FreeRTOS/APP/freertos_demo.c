#include "freertos_demo.h"

static void MX_FREERTOS_Init(void);

/**
 * @brief ≥ı ºªØ
 *
 */
void System_Task(void)
{
  osKernelInitialize();
  MX_FREERTOS_Init();
  osKernelStart();
}

// TaskHandle_t TaskStart_Handle;
// StackType_t TaskStart_Buff[128];
// StaticTask_t TaskStart_TCB;
// void TaskStart(void *argument);

TaskHandle_t CMD_Handle;
// StackType_t CMD_Buff[128];
// StaticTask_t CMD_TCB;
void CMDTask(void *argument);

static SemaphoreHandle_t xMutex = NULL;

void MX_FREERTOS_Init(void)
{
  xMutex = xSemaphoreCreateCounting(1, 0);

  taskENTER_CRITICAL();
  printf("Create_Task\r\n");
  xTaskCreate(CMDTask,
              "CMDTask_Task", 
              128,
              NULL,
              osPriorityBelowNormal,
              &CMD_Handle);
  // CMD_Handle = xTaskCreateStatic(CMDTask, "CMDTask_Task", 128, NULL, osPriorityBelowNormal, CMD_Buff, &CMD_TCB);
  taskEXIT_CRITICAL();
}

void CMDTask(void *argument)
{
  for (;;)
  {
    if (xSemaphoreTake(xMutex, 1000) == pdTRUE)
    {
      Match_Cmd((char *)Uart1.Rxbuf);
    }
    xSemaphoreGive(xMutex);
    vTaskDelay(100);
  }
}
