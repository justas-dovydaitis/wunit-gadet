#ifndef __ANGLE_TASK_H__
#define __ANGLE_TASK_H__

#include <Arduino.h>

extern TaskHandle_t angleTaskHandle;

void taskUpdateAngleValue(void *param);

#endif