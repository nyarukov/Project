#include "bsp_i2c_app.h"

User_Data user_data;

void Single_Write_BH1750(uint8_t address, uint8_t REG_Address)
{
    Soft_I2C_Start();
    Soft_I2C_SendByte(address);
    Soft_I2C_ReceiveAck();
    Soft_I2C_SendByte(REG_Address);
    Soft_I2C_ReceiveAck();
    Soft_I2C_Stop();
}
void BH1750_Init(void)
{
    Single_Write_BH1750(0x46, 0x01);
    Single_Write_BH1750(0x46, 0x10);
}

uint8_t buffer[2];

void BH1750_ReadLight(void)
{
    Soft_I2C_Start();

    Soft_I2C_SendByte(0x47); // 假设设备地址是0x46, 读写位设为1, 实际为0x47
    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop();   // 如果没有收到确认，结束传输
        user_data.lux = 0; // 通信错误，将lux值设为0
        return;
    }

    // 接收两个字节的数据
    buffer[0] = Soft_I2C_ReceiveByte(); // 接收第一个字节
    Soft_I2C_SendAck(0);                // 发送确认位，接收下一个字节
    buffer[1] = Soft_I2C_ReceiveByte(); // 接收第二个字节
    Soft_I2C_SendAck(1);                // 最后一个字节不发送确认位

    // 停止I2C传输
    Soft_I2C_Stop();

    user_data.lux = ((buffer[0] << 8) + buffer[1]) / 1.2;
}

int8_t Sensors_I2C_ReadRegister(uint8_t slave_address, uint8_t reg_address, uint8_t length, uint8_t *data)
{
    // 开始 I2C 通信
    Soft_I2C_Start();

    // 发送从设备地址（带写操作位）
    Soft_I2C_SendByte(slave_address << 1 | I2C_Direction_Transmitter);

    // 等待 ACK
    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop();
        return -1;
    }

    // 发送寄存器地址
    Soft_I2C_SendByte(reg_address);

    // 等待 ACK
    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop();
        return -1;
    }

    // 重新启动 I2C 通信
    Soft_I2C_Start();

    // 发送从设备地址（带读操作位）
    Soft_I2C_SendByte(slave_address << 1 | I2C_Direction_Receiver);

    // 等待 ACK
    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop();
        return -1;
    }

    // 接收数据
    for (int i = 0; i < length; i++)
    {
        data[i] = Soft_I2C_ReceiveByte();

        // 如果不是最后一个字节，发送 ACK
        if (i < length - 1)
        {
            Soft_I2C_SendAck(0);
        }
        else
        {
            // 发送 NACK
            Soft_I2C_SendAck(1);
        }
    }

    // 结束 I2C 通信
    Soft_I2C_Stop();
    return 0;
}

int8_t Sensors_I2C_WriteRegister(uint8_t slave_address, uint8_t reg_address, uint8_t length, uint8_t *data)
{
    // 开始 I2C 通信
    Soft_I2C_Start();

    // 发送从设备地址（带写操作位）
    Soft_I2C_SendByte(slave_address << 1 | I2C_Direction_Transmitter);

    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop(); // 如果没有收到确认，结束传输
        return -1;
    }
    // 发送寄存器地址
    Soft_I2C_SendByte(reg_address);

    if (Soft_I2C_ReceiveAck() != 0)
    {
        Soft_I2C_Stop(); // 如果没有收到确认，结束传输
        return -1;
    }

    // 发送数据
    for (int i = 0; i < length; i++)
    {
        Soft_I2C_SendByte(data[i]);

        if (Soft_I2C_ReceiveAck() != 0)
        {
            Soft_I2C_Stop(); // 如果没有收到确认，结束传输
            return -1;
        }
    }

    Soft_I2C_Stop();
    return 0;
}

static s32 bmp280RawPressure = 0;
static s32 bmp280RawTemperature = 0;

bmp280Calib bmp280Cal;

uint8_t BMP280_Init(void)
{
    uint8_t bmp280_id;
    uint8_t tmp[10];
    if (Sensors_I2C_ReadRegister(BMP280_SLAVE_ADDRESS, BMP280_CHIPID_REG, 1, &bmp280_id) != 0)
    {
        return 1; // 通信错误，返回1
    }

    /* 读取校准数据 */
    if (Sensors_I2C_ReadRegister(BMP280_SLAVE_ADDRESS, BMP280_DIG_T1_LSB_REG, 24, (u8 *)&bmp280Cal) != 0)
    {
        return 1; // 通信错误，返回0
    }

    tmp[0] = BMP280_MODE;
    Sensors_I2C_WriteRegister(BMP280_SLAVE_ADDRESS, BMP280_CTRLMEAS_REG, 1, tmp);

    tmp[0] = (5 << 2);
    Sensors_I2C_WriteRegister(BMP280_SLAVE_ADDRESS, BMP280_CONFIG_REG, 1, tmp); /*配置IIR滤波*/

    return bmp280_id;
}

static void BMP280GetPressure(void)
{
    u8 data[BMP280_DATA_FRAME_SIZE];

    // read data from sensor
    Sensors_I2C_ReadRegister(BMP280_SLAVE_ADDRESS, BMP280_PRESSURE_MSB_REG, BMP280_DATA_FRAME_SIZE, (u8 *)&data);
    bmp280RawPressure = (s32)((((uint32_t)(data[0])) << 12) | (((uint32_t)(data[1])) << 4) | ((uint32_t)data[2] >> 4));
    bmp280RawTemperature = (s32)((((uint32_t)(data[3])) << 12) | (((uint32_t)(data[4])) << 4) | ((uint32_t)data[5] >> 4));
}

