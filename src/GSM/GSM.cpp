#include "GSM.h"
#include "Constants.h"

#include <SoftwareSerial.h>

GSM::GSM()
{
    _serial.begin(9600, SWSERIAL_8N1, C_SIM_RX_PIN, C_SIM_TX_PIN);

    _pFona = new Adafruit_FONA(C_SIM_RST_PIN);

    if (!_pFona->begin(_serial))
    {
        Serial.println(F("Couldn't find FONA"));
        while (1)
            ;
    }
}

Adafruit_FONA *GSM::getFona()
{
    return _pFona;
}