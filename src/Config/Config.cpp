#include "Config.h"
#include "Constants.h"
#include <SPIFFS.h>

Config *Config::_pInstance = nullptr;
SemaphoreHandle_t Config::_mutex = xSemaphoreCreateMutex();

template <size_t desiredCapacity>
StaticJsonDocument<desiredCapacity> Config::getConfigJson()
{
    SPIFFS.begin();

    File file = SPIFFS.open("/config.json", FILE_READ);

    StaticJsonDocument<C_CONFIG_JSON_SIZE> json;

    /*DeserializationError error =*/deserializeJson(json, file);
    file.close();

    return json;
}
void Config::loadConfigFromFile()
{
    StaticJsonDocument<C_CONFIG_JSON_SIZE> json = getConfigJson<C_CONFIG_JSON_SIZE>();

    _phoneNumber = json.containsKey("phone") ? json["phone"].as<char *>() : "";
    _proxyPhoneNumber = json.containsKey("proxyPhone") ? json["proxyPhone"].as<char *>() : "";

    _speedUpdateInterval = json.containsKey("speedInterval") ? json["speedInterval"].as<uint16_t>() : C_DEFAULT_SPEED_UPDATE_INTERVAL;
    _tachUpdateInterval = json.containsKey("tachInterval") ? json["tachInterval"].as<uint16_t>() : C_DEFAULT_TACH_UPDATE_INTERVAL;
    _odometerUpdateInterval = json.containsKey("odoInterval") ? json["odoInterval"].as<uint16_t>() : C_DEFAULT_ODOMETER_UPDATE_INTERVAL;

    _panicLevelAlarmDuration = json.containsKey("highAlarmDuration") ? json["highAlarmDuration"].as<uint>() : C_DEFAULT_PANIC_LEVEL_ALARM_DURATION;
    _mediumLevelAlarmDuration = json.containsKey("mediumAlarmDuration") ? json["mediumAlarmDuration"].as<uint>() : C_DEFAULT_MEDIUM_LEVEL_ALARM_DURATION;
    _lowLevelAlarmDuration = json.containsKey("lowAlarmDuration") ? json["lowAlarmDuration"].as<uint>() : C_DEFAULT_LOW_LEVEL_ALARM_DURATION;

    _callOnPanicLevelAlarm = json.containsKey("callOnHighAlarm") ? json["callOnHighAlarm"].as<bool>() : C_DEFAULT_CALL_ON_PANIC_LEVEL_ALARM;
    _callOnMediumLevelAlarm = json.containsKey("callOnMediumAlarm") ? json["callOnMediumAlarm"].as<bool>() : C_DEFAULT_CALL_ON_MEDIUM_LEVEL_ALARM;
    _callOnLowLevelAlarm = json.containsKey("callOnLowAlarm") ? json["callOnLowAlarm"].as<bool>() : C_DEFAULT_CALL_ON_LOW_LEVEL_ALARM;

    _smsOnPanicLevelAlarm = json.containsKey("smsOnHighAlarm") ? json["smsOnHighAlarm"].as<bool>() : C_DEFAULT_SMS_ON_PANIC_LEVEL_ALARM;
    _smsOnMediumLevelAlarm = json.containsKey("smsOnMediumAlarm") ? json["smsOnMediumAlarm"].as<bool>() : C_DEFAULT_SMS_ON_MEDIUM_LEVEL_ALARM;
    _smsOnLowLevelAlarm = json.containsKey("smsOnLowAlarm") ? json["smsOnLowAlarm"].as<bool>() : C_DEFAULT_SMS_ON_LOW_LEVEL_ALARM;

    _blinkersTimeToRest = json.containsKey("blinkersRest") ? json["blinkersRest"].as<uint16_t>() : C_DEFAULT_BLINKERS_TIME_OFF;
    _blinkersTimeToShine = json.containsKey("blinkersShine") ? json["blinkersShine"].as<uint16_t>() : C_DEFAULT_BLINKERS_TIME_ON;

    _killOnFall = json.containsKey("killOnFall") ? json["killOnFall"].as<bool>() : C_DEFAULT_KILL_ON_FALL;
    _smsOnFall = json.containsKey("smsOnFall") ? json["smsOnFall"].as<bool>() : C_DEFAULT_SMS_PROXY_ON_FALL;

    _angleCompensate = json.containsKey("angleCompensate") ? json["angleCompensate"].as<int8_t>() : C_DEFAULT_ANGLE_COMPENSATE;
    _angleUpdateInterval = json.containsKey("angleInterval") ? json["angleInterval"].as<uint16_t>() : C_DEFAULT_ANGLE_UPDATE_INTERVAL;
    _maxLeanAngle = json.containsKey("maxAngle") ? json["maxAngle"].as<uint8_t>() : C_DEFAULT_MAX_LEAN_ANGLE;
}

Config *Config::getInstance()
{
    xSemaphoreTake(_mutex, portMAX_DELAY);
    if (_pInstance == nullptr)
    {
        _pInstance = new Config();
    }
    xSemaphoreGive(_mutex);
    return _pInstance;
}

uint8_t Config::angleCompensate()
{
    return _angleCompensate;
}

Config::Config() {}