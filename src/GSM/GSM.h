#ifndef __GSM_H__
#define __GSM_H__

#include "Templates/Singleton.h"

#include <SoftwareSerial.h>
#include <Adafruit_FONA.h>

class GSM : public Singleton<GSM>
{
    friend class Singleton<GSM>;

protected:
    GSM();

    char _replyBuffer[255];
    SoftwareSerial _serial;
    Adafruit_FONA *_pFona;

public:
    Adafruit_FONA *getFona();
};

#endif