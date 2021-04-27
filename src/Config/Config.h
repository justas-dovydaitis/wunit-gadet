#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "ConfigData.h"
#include "Constants.h"
#include "Templates/Singleton.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include "FS.h"

class Config : public Singleton<Config>
{
    friend class Singleton<Config>;

protected:
    ConfigData _configData;
    static SemaphoreHandle_t _mutex;

private:
    Config();

    static Config *getInstance();

    void loadConfigFromFile();

    File getConfigFile(const char *mode);

    template <size_t desiredCapacity>
    StaticJsonDocument<desiredCapacity> getConfigJson();

    template <typename T>
    void setValue(StaticJsonDocument<C_CONFIG_JSON_SIZE> json, T &variable, const char *key, T defaultValue);

public:
    void writeConfigToFile(const char *configString);
    ConfigData getConfig();
};

#endif
