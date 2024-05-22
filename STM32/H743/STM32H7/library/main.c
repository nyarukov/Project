#include "include/mr_lib.h"

/* 定义串口设备描述符 */
int serial_ds = -1;

void serial_init(void)
{
    /* 初始化串口 */
    serial_ds = mr_dev_open("serial1", MR_O_RDWR); 
    if (serial_ds < 0)
    {
        mr_printf("serial open failed: %s\r\n", mr_strerror(serial_ds));
        return;
    }
    /* 设置串口配置 */
    struct mr_serial_config config = MR_SERIAL_CONFIG_DEFAULT;
    int ret = mr_dev_ioctl(serial_ds, MR_IOC_SERIAL_SET_CONFIG, &config);
    if (ret < 0)
    {
        mr_printf("serial set config failed: %s\r\n", mr_strerror(ret));
    }
}
/* 导出到自动初始化（APP级） */
MR_INIT_APP_EXPORT(serial_init);

int main(void)
{
    /* 自动初始化（serial_init函数将在此处自动调用） */
    mr_auto_init();

    while (1)
    {
        /* 回环测试 */
        char buf[64];
        ssize_t ret = mr_dev_read(serial_ds, buf, sizeof(buf));
        mr_dev_write(serial_ds, buf, ret);
    }
}