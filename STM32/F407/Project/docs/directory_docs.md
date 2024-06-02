```plaintext
├─build
├─docs
├─libs
│   ├─assembly
│   ├─Stm32_lib
├─project
│   ├─cmake
│   ├─eide
│   ├─keil
│   ├─make
├─scripts
├─src
│   ├─config
│   │   │   │   config.c  // 项目配置
│   │   │   │   config.h  // 项目配置
│   ├─drivers
│   │   │   │   gpio.c  // IO驱动
│   │   │   │   gpio.h  // IO驱动
│   │   │   │   hard_i2c.c  // 硬件I2C驱动
│   │   │   │   hard_i2c.h  // 硬件I2C驱动
│   │   │   │   hard_spi.c  // 硬件SPI驱动
│   │   │   │   hard_spi.h  // 硬件SPI驱动
│   │   │   │   soft_i2c.c  // 软件I2C驱动
│   │   │   │   soft_i2c.h  // 软件I2C驱动
│   │   │   │   soft_spi.c  // 软件SPI驱动
│   │   │   │   soft_spi.h  // 软件SPI驱动
│   │   │   │   systick.c  // 滴答定时器驱动
│   │   │   │   systick.h  // 滴答定时器驱动
│   │   │   │   time.c  // 定时器驱动
│   │   │   │   time.h  // 定时器驱动
│   │   │   │   uart.c  // UART驱动
│   │   │   │   uart.h  // UART驱动
│   ├─peripherals
│   ├─protocol
│   │   │   │   modbus_master.c  // MODBUS主机协议
│   │   │   │   modbus_master.h  // MODBUS主机协议
│   │   │   │   modbus_slave.c  // MODBUS从机协议
│   │   │   │   modbus_slave.h  // 
│   │   │   │   xmode.c  // XMODE协议
│   │   │   │   xmode.h  // XMODE协议
│   │   │   │   ymode.c  // YMODE协议
│   │   │   │   ymode.h  // YMODE协议
│   ├─utils
│   │   │   │   buffer.c  // 缓冲区
│   │   │   │   buffer.h  // 缓冲区
│   │   │   │   lib.c  // 常用lib库
│   │   │   │   lib.h  // 常用lib库
│   │   │   │   list.c  // 链表
│   │   │   │   list.h  // 
├─tests
```