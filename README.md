# WUnit™ Gadget

## About

WUnit® Gadget is a cheap Arduino based gadget that makes old motorcycle smarter. Get a unit of the WUnit™ and ride smarter!

### Competitors

- [Motogadget mo.unit](https://motogadget.com)
- [B-BOX](https://www.elektronikbox.de/shop/index.php?main_page=product_info&cPath=10&products_id=1)

### TODO:Features

| Feature                                                                         | WUnit™                        | mo.Unit                           | B-BOX |
| ------------------------------------------------------------------------------- | ----------------------------- | --------------------------------- | ----- |
| Complete digital control using buttons possible with 4 or 5-button operation.   | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Complete replacement for the fuse box.                                          |                               | :heavy_check_mark:                |       |
| Integrated alarm system that can be installed in any position.                  | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated, digital flasher relay that is load-independent                      | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated hazard warning light.                                                | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Turn signal can optionally be set as a positioning light.                       | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated parking light and headlight flashing.                                | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Lo-beam and Hi-beam can be controlled using only one button.                    | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated, digital brake light modulator; flashing mode can be programmed.     | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Acceleration-controlled emergency brake light (automatic warning signal).       | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated starter relay for the starter system with solenoid.                  |                               | :heavy_check_mark:                |       |
| Integrated, digital horn relay.                                                 | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Configurable outputs.                                                           | 12                            | 2                                 |       |
| Calibration and current measurement enables faults to be detected on all lamps. |                               | :heavy_check_mark:                |       |
| Encrypted connection via Bluetooth® LE                                          |                               | :heavy_check_mark:                |       |
| Keyless go                                                                      | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Alarm events are sent to the App                                                | :heavy_check_mark: (Internet) | :heavy_check_mark: (Bluetooth LE) |       |
| Remote control                                                                  | :heavy_check_mark:            | :heavy_check_mark:                |       |
| GPS tracking                                                                    | :heavy_check_mark:            |                                   |       |
| Internet connectivity                                                           | :heavy_check_mark:            |                                   |       |
| Lean angle detection                                                            | :heavy_check_mark:            |                                   |       |
| Crash detection                                                                 | :heavy_check_mark:            |                                   |       |
| Emergency notification                                                          | :heavy_check_mark:            |                                   |       |

## Requirements

### Functional requirements
#### Gadget
- Communicate with app via BLE.
- Communicate with server via internet when bluetooth is disconnected.
- Communicate with server via app when bluetooth is connected.
- must be able to turn off power of unused modules for less power consumption.
- BT connection should not be "just works".

#### App
- App should always run in background.
- Should be compatible with android 10+.
- Communicate and control WUnit Gadget via BLE when bluetooth connected.
- Communicate and control WUnit Gadget via Server through internet when bluetooth is disconnected.
- Live speed tracking.
- Dashboard indicators.
- Navigation.
- Light and Dark Themes.

#### Website


#### General
- I/O behavior must be user configurable.   
- Remote output control via Bluetooth.
- Bluetooth connect/disconnect event must be user configurable using app.
- Keyless go function.
- Gadget should detect crash.
- Emergency Notification.
- Live location GPS tracking via app or website.
- Use [Firebase](https://firebase.google.com) for user auth and data storage.
- Save vehycle data in SD card and database ( mileage, etc... ).
- More than 1 vehycle per user.
- Live tracking of electrical current.
- Collecting statistics (lean angles, max and average speeds, etc like mo.ride).
- Collecting trips data (mileage, route, speeds, time, corners, etc like mo.ride).
- Maintenance reminders.
- Able to give key to vehycle to other user.
- Transfer vehycle to other user.



### Non-functional requirements

## Hardware

- Arduino Mega 2560 microcontroler
- SIM800L GSM/GPRS module
- NEO6M GPS module
- AT-09 Bluetooth low energy module
- MicroSD storage module
- MPU-9250 Accelerometer/Gyroscope/Magnetometer module

### Wiring table

| Sensor   | Connection description | Arduino Pin | Sensor Pin |
| -------- | ---------------------- | ----------- | ---------- |
| SIM800L  | Power                  |             |            |
| SIM800L  | Ground                 |             |            |
| SIM800L  | Serial (UART)          |             |            |
| SIM800L  | Serial (UART)          |             |            |
| NEO6M    | Power                  |             |            |
| NEO6M    | Ground                 |             |            |
| NEO6M    | Serial (UART)          |             |            |
| NEO6M    | Serial (UART)          |             |            |
| AT-09    | Power                  |             |            |
| AT-09    | Ground                 |             |            |
| AT-09    | Serial (UART)          |             |            |
| AT-09    | Serial (UART)          |             |            |
| MPU-9250 | Power                  |             |            |
| MPU-9250 | Ground                 |             |            |
| MPU-9250 | I2C                    |             |            |
| MPU-9250 | I2C                    |             |            |
| MicroSD  | Power                  |             |            |
| MicroSD  | Ground                 |             |            |
| MicroSD  |                        |             |            |
| MicroSD  |                        |             |            |

## Tools

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO](https://platformio.org/)

## Frameworks

- Arduino

## Libraries



## Code style

- Class names PascalCase
- public variables and functions - camelCase
- private variables and functions  _camelCase

## GIT Brach naming

Every branch name should start with one of several prefixes:

- `feature` - for developing new features.
- `fix`- for fixing bugs.
- `chore` - for other stuff.

Hyphens should be used as separator of words in branch name.

For example `feature-add-bluetooth-communication` or `fix-gyroscope-drifting`

## Tests

## Sources

- [PlatformIO Documentation](https://docs.platformio.org/)
