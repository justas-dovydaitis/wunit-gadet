#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "Constants.h"
#include "Templates/Singleton.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include "FS.h"
#include <Preferences.h>

class Config : public Singleton<Config>, private Preferences
{
    friend class Singleton<Config>;

protected:
    Config();
    ~Config();

    void loadConfigFromFile();

    File getConfigFile(const char *mode);

    template <size_t desiredCapacity>
    StaticJsonDocument<desiredCapacity> getConfigJson();

    template <typename T>
    void setValue(StaticJsonDocument<C_CONFIG_JSON_SIZE> json, T &variable, const char *key, T defaultValue);

    static SemaphoreHandle_t _mutex;

public:
    static Config *getInstance();

    void writeConfigToFile(const char *configString);

    uint32_t getPasskey();
    void setPasskey(uint32_t passkey);

    uint16_t getLastState();
    void setLastState(uint16_t state);

    int16_t getAngleCompensate();
    void setAngleCompensate(int16_t compensate);

    uint16_t getLeanAngleBoundary();
    void setLeanAngleBoundary(uint16_t angle);
};

#endif
