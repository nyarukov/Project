#ifndef _API_H
#define _API_H

#include "device.h"

int sa_register(struct device *dev,
                const char *path,
                enum device_type type,
                int flags,
                struct device_ops *device_ops,
                struct driver_ops *driver_ops);



#endif // !_API_H