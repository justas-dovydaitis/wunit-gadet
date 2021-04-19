#include "AngleTask.h"
#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"

TaskHandle_t angleTaskHandle = NULL;

void taskUpdateAngleValue(void *param)
{
    String currentAngle;
    for (;;)
    {
        currentAngle = String(getCurrentAngle());
        Serial.println("Angle " + currentAngle);
        pAngleCharacteristic->setValue(currentAngle.c_str());
        pAngleCharacteristic->notify();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}