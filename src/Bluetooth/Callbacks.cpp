#include "Callbacks.h"
#include "States/LockedState.h"


void ServerCallbacks::onConnect(BLEServer *pServer)
{

}
void ServerCallbacks::onConnect(BLEServer *pServer, esp_ble_gatts_cb_param_t *param)
{

}
void ServerCallbacks::onDisconnect(BLEServer *pServer)
{
    setState(new LockedState);
    Serial.println("Disconnected");
    pServer->startAdvertising();
}

void PasswordCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    String newPasskeyValue = pCharacteristic->getValue().c_str();

    if (newPasskeyValue.length() == 6)
    {
        uint32_t newPasskey = atoi(newPasskeyValue.c_str());
        EEPROM.writeUInt(EEPROM_PASSKEY_ADDRESS, newPasskey);

        esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &newPasskey, sizeof(uint32_t));
    }
    pCharacteristic->setValue("OK");
}