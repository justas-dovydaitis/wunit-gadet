#ifndef __CONFIG_DATA_H__
#define __CONFIG_DATA_H__

#include "Controls/AbstractButton.h"

#include <Arduino.h>

struct ConfigData
{
    int8_t angleCompensate;
    uint16_t angleUpdateInterval;
    uint8_t maxLeanAngle;
    bool killOnFall;
    bool smsOnFall;
    uint16_t blinkersTimeToShine;
    uint16_t blinkersTimeToRest;
    uint lowLevelAlarmDuration;
    bool smsOnLowLevelAlarm;
    bool callOnLowLevelAlarm;
    uint mediumLevelAlarmDuration;
    bool smsOnMediumLevelAlarm;
    bool callOnMediumLevelAlarm;
    uint panicLevelAlarmDuration;
    bool smsOnPanicLevelAlarm;
    bool callOnPanicLevelAlarm;

    uint16_t speedUpdateInterval;
    uint16_t tachUpdateInterval;
    uint16_t odometerUpdateInterval;

    uint8_t controlsCount;
    AbstractButton *controls[];

    String phoneNumber;
    String proxyPhoneNumber;
};

#endif