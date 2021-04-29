#include "Config.h"
#include "Constants.h"

#include <LITTLEFS.h>

const bool C_FORMAT_LITTLEFS_IF_FAILED = true;
const char C_CONFIG_NAMESPACE[] = "device.x";

SemaphoreHandle_t Config::_mutex = xSemaphoreCreateMutex();

File Config::getConfigFile(const char *mode)
{
    File configFile;

    if (!LITTLEFS.begin(C_FORMAT_LITTLEFS_IF_FAILED))
    {
        Serial.println("LITTLEFS Mount Failed");
    }

    configFile = LITTLEFS.open("/config.json", mode);
    if (!configFile || configFile.isDirectory())
    {
        Serial.println("- failed to open file for reading");
    }

    return configFile;
}

template <size_t desiredCapacity>
StaticJsonDocument<desiredCapacity> Config::getConfigJson()
{
    File configFile = getConfigFile(FILE_READ);

    size_t const configSize = configFile.size();
    std::unique_ptr<char[]> buf(new char[configSize]);
    configFile.readBytes(buf.get(), configSize);

    StaticJsonDocument<C_CONFIG_JSON_SIZE> json;
    auto error = deserializeJson(json, buf.get());

    if (error)
    {
        Serial.println("Failed to parse config file");
    }
    return json;
}
template <typename T>
void Config::setValue(StaticJsonDocument<C_CONFIG_JSON_SIZE> json, T &variable, const char *key, T defaultValue)
{
    variable = json.containsKey(key) ? json[key].as<T>() : defaultValue;
}

