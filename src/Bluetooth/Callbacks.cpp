#include "Callbacks.h"
#include "Commands/Command.h"
#include "States/LockedState.h"

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <esp_ota_ops.h>
#include <Preferences.h>
#include <Update.h>

void ServerCallbacks::onConnect(BLEServer *pServer)
{
}
void ServerCallbacks::onConnect(BLEServer *pServer, esp_ble_gatts_cb_param_t *param)
{
}
void ServerCallbacks::onDisconnect(BLEServer *pServer)
{
    Serial.println("Disconnected");

    Bluetooth::getInstance()->setConnected(false);
    setState(new LockedState);
    pServer->startAdvertising();
}

void PasswordCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    String newPasskeyValue = pCharacteristic->getValue().c_str();

    if (newPasskeyValue.length() == 6)
    {
        uint32_t newPasskey = atoi(newPasskeyValue.c_str());

        Preferences preferences;
        preferences.begin("wunit");
        preferences.putUInt("passkey", newPasskey);
        preferences.end();

        esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &newPasskey, sizeof(uint32_t));
    }
    pCharacteristic->setValue("OK");
}

void ConfigCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    //     size_t const configSize = configFile.size();
    // std::unique_ptr<char[]> buf(new char[configSize]);
    // configFile.readBytes(buf.get(), configSize);
}
void ControlCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    std::string value = pCharacteristic->getValue();

    int valueStart = 0;
    int valueEnd = value.find_first_of(',');
    uint command = atoi(value.substr(valueStart, valueEnd).c_str());

    valueStart = valueEnd + 1;

    std::string paramsString = value.substr(valueStart);

    CommandInterface *pCommand = createCommand(command, paramsString);
    pCommand->execute();
}

#define FULL_PACKET 512
#define CHARPOS_UPDATE_FLAG 5

esp_ota_handle_t otaHandler = 0;

bool updateFlag = false;
bool readyFlag = false;
int bytesReceived = 0;
int timesWritten = 0;

OTAUpdateCallbacks::OTAUpdateCallbacks(Bluetooth *pBluetooth)
{
    _pBluetooth = pBluetooth;
}

void OTAUpdateCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    std::string rxData = pCharacteristic->getValue();
    if (!updateFlag)
    { //If it's the first packet of OTA since bootup, begin OTA
        Serial.println("BeginOTA");
        esp_ota_begin(esp_ota_get_next_update_partition(NULL), OTA_SIZE_UNKNOWN, &otaHandler);
        updateFlag = true;
    }
    if (_pBluetooth != NULL)
    {
        if (rxData.length() > 0)
        {
            esp_ota_write(otaHandler, rxData.c_str(), rxData.length());
            if (rxData.length() != FULL_PACKET)
            {
                esp_ota_end(otaHandler);
                Serial.println("EndOTA");
                if (ESP_OK == esp_ota_set_boot_partition(esp_ota_get_next_update_partition(NULL)))
                {
                    esp_restart();
                }
                else
                {
                    Serial.println("Upload Error");
                }
            }
        }
    }

    uint8_t txData[5] = {1, 2, 3, 4, 5};
    //delay(1000);
    pCharacteristic->setValue((uint8_t *)txData, 5);
    pCharacteristic->notify();
}