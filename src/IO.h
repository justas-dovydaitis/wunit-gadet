#ifndef __IO_H__
#define __IO_H__

#include <Arduino.h>
#include <pcf8574_esp.h>

#define PIN_INPUT_LOCK 36       // Latching
#define PIN_INPUT_LIGHT 25      // Latching
#define PIN_INPUT_LEFT_TURN 25  // Latching
#define PIN_INPUT_RIGHT_TURN 35 // Latching
#define PIN_INPUT_KILL 27       // Latching
#define PIN_INPUT_HIGH_BEAM 34  // Latching
#define PIN_INPUT_STARTER 39    // Momentary
#define PIN_INPUT_HORN 32       // Momentary
#define PIN_INPUT_BRAKE 33      // Momentary
#define PIN_INPUT_STAND 26      // Momentary

#define PIN_IIC_SDA 21
#define PIN_IIC_SCL 22

#define PIN_IO_EXPANDER_INTERRUPT 23

#define PIN_OUTPUT_IGNITION 0
#define PIN_OUTPUT_LIGHT 1
#define PIN_OUTPUT_HIGH_BEAM 2
#define PIN_OUTPUT_LEFT_TURN 3
#define PIN_OUTPUT_RIGHT_TURN 4
#define PIN_OUTPUT_STARTER 5
#define PIN_OUTPUT_HORN 6
#define PIN_OUTPUT_BRAKE 7
#define PIN_OUTPUT_AUX1 8
#define PIN_OUTPUT_AUX2 9

extern PCF857x ioExpander;

extern void setupIO();

#endif