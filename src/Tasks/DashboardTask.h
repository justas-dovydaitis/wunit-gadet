#ifndef __DASHBOARD_TASK_H__
#define __DASHBOARD_TASL_H__

#include <Arduino.h>

extern TaskHandle_t dashboardTaskHandle;

void taskUpdateDashboard(void *param);

#endif