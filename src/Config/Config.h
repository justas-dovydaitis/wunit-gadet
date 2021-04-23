#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FreeRTOS.h>

#include "Constants.h"
#include "Controls/AbstractButton.h"

class Config
{
protected:
    uint32_t _bluetoothPasskey;

    int8_t _angleCompensate;
    uint16_t _angleUpdateInterval;
    uint8_t _maxLeanAngle;
    bool _killOnFall;
    bool _smsOnFall;
    uint16_t _blinkersTimeToShine;
    uint16_t _blinkersTimeToRest;
    uint _lowLevelAlarmDuration;
    bool _smsOnLowLevelAlarm;
    bool _callOnLowLevelAlarm;
    uint _mediumLevelAlarmDuration;
    bool _smsOnMediumLevelAlarm;
    bool _callOnMediumLevelAlarm;
    uint _panicLevelAlarmDuration;
    bool _smsOnPanicLevelAlarm;
    bool _callOnPanicLevelAlarm;

    uint16_t _speedUpdateInterval;
    uint16_t _tachUpdateInterval;
    uint16_t _odometerUpdateInterval;

    uint8_t _controlsCount = 0;
    AbstractButton *_controls[16];

    const char *_phoneNumber = nullptr;
    const char *_proxyPhoneNumber = nullptr;

private:
    static Config *_pInstance;
    static SemaphoreHandle_t _mutex;

    Config();
    void loadConfigFromFile();
    template <size_t desiredCapacity>
    StaticJsonDocument<desiredCapacity> getConfigJson();

public:
    Config(Config &otherConfig) = delete;
    void operator=(const Config &) = delete;

    static Config *getInstance();

    void setConfig(const char *configString);
    void getConfig();

    uint8_t angleCompensate();
};

#endif