
#include "Security.h"
#include "States/UnlockedState.h"

bool SecurityCallbacks::onConfirmPIN(uint32_t pin)
{
    return false;
}

uint32_t SecurityCallbacks::onPassKeyRequest()
{
    ESP_LOGI(LOG_TAG, "PassKeyRequest");
    return 123456;
}

void SecurityCallbacks::onPassKeyNotify(uint32_t pass_key)
{
    ESP_LOGI(LOG_TAG, "On passkey Notify number:%d", pass_key);
}

bool SecurityCallbacks::onSecurityRequest()
{
    ESP_LOGI(LOG_TAG, "On Security Request");
    return true;
}

void SecurityCallbacks::onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl)
{
    ESP_LOGI(LOG_TAG, "Starting BLE work!");
    if (cmpl.success)
    {
        uint16_t length;
        esp_ble_gap_get_whitelist_size(&length);
        ESP_LOGD(LOG_TAG, "size: %d", length);

        Serial.println("AUTH_COMPLETE");
        Bluetooth::getInstance()->setConnected(true);
        setState(new UnlockedState);
        Serial.println("Connected");
    }
}