#include <Arduino.h>

#include "wunit_bluetooth.h"

#define DEBUG true

#define BT_SERIAL Serial1
#define BT_STATE_PIN 22
#define BT_PWRC_PIN 23

WUnitBluetooth *BT;

void setup()
{
    //Initiate serial for debugging
    if (DEBUG)
    {
        Serial.begin(9600);
    }

    // Bluetooth setup
    BT = new WUnitBluetooth(BT_SERIAL, BT_STATE_PIN, BT_PWRC_PIN, DEBUG);
    BT->setName("WUnit™");
    BT->setPassword("111111");

}
int k = 0;
void loop()
{
    // delay(5000);
    // Serial.println(k += BT->isConnected());

    // if (k >= 2)
    // {
    //     BT->disconnect();
    // }
}
    // // Read from Bluetooth and send to Arduino serial monitor
    // if (BT->isAvailable())
    // {
    //     c = BT->read();
    //     Serial.write(c);
    // }

    // // Read from Arduino Serial Monitor and send to Bluetooth
    // if (Serial.available())
    // {
    //     c = Serial.read();
    //     BT->write(c);
    // }
