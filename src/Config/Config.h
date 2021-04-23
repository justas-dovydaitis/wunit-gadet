#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "ConfigData.h"
#include "Constants.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FreeRTOS.h>
#include "FS.h"

class Config
{
protected:
    ConfigData _configData;

private:
    static Config *_pInstance;
    static SemaphoreHandle_t _mutex;

    Config();
    void loadConfigFromFile();

    File getConfigFile(const char *mode);

    template <size_t desiredCapacity>
    StaticJsonDocument<desiredCapacity> getConfigJson();

    template <typename T>
    void setValue(StaticJsonDocument<C_CONFIG_JSON_SIZE> json, T &variable, const char *key, T defaultValue);

public:
    Config(Config &otherConfig) = delete;
    void operator=(const Config &) = delete;

    static Config *getInstance();

    void writeConfigToFile(const char *configString);
    ConfigData getConfig();
};

#endif
