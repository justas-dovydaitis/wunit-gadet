#include "Bluetooth.h"
#include "Callbacks.h"
#include "Constants.h"
#include "Security.h"

#include <BLE2902.h>
#include <Preferences.h>

void Bluetooth::setupBLESecurity()
{
    Preferences preferences;
    preferences.begin("wunit");
    uint32_t bluetoothPasskey = preferences.getUInt("passkey", C_DEFAULT_BLUETOOTH_PASSKEY);
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

void Bluetooth::setupBLEServices()
{
    _pDashboardService = _pBLEServer->createService(C_DASHBOARD_SERVICE_UUID);
    _pControlService = _pBLEServer->createService(C_CONTROL_SERVICE_UUID);
    _pConfigService = _pBLEServer->createService(C_CONFIG_SERVICE_UUID);
}

void Bluetooth::setupBLECharacteristics()
{
    /**
     *  Dashboard service characteristics.
     */
    _pDashboardCharacteristic = _pDashboardService->createCharacteristic(C_DASHBOARD_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    _pDashboardCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    _pGadgetsCharacteristic = _pDashboardService->createCharacteristic(C_GADGETS_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    _pGadgetsCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    /**
     *  Control service characteristics.
     */
    _pControlCharacteristic = _pControlService->createCharacteristic(C_CONTROL_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);
    _pControlCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    _pControlCharacteristic->setCallbacks(new ControlCallbacks());
    /**
     *  Config service characteristics.
     */
    _pPasswordCharacteristic = _pConfigService->createCharacteristic(C_PASSKEY_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);
    _pPasswordCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    _pPasswordCharacteristic->setCallbacks(new PasswordCallbacks());

    _pConfigCharacteristic = _pConfigService->createCharacteristic(C_CONFIG_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE);
    _pConfigCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    _pConfigCharacteristic->setCallbacks(new ConfigCallbacks());

    _pOTAIdCharacteristic = _pConfigService->createCharacteristic(C_OTA_ID_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ);
    _pOTAIdCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);

    _pVersionCharacteristic = _pConfigService->createCharacteristic(C_VERSION_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ);
    _pVersionCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENC_MITM);
    char buff[28];
    sprintf(buff, "%s,%s", DEVICE_SOFTWARE_VERSION, DEVICE_HARDWARE_VERSION);
    _pVersionCharacteristic->setValue(buff);

    _pUpdateCharacteristic = _pConfigService->createCharacteristic(C_UPDATE_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_WRITE);
    _pUpdateCharacteristic->setAccessPermissions(ESP_GATT_PERM_WRITE_ENC_MITM);
    _pUpdateCharacteristic->addDescriptor(new BLE2902());
    _pUpdateCharacteristic->setCallbacks(new OTAUpdateCallbacks(this));
}

Bluetooth::Bluetooth()
{
    BLEDevice::init("WUnit™");
    BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT);
    BLEDevice::setSecurityCallbacks(new SecurityCallbacks());

    _pBLEServer = BLEDevice::createServer();
    _pBLEServer->setCallbacks(new ServerCallbacks());

    setupBLEServices();
    setupBLECharacteristics();

    _pDashboardService->start();
    _pControlService->start();
    _pConfigService->start();

    _pBLEAdvertising = _pBLEServer->getAdvertising();
    _pBLEAdvertising->start();

    setupBLESecurity();
}

BLEAdvertising *Bluetooth::getAdvertising()
{
    return _pBLEAdvertising;
}

BLEService *Bluetooth::getConfigService()
{
    return _pConfigService;
}

BLEService *Bluetooth::getDashboardService()
{
    return _pDashboardService;
}

BLEService *Bluetooth::getControlService()
{
    return _pControlService;
}

BLECharacteristic *Bluetooth::getDashboardCharacteristic()
{
    return _pDashboardCharacteristic;
}

BLECharacteristic *Bluetooth::getGadgetCharacteristic()
{
    return _pGadgetsCharacteristic;
}

bool Bluetooth::isConnected()
{
    return _isConnected;
}

void Bluetooth::setConnected(bool connected)
{
    _isConnected = connected;
}