void Config::loadConfigFromFile()
{
    StaticJsonDocument<C_CONFIG_JSON_SIZE> json = getConfigJson<C_CONFIG_JSON_SIZE>();

    // setValue<String>(json, _configData.phoneNumber, "phone", "");
    // setValue<String>(json, _configData.proxyPhoneNumber, "proxyPhone", "");
    // setValue<uint16_t>(json, _configData.speedUpdateInterval, "speedInterval", C_DEFAULT_SPEED_UPDATE_INTERVAL);
    // setValue<uint16_t>(json, _configData.tachUpdateInterval, "tachInterval", C_DEFAULT_TACH_UPDATE_INTERVAL);
    // setValue<uint16_t>(json, _configData.odometerUpdateInterval, "odoInterval", C_DEFAULT_ODOMETER_UPDATE_INTERVAL);
    // setValue<uint>(json, _configData.panicLevelAlarmDuration, "highAlarmDuration", C_DEFAULT_PANIC_LEVEL_ALARM_DURATION);
    // setValue<uint>(json, _configData.mediumLevelAlarmDuration, "mediumAlarmDuration", C_DEFAULT_MEDIUM_LEVEL_ALARM_DURATION);
    // setValue<uint>(json, _configData.lowLevelAlarmDuration, "lowAlarmDuration", C_DEFAULT_LOW_LEVEL_ALARM_DURATION);
    // setValue<bool>(json, _configData.callOnPanicLevelAlarm, "callOnHighAlarm", C_DEFAULT_CALL_ON_PANIC_LEVEL_ALARM);
    // setValue<bool>(json, _configData.callOnMediumLevelAlarm, "callOnMediumAlarm", C_DEFAULT_CALL_ON_MEDIUM_LEVEL_ALARM);
    // setValue<bool>(json, _configData.callOnLowLevelAlarm, "callOnLowAlarm", C_DEFAULT_CALL_ON_LOW_LEVEL_ALARM);
    // setValue<bool>(json, _configData.smsOnPanicLevelAlarm, "smsOnHighAlarm", C_DEFAULT_SMS_ON_PANIC_LEVEL_ALARM);
    // setValue<bool>(json, _configData.smsOnMediumLevelAlarm, "smsOnMediumAlarm", C_DEFAULT_SMS_ON_MEDIUM_LEVEL_ALARM);
    // setValue<bool>(json, _configData.smsOnLowLevelAlarm, "smsOnLowAlarm", C_DEFAULT_SMS_ON_LOW_LEVEL_ALARM);
    // setValue<uint16_t>(json, _configData.blinkersTimeToRest, "blinkersRest", C_DEFAULT_BLINKERS_TIME_OFF);
    // setValue<uint16_t>(json, _configData.blinkersTimeToShine, "blinkersShine", C_DEFAULT_BLINKERS_TIME_ON);
    // setValue<bool>(json, _configData.killOnFall, "killOnFall", C_DEFAULT_KILL_ON_FALL);
    // setValue<bool>(json, _configData.smsOnFall, "smsOnFall", C_DEFAULT_SMS_PROXY_ON_FALL);
    // setValue<int8_t>(json, _configData.angleCompensate, "angleCompensate", C_DEFAULT_ANGLE_COMPENSATE);
    // setValue<uint16_t>(json, _configData.angleUpdateInterval, "angleInterval", C_DEFAULT_ANGLE_UPDATE_INTERVAL);
    // setValue<uint8_t>(json, _configData.maxLeanAngle, "maxAngle", C_DEFAULT_MAX_LEAN_ANGLE);

    // _configData.phoneNumber = json.containsKey("phone") ? json["phone"].as<String>() : "";
    // _configData.proxyPhoneNumber = json.containsKey("proxyPhone") ? json["proxyPhone"].as<String>() : "";

    // _configData.speedUpdateInterval = json.containsKey("speedInterval") ? json["speedInterval"].as<uint16_t>() : C_DEFAULT_SPEED_UPDATE_INTERVAL;
    // _configData.tachUpdateInterval = json.containsKey("tachInterval") ? json["tachInterval"].as<uint16_t>() : C_DEFAULT_TACH_UPDATE_INTERVAL;
    // _configData.odometerUpdateInterval = json.containsKey("odoInterval") ? json["odoInterval"].as<uint16_t>() : C_DEFAULT_ODOMETER_UPDATE_INTERVAL;

    // _configData.panicLevelAlarmDuration = json.containsKey("highAlarmDuration") ? json["highAlarmDuration"].as<uint>() : C_DEFAULT_PANIC_LEVEL_ALARM_DURATION;
    // _configData.mediumLevelAlarmDuration = json.containsKey("mediumAlarmDuration") ? json["mediumAlarmDuration"].as<uint>() : C_DEFAULT_MEDIUM_LEVEL_ALARM_DURATION;
    // _configData.lowLevelAlarmDuration = json.containsKey("lowAlarmDuration") ? json["lowAlarmDuration"].as<uint>() : C_DEFAULT_LOW_LEVEL_ALARM_DURATION;

    // _configData.callOnPanicLevelAlarm = json.containsKey("callOnHighAlarm") ? json["callOnHighAlarm"].as<bool>() : C_DEFAULT_CALL_ON_PANIC_LEVEL_ALARM;
    // _configData.callOnMediumLevelAlarm = json.containsKey("callOnMediumAlarm") ? json["callOnMediumAlarm"].as<bool>() : C_DEFAULT_CALL_ON_MEDIUM_LEVEL_ALARM;
    // _configData.callOnLowLevelAlarm = json.containsKey("callOnLowAlarm") ? json["callOnLowAlarm"].as<bool>() : C_DEFAULT_CALL_ON_LOW_LEVEL_ALARM;

    // _configData.smsOnPanicLevelAlarm = json.containsKey("smsOnHighAlarm") ? json["smsOnHighAlarm"].as<bool>() : C_DEFAULT_SMS_ON_PANIC_LEVEL_ALARM;
    // _configData.smsOnMediumLevelAlarm = json.containsKey("smsOnMediumAlarm") ? json["smsOnMediumAlarm"].as<bool>() : C_DEFAULT_SMS_ON_MEDIUM_LEVEL_ALARM;
    // _configData.smsOnLowLevelAlarm = json.containsKey("smsOnLowAlarm") ? json["smsOnLowAlarm"].as<bool>() : C_DEFAULT_SMS_ON_LOW_LEVEL_ALARM;

    // _configData.blinkersTimeToRest = json.containsKey("blinkersRest") ? json["blinkersRest"].as<uint16_t>() : C_DEFAULT_BLINKERS_TIME_OFF;
    // _configData.blinkersTimeToShine = json.containsKey("blinkersShine") ? json["blinkersShine"].as<uint16_t>() : C_DEFAULT_BLINKERS_TIME_ON;

    // _configData.killOnFall = json.containsKey("killOnFall") ? json["killOnFall"].as<bool>() : C_DEFAULT_KILL_ON_FALL;
    // _configData.smsOnFall = json.containsKey("smsOnFall") ? json["smsOnFall"].as<bool>() : C_DEFAULT_SMS_PROXY_ON_FALL;

    // _configData.angleCompensate = json.containsKey("angleCompensate") ? json["angleCompensate"].as<int8_t>() : C_DEFAULT_ANGLE_COMPENSATE;
    // _configData.angleUpdateInterval = json.containsKey("angleInterval") ? json["angleInterval"].as<uint16_t>() : C_DEFAULT_ANGLE_UPDATE_INTERVAL;
    // _configData.maxLeanAngle = json.containsKey("maxAngle") ? json["maxAngle"].as<uint8_t>() : C_DEFAULT_MAX_LEAN_ANGLE;
}

void Config::writeConfigToFile(const char *config)
{
    File configFile = getConfigFile(FILE_WRITE);
    configFile.print(config);
    configFile.close();
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

Config::Config()
{
    this->begin(C_CONFIG_NAMESPACE);
}

Config::~Config()
{
    this->end();
}

uint32_t Config::getPasskey()
{
    return this->getUInt("passkey");
}

void Config::setPasskey(uint32_t passkey)
{
    this->putUInt("passkey", passkey);
}

uint16_t Config::getLastState()
{
    return this->getUShort("lastState");
}

void Config::setLastState(uint16_t state)
{
    this->putUShort("lastState", state);
}

int16_t Config::getAngleCompensate()
{
    return this->getUShort("angleCompensate");
}

void Config::setAngleCompensate(int16_t compensate)
{
    this->putUShort("angleCompensate", compensate);
}

uint16_t Config::getLeanAngleBoundary()
{
    return this->getUShort("leanAngleBoundary");
}

void Config::setLeanAngleBoundary(uint16_t angle)
{
    this->putUShort("leanAngleBoundary", angle);
}