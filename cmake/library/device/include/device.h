/**
 * @file device.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __DEVICE_H
#define __DEVICE_H

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define DEV_FLAG_INIT                       (0x00000001UL)
#define DEV_FLAG_READY                      (0x00000002UL)
#define DEV_FLAG_OPEN                       (0x00000004UL)
#define DEV_FLAG_CLOSE                      (0x00000008UL)
#define DEV_FLAG_BUSY                       (0x00000010UL)

#define DEV_STATUS_REGISTERED               (0x00000020UL)      
#define DEV_STATUS_INIT_COMPLETED           (0x00000040UL)      


enum device_type
{
    DEV_TYPE_ROOT,
    DEV_TYPE_GPIO,
    DEV_TYPE_I2C,
    DEV_TYPE_SPI,
    DEV_TYPE_UART,
    DEV_TYPE_PWM,
    DEV_TYPE_ADC,
    DEV_TYPE_MAX
};

enum device_bus_type{
    DEV_BUS_I2C,
    DEV_BUS_SPI,
    DEV_BUS_UART,
    DEV_BUS_PWM,
    DEV_BUS_ADC,
    DEV_BUS_GPIO
};

struct sa_list
{
    struct sa_list *next;
    struct sa_list *prev;
};


struct driver_ops
{
    void *ops;  
    void *data; 
};


struct device_bus
{
    enum device_bus_type type;
    void *parent;
    struct sa_list *siblings;     
    struct sa_lsit *children;  
    uint32_t device_count;
};

struct device
{
    const char name[SA_NAME_MAX];  
    enum device_type type;       
    uint32_t flags;               
    void *parent;                 
    struct driver_ops *driver_ops;
    struct device_ops *device_ops;
};

struct device_ops
{
    int (*open)(struct device *dev);
    int (*close)(struct device *dev);
    int (*read)(struct device *dev, void *buf, int count);
    int (*write)(struct device *dev, const void *buf, int count);
    long (*ioctl)(struct device *dev, int cmd, void *arg);
    int (*isr)(struct device *dev, int event, void *args);
};

extern struct device root;

// struct device root = {
//     .name = "root",
//     .type = DEV_TYPE_ROOT,
//     .flags = DEV_FLAG_READY,
//     .parent = NULL,
//     .siblings = NULL,
//     .children = NULL,
//     .driver_ops = NULL,
//     .device_ops = NULL};


#endif // DEVICE_H