s32 BMP280CompensateT(s32 adcT)
{
    s32 var1, var2, T;

    var1 = ((((adcT >> 3) - ((s32)bmp280Cal.dig_T1 << 1))) * ((s32)bmp280Cal.dig_T2)) >> 11;
    var2 = (((((adcT >> 4) - ((s32)bmp280Cal.dig_T1)) * ((adcT >> 4) - ((s32)bmp280Cal.dig_T1))) >> 12) * ((s32)bmp280Cal.dig_T3)) >> 14;
    bmp280Cal.t_fine = var1 + var2;

    T = (bmp280Cal.t_fine * 5 + 128) >> 8;

    return T;
}

uint32_t BMP280CompensateP(s32 adcP)
{
    int64_t var1, var2, p;
    var1 = ((int64_t)bmp280Cal.t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)bmp280Cal.dig_P6;
    var2 = var2 + ((var1 * (int64_t)bmp280Cal.dig_P5) << 17);
    var2 = var2 + (((int64_t)bmp280Cal.dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)bmp280Cal.dig_P3) >> 8) + ((var1 * (int64_t)bmp280Cal.dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)bmp280Cal.dig_P1) >> 33;
    if (var1 == 0)
        return 0;
    p = 1048576 - adcP;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)bmp280Cal.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)bmp280Cal.dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)bmp280Cal.dig_P7) << 4);
    return (uint32_t)p;
}

#define CONST_PF 0.1902630958
#define FIX_TEMP 25

static float BMP280PressureToAltitude(float *pressure)
{
    if (*pressure > 0)
    {
        return ((pow((1015.7f / *pressure), CONST_PF) - 1.0f) * (FIX_TEMP + 273.15f)) / 0.0065f;
    }
    else
    {
        return 0;
    }
}

#define FILTER_NUM 5
#define FILTER_A 0.1f

/*限幅平均滤波法*/
static void presssureFilter(float *in, float *out)
{
    static u8 i = 0;
    static float filter_buf[FILTER_NUM] = {0.0};
    double filter_sum = 0.0;
    u8 cnt = 0;
    float deta;

    if (filter_buf[i] == 0.0f)
    {
        filter_buf[i] = *in;
        *out = *in;
        if (++i >= FILTER_NUM)
            i = 0;
    }
    else
    {
        if (i)
            deta = *in - filter_buf[i - 1];
        else
            deta = *in - filter_buf[FILTER_NUM - 1];

        if (fabs(deta) < FILTER_A)
        {
            filter_buf[i] = *in;
            if (++i >= FILTER_NUM)
                i = 0;
        }
        for (cnt = 0; cnt < FILTER_NUM; cnt++)
        {
            filter_sum += filter_buf[cnt];
        }
        *out = filter_sum / FILTER_NUM;
    }
}

static float p;

void BMP280GetData(void)
{

    BMP280GetPressure();
    p = BMP280CompensateP(bmp280RawPressure) / 25600.0;
    presssureFilter(&p, &user_data.Pa);
    user_data.ALT = BMP280PressureToAltitude(&user_data.Pa);
}

void DH11_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_DQ, ENABLE);

    DQ_1();

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin = PIN_DQ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PORT_DQ, &GPIO_InitStructure);
}

static uint8_t DHT11_ReadByte(void)
{
    uint8_t i, k;
    uint8_t read = 0;

    for (i = 0; i < 8; i++)
    {
        read <<= 1;
        for (k = 0; k < 10; k++)
        {
            if (!DQ_IS_LOW())
            {
                break;
            }
            Delay_us(10);
        }
        if (k >= 10)
        {
            goto quit;
        }

        for (k = 0; k < 10; k++)
        {
            if (DQ_IS_LOW())
            {
                break;
            }
            Delay_us(10);
        }

        if (k > 3)
        {
            read++;
        }
    }

    return read;

quit:
    return 0xFF;
}

uint8_t DHT11_ReadData(void)
{
    uint8_t i;
    uint8_t k;
    uint8_t sum;
    uint8_t Buf[5];

    DQ_1();

    Delay_us(15);
    for (k = 0; k < 10; k++)
    {
        if (DQ_IS_LOW())
        {
            break;
        }
        Delay_us(10);
    }
    if (k >= 10)
    {
        goto quit;
    }

    for (k = 0; k < 10; k++)
    {
        if (!DQ_IS_LOW())
        {
            break;
        }
        Delay_us(10);
    }
    if (k >= 10)
    {
        goto quit;
    }

    for (k = 0; k < 10; k++)
    {
        if (DQ_IS_LOW())
        {
            break;
        }
        Delay_us(10);
    }
    if (k >= 10)
    {
        goto quit;
    }

    for (i = 0; i < 5; i++)
    {
        Buf[i] = DHT11_ReadByte();
    }
    Delay_us(100);

    sum = Buf[0] + Buf[1] + Buf[2] + Buf[3];
    if (sum == Buf[4])
    {
        user_data.temp = (float)Buf[2];
        user_data.humi = (float)Buf[0];
        return 1;
    }
quit:
    return 0;
}
