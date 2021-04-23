#include "Bluetooth.h"
#include "Callbacks.h"
#include "Constants.h"
#include "Security.h"

#include <Preferences.h>

Preferences preferences;

uint32_t bluetoothPasskey = C_DEFAULT_BLUETOOTH_PASSKEY;

BLEServer *pBLEServer = nullptr;
BLEAdvertising *pBLEAdvertising = nullptr;

BLEService *pConfigService = nullptr;
BLEService *pDashboardService = nullptr;
BLEService *pControlService = nullptr;

BLECharacteristic *pAngleCharacteristic = nullptr;
BLECharacteristic *pSpeedometerCharacteristic = nullptr;
BLECharacteristic *pTachometerCharacteristic = nullptr;
BLECharacteristic *pOdometerCharacteristic = nullptr;
BLECharacteristic *pGadgetsCharacteristic = nullptr;

BLECharacteristic *pControlCharacteristic = nullptr;

BLECharacteristic *pConfigCharacteristic = nullptr;
BLECharacteristic *pPasswordCharacteristic = nullptr;

void setupBLESecurity()
{

    preferences.begin("wunit");
    bluetoothPasskey = preferences.getUInt("passkey", C_DEFAULT_BLUETOOTH_PASSKEY);
    preferences.end();

    esp_ble_auth_req_t auth_req = ESP_LE_AUTH_REQ_SC_MITM_BOND;
    esp_ble_io_cap_t iocap = ESP_IO_CAP_OUT;
    uint8_t key_size = 16;
    uint8_t init_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;
    uint8_t rsp_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;

    uint8_t auth_option = ESP_BLE_ONLY_ACCEPT_SPECIFIED_AUTH_DISABLE;
    uint8_t oob_support = ESP_BLE_OOB_DISABLE;

    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &bluetoothPasskey, sizeof(uint32_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_AUTHEN_REQ_MODE, &auth_req, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_IOCAP_MODE, &iocap, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_MAX_KEY_SIZE, &key_size, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_ONLY_ACCEPT_SPECIFIED_SEC_AUTH, &auth_option, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_OOB_SUPPORT, &oob_support, sizeof(uint8_t));

    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_INIT_KEY, &init_key, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_RSP_KEY, &rsp_key, sizeof(uint8_t));
}

void setupBLEServices()
{
    pDashboardService = pBLEServer->createService(C_DASHBOARD_SERVICE_UUID);
    pControlService = pBLEServer->createService(C_CONTROL_SERVICE_UUID);

    pConfigService = pBLEServer->createService(C_CONFIG_SERVICE_UUID);
}

void setupBLECharacteristics()
{
    /**
     *  Dashboard service characteristics.
     */
    pAngleCharacteristic = pDashboardService->createCharacteristic(C_ANGLE_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    pAngleCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    pSpeedometerCharacteristic = pDashboardService->createCharacteristic(C_SPEEDOMETER_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    pSpeedometerCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    pTachometerCharacteristic = pDashboardService->createCharacteristic(C_TACHOMETER_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    pTachometerCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    pOdometerCharacteristic = pDashboardService->createCharacteristic(C_ODOMETER_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    pOdometerCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    pGadgetsCharacteristic = pDashboardService->createCharacteristic(C_GADGETS_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    pGadgetsCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    /**
     *  Control service characteristics.
     */
    pControlCharacteristic = pControlService->createCharacteristic(C_CONTROL_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);

    /**
     *  Config service characteristics.
     */
    pPasswordCharacteristic = pConfigService->createCharacteristic(C_PASSKEY_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);
    pPasswordCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    pPasswordCharacteristic->setCallbacks(new PasswordCallbacks());

    pConfigCharacteristic = pConfigService->createCharacteristic(C_CONFIG_SERVICE_UUID, BLECharacteristic::PROPERTY_WRITE);
    pConfigCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    pConfigCharacteristic->setCallbacks(new ConfigCallbacks());
}

void setupBLE()
{
    BLEDevice::init("WUnit™");
    BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT);
    BLEDevice::setSecurityCallbacks(new BTSecurity());

    pBLEServer = BLEDevice::createServer();
    pBLEServer->setCallbacks(new ServerCallbacks());

    setupBLEServices();
    setupBLECharacteristics();

    pBLEAdvertising = pBLEServer->getAdvertising();
    pBLEAdvertising->start();

    setupBLESecurity();
}