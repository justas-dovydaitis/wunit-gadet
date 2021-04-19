#ifndef __ODOMETER_TASK_H__
#define __ODOMETER_TASK_H__

#include <Arduino.h>

extern TaskHandle_t odometerTaskHandle;

void taskUpdateOdometerValue(void *param);

#endif
