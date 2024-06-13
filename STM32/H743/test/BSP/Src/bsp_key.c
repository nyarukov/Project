#include "bsp_key.h"

//static KEY_FIFO_t keys;

#if KEYMATRIX
uint8_t keyMatrix[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}};

uint16_t row_pin[] = {ROW_PIN_1, ROW_PIN_2, ROW_PIN_3, ROW_PIN_4};
uint16_t col_pin[] = {COL_PIN_1, COL_PIN_2, COL_PIN_3, COL_PIN_4};

void Key_Matrix(void)
{
    GPIO_InitTypeDef keygpio;
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    uint8_t i;
    for (i = 0; i < 4; i++)
    {
        keygpio.Pin = row_pin[i];
        keygpio.Mode = GPIO_MODE_OUTPUT_PP;
        keygpio.Speed = GPIO_SPEED_LOW;
        HAL_GPIO_Init(ROW_PORT, &keygpio);

        keygpio.Pin = col_pin[i];
        keygpio.Mode = GPIO_MODE_INPUT;
        keygpio.Pull = GPIO_PULLDOWN;
        HAL_GPIO_Init(COL_PORT, &keygpio);
    }
}

uint8_t pollKeys(void)
{
    uint8_t row, col;
    for (row = 0; row < 4; row++)
    {
        __GPIO_SET_BIT(ROW_PORT, row_pin[row]);
        for (col = 0; col < 4; col++)
        {
            if (__GPIO_IN_READ(COL_PORT, col_pin[col]))
            {
                __GPIO_RESET_BIT(ROW_PORT, row_pin[row]);
                return keyMatrix[row][col];
            }
        }
        __GPIO_RESET_BIT(ROW_PORT, row_pin[row]);
    }
    return NULL;
}
#endif

void KEY_Init(void)
{
    GPIO_InitTypeDef keygpio;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    keygpio.Pin = 1 << KEY1_PIN | 1 << KEY2_PIN | 1 << KEY3_PIN;
    keygpio.Mode = GPIO_MODE_INPUT;
    keygpio.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(KEY_PORT, &keygpio);
}

