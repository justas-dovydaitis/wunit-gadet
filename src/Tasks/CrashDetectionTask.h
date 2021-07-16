#ifndef __CRASH_DETECTION_TASK_H__
#define __CRASH_DETECTION_TASK_H__

#include <Arduino.h>

extern TaskHandle_t crashDetectionTaskHandle;

void taskCrashDetection(void *param);

#endif