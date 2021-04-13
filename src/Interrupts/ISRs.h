#ifndef __ISRS_H__
#define __ISRS_H__

#include <Arduino.h>

extern void IRAM_ATTR ISRLeftTurn();
extern void IRAM_ATTR ISRRightTurn();

#endif