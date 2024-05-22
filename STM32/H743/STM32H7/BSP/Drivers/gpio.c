#include "gpio.h"

// GPIO ��ʼ�����ò��ұ�
const uint32_t initConfigs[] = {
    {GPIO_MODE_INPUT|GPIO_NOPULL},       // 0x00UL: ��������ģʽ
    {GPIO_MODE_ANALOG|0},                // 0x01UL: ģ������ģʽ
    {GPIO_MODE_INPUT|GPIO_PULLUP},       // 0x02UL: ��������ģʽ
    {GPIO_MODE_INPUT|GPIO_PULLDOWN},     // 0x04UL: ��������ģʽ
    {GPIO_MODE_OUTPUT_PP|GPIO_PULLUP},   // 0x08UL: �����������ģʽ
    {GPIO_MODE_OUTPUT_PP|GPIO_PULLDOWN}, // 0x10UL: �����������ģʽ
    {GPIO_MODE_OUTPUT_OD|GPIO_PULLUP},   // 0x20UL: ��©�������ģʽ
    {GPIO_MODE_OUTPUT_OD|GPIO_PULLDOWN}  // 0x40UL: ��©�������ģʽ
};

// ���� GPIO �ٶ�����
const uint32_t GPIO_Speed[] = {
    GPIO_SPEED_FREQ_LOW,
    GPIO_SPEED_FREQ_MEDIUM,
    GPIO_SPEED_FREQ_HIGH,
    GPIO_SPEED_FREQ_VERY_HIGH};

// ���� GPIO ��ַ����
const GPIO_TypeDef *GPIOx[] = {
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF,
    GPIOG,
    GPIOH,
    GPIOI
};


void IO_Init(uint8_t *_IOx, uint8_t _Mode, uint8_t _Speed)
{
    uint8_t index = _IOx[1] - 'A';
    uint8_t pin = GPIO_PIN_NUM(_IOx);
    GPIO_TypeDef *gpio_instance = GPIOx[index];

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.Pin = 1 << GPIO_PIN_NUM(_IOx);
    GPIO_InitStructure.Mode = initConfigs[_Mode];
    GPIO_InitStructure.Pull = initConfigs[_Mode];
    GPIO_InitStructure.Speed = GPIO_Speed[_Speed];

    HAL_GPIO_Init(gpio_instance,&GPIO_InitStructure);
}

uint32_t IO_Read(uint32_t _IOx, uint8_t _Para)
{
    // IDR_reg:         GPIOA_BASS+0x10UL 16 1bit
    // ODR_reg:         GPIOA_BASS+0x14UL 16 1bit
    //__IO uint32_t *BSRR_reg = (uint32_t *)(addr + 0x18UL);
    //uint8_t pin = GPIO_PIN_NUM(_IOx);
    if (_Para > 1)
    {
    }
    return 0;
}

void IO_Write(uint32_t _IOx, uint32_t _Val, uint8_t _Para)
{
    if (_Para > 1)
    {
    }
}

int8_t IO_Ctrl(uint32_t _IOx, IOCmd _CMD, uint8_t _Para)
{
    return 0;
}
