#include <Arduino.h>

#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "States/LockedState.h"

#include "IOConfig/IOConfig.h"

#include "Tasks/Tasks.h"
void LongPress()
{

  Serial.println("LongPress");
}
void Click()
{

  Serial.println("Click");
}
void DoubleClick()
{
  Serial.println("Double Click");
}
void WhileStart()
{
  Serial.println("Press started");
}
void During()
{
  Serial.println(" now Presing");
}
void WhileStop()
{
  Serial.println("Press stoped");
}

void setup()
{
  Serial.begin(115200);
  setupIO();
  setupBLE();
  setupAngle();
  setState(new LockedState);

  controls[0].attachPress(Click);
  controls[0].attachDoublePress(DoubleClick);
  controls[0].attachDuringLongPress(During);
  controls[0].attachLongPressStart(WhileStart);
  controls[0].attachLongPressStop(WhileStop);

  vTaskDelete(NULL);
}
void loop()
{
}
