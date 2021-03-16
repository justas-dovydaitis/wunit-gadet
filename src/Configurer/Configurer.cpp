#include "Configurer.h"

ConfigData Configurer::getConfig()
{
    if (this->_pConfig == nullptr)
    {
        ConfigData data = readConfig();

        this->_pConfig = &data;
    }
    return *this->_pConfig;
}

ConfigData Configurer::readConfig()
{
    EEPROM.begin(EEPROM_SIZE);

    ConfigData data;

    EEPROM.get(EEPROM_PASSKEY_ADDRESS, data.bluetoothPasskey);
    EEPROM.get(EEPROM_ANGLE_COMPENSATE_ADDRESS, data.angleCompensate);

    if (data.bluetoothPasskey == std::numeric_limits<uint32_t>::max())
    {
        data.bluetoothPasskey = DEFAULT_BLUETOOTH_PASSKEY;
    }

    if (data.angleCompensate == std::numeric_limits<int8_t>::max())
    {
        data.angleCompensate = DEFAULT_ANGLE_COMPENSATE;
    }
    return data;
}