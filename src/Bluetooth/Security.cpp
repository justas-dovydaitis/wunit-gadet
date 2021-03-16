
#include "Security.h"
#include "State/UnlockedState.h"

bool BTSecurity::onConfirmPIN(uint32_t pin)
{
    return false;
}

uint32_t BTSecurity::onPassKeyRequest()
{
    ESP_LOGI(LOG_TAG, "PassKeyRequest");
    return 123456;
}

void BTSecurity::onPassKeyNotify(uint32_t pass_key)
{
    ESP_LOGI(LOG_TAG, "On passkey Notify number:%d", pass_key);
}

bool BTSecurity::onSecurityRequest()
{
    ESP_LOGI(LOG_TAG, "On Security Request");
    return true;
}

void BTSecurity::onAuthenticationComplete(esp_ble_auth_cmpl_t cmpl)
{
    ESP_LOGI(LOG_TAG, "Starting BLE work!");
    if (cmpl.success)
    {
        uint16_t length;
        esp_ble_gap_get_whitelist_size(&length);
        ESP_LOGD(LOG_TAG, "size: %d", length);

        Serial.println("AUTH_COMPLETE");
        setState(new UnlockedState);
        Serial.println("Connected");
    }
}