#include <Arduino.h>
#include <wunit-bluetooth.h>
#include <wunit-angle.h>

#define ANGLE_PIN 34
#define ANGLE_D1_PIN 39
#define ANGLE_D2_PIN 36

WUnitAngle *angle;

WUnitBluetooth *BLE;

void setup()
{
  angle = new WUnitAngle(ANGLE_PIN, ANGLE_D1_PIN, ANGLE_D2_PIN);

  BLE = new WUnitBluetooth();
}

void loop()
{
    // Test angle;
    delay(1000);

    Serial.print("angle: ");
    Serial.println(angle->getAngle());
}