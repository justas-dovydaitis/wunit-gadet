#ifndef __IO_CONFIG_H__
#define __IO_CONFIG_H__

#include <Arduino.h>
#include <pcf8574_esp.h>

#define PIN_INPUT_0 0
#define PIN_INPUT_1 2
#define PIN_INPUT_2 4
#define PIN_INPUT_3 8
#define PIN_INPUT_4 16
#define PIN_INPUT_5 32
#define PIN_INPUT_6 64
#define PIN_INPUT_7 128
#define PIN_INPUT_8 256
#define PIN_INPUT_9 512
#define PIN_INPUT_10 1024
#define PIN_INPUT_11 2048
#define PIN_INPUT_12 4096
#define PIN_INPUT_13 8192
#define PIN_INPUT_14 16384
#define PIN_INPUT_15 32768

#define PIN_CONTROL_INTERRUPT 34

typedef uint8_t OutputPin_t;
extern OutputPin_t outputs[];

#define PIN_IIC_SDA 21
#define PIN_IIC_SCL 22


#define PIN_INPUT_SPEED 36
#define PIN_INPUT_TACH 39

extern PCF857x ioExpander;

void setupIO();

#endif