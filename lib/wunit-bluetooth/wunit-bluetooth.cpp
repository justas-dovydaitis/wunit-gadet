#include <wunit-bluetooth.h>

esp_ble_sm_param_t ESP_BLE_SM_OOB_SUPPORT = (esp_ble_sm_param_t)10;

WUnitBluetooth::WUnitBluetooth()
{
    BLEDevice::init("WUnit™");
    BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT);
    BLEDevice::setSecurityCallbacks(new BTSecurity());

    pServer = BLEDevice::createServer();

    registerServicesAndCharacteristics();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();

    configureSecurity();
}

void WUnitBluetooth::registerServicesAndCharacteristics()
{
    /**
     * Control service
     */
    BLEService *pService = pServer->createService(CONTROL_SERVICE_UUID);

    //Password characteristic
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(PASSKEY_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);
    pCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENCRYPTED);
    pCharacteristic->setCallbacks(new PasswordCallbacks());

    pService->start();
}
void WUnitBluetooth::configureSecurity()
{
    uint32_t passkey = DEFAULT_PASSKEY;
    
    esp_ble_auth_req_t auth_req = ESP_LE_AUTH_REQ_SC_MITM_BOND;
    esp_ble_io_cap_t iocap = ESP_IO_CAP_OUT;
    uint8_t key_size = 16;
    uint8_t init_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;
    uint8_t rsp_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;

    
    uint8_t auth_option = ESP_BLE_ONLY_ACCEPT_SPECIFIED_AUTH_DISABLE;
    uint8_t oob_support = ESP_BLE_OOB_DISABLE;

    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &passkey, sizeof(uint32_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_AUTHEN_REQ_MODE, &auth_req, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_IOCAP_MODE, &iocap, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_MAX_KEY_SIZE, &key_size, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_ONLY_ACCEPT_SPECIFIED_SEC_AUTH, &auth_option, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_OOB_SUPPORT, &oob_support, sizeof(uint8_t));

    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_INIT_KEY, &init_key, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_RSP_KEY, &rsp_key, sizeof(uint8_t));
}