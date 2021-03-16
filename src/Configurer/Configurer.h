#ifndef __CONFIGURER_H__
#define __CONFIGURER_H__

#include <Arduino.h>
#include <EEPROM.h>

#include "ConfigData.h"
#include "DefaultConfig.h"
#include "EEPROMConstants.h"

class Configurer
{
private:
    ConfigData *_pConfig;

    ConfigData readConfig();
    void fallBackToDefault();

public:
    ConfigData getConfig();
    void writeConfig(ConfigData data);
};

#endif