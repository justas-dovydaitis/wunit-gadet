#include <Arduino.h>

#include "Angle/Angle.h"
#include "Bluetooth/Bluetooth.h"
#include "State/LockedState.h"

#include "IO.h"

#include "Tasks/Tasks.h"


void setup()
{
  Serial.begin(115200);
  setState(new LockedState);

  setupBLE();
  setupAngle();
  initializeTasks();
  setupIO();
}
void loop()
{
}
