

#include "AnalogSensor/Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "Config/Config.h"
#include "GSM/GSM.h"
#include "States/InitState.h"
#include "IOConfig/IOConfig.h"
#include "Tasks/Tasks.h"

#include <Arduino.h>

void setup()
{
  Serial.begin(115200);

  setState(new InitState);

  vTaskDelete(NULL);
}
void loop()
{
}
