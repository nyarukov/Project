
/*
 * @file device.c
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "./include/device.h"

static struct device *find_device(struct device *dev,const char *path){
    

    //SA_container_of(&gpio.driver_ops,struct device,driver_ops)

}

int sa_register(struct device *dev,
                const char *path,
                enum device_type type,
                int flags,
                struct device_ops *device_ops,
                struct driver_ops *driver_ops)
{
    find_device(dev, path);
    printf("sa_register_init\n");
    return 0;
}
