# WUnit™ Gadget

## About

WUnit™ Gadget is an Arduino based gadget that makes any motorcycle smarter. Get a unit of the WUnit™ and ride smarter!

### Competitors

- [Motogadget mo.unit](https://motogadget.com)
- [B-BOX](https://www.elektronikbox.de/shop/index.php?main_page=product_info&cPath=10&products_id=1)

### TODO:Features

| Feature                                                                             | WUnit™                        | mo.Unit                           | B-BOX |
| ----------------------------------------------------------------------------------- | ----------------------------- | --------------------------------- | ----- |
| Complete digital control using buttons possible with 4 or 5-button operation.       | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Complete replacement for the fuse box.                                              |                               | :heavy_check_mark:                |       |
| Integrated alarm system that can be installed in any position.                      | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated digital flasher relay that is load-independent                           | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated hazard warning light.                                                    | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Turn signal can optionally be set as a positioning light.                           | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated parking light and headlight flashing.                                    | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Lo-beam and Hi-beam can be controlled using only one button.                        | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated, digital brake light modulator; flashing mode can be configured by user. | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Acceleration-controlled emergency brake light (automatic warning signal).           | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Integrated starter relay for the starter system with solenoid.                      |                               | :heavy_check_mark:                |       |
| Integrated, digital horn relay.                                                     | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Configurable outputs.                                                               | 12                            | 2                                 |       |
| Calibration and current measurement enables faults to be detected on all lamps.     |                               | :heavy_check_mark:                |       |
| Encrypted connection via Bluetooth LE. (BLE)                                        |                               | :heavy_check_mark:                |       |
| Keyless go.                                                                         | :heavy_check_mark:            | :heavy_check_mark:                |       |
| Alarm events are sent to the App.                                                   | :heavy_check_mark: (Internet) | :heavy_check_mark: (Bluetooth LE) |       |
| Remote control.                                                                     | :heavy_check_mark:            | :heavy_check_mark:                |       |
| GPS tracking.                                                                       | :heavy_check_mark:            |                                   |       |
| Internet connectivity.                                                              | :heavy_check_mark:            |                                   |       |
| Lean angle detection.                                                               | :heavy_check_mark:            |                                   |       |
| Crash detection.                                                                    | :heavy_check_mark:            |                                   |       |
| Emergency notification.                                                             | :heavy_check_mark:            |                                   |       |

## Requirements

### Functional requirements

#### Gadget

- Communicate with app via BLE.
- Communicate with server via internet when Bluetooth is disconnected.
- Communicate with server via app when Bluetooth is connected.
- Must be able to turn off power of unused modules for less power consumption.
- Bluetooth connection should be reliable.

#### App

- App is running in background with minimal system resources.
- Should be compatible with Android 10+.
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
- Save vehicle data in SD card and database ( mileage, etc... ).
- More than 1 vehicle per user.
- Live tracking of electrical current.
- Live statistics tracking (lean angles, max and average speeds, etc like mo.ride).
- Tracking trip's data (mileage, route, speeds, time, corners, etc like mo.ride).
- Maintenance reminders.
- Ability to lend/transfer ownership of vehicle key to other user.

### Non-functional requirements

## Hardware

- Arduino Mega 2560 microcontroler.
- SIM800L GSM/GPRS module.
- NEO6M GPS module.
- AT-09 Bluetooth low energy module.
- MicroSD storage module.
- MPU-9250 Accelerometer/Gyroscope/Magnetometer module.

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
| AT-09    | Power                  | 3V3         | VCC        |
| AT-09    | Ground                 | GND         | GND        |
| AT-09    | Serial (UART)          | RX1         | TX         |
| AT-09    | Serial (UART)          | TX1         | RX         |
| AT-09    | Connection status      | 22          | STAT       |
| AT-09    | Sleep pin              | 23          | PWRC       |
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

### Naming convention

| Type                   | Scope     | Name                 | Suffix    | Prefix   | Example              | Accepted |
| ---------------------- | --------- | -------------------- | --------- | -------- | -------------------- | -------- |
| Class / Structure name |           | PascalCase           |           |          | MyClass              | +        |
| Interface class name   |           | PascalCase           | Interface |          | MyClassInterface     | +        |
| Abstract class name    |           | PascalCase           |           | Abstract | AbstractMyClass      | +        |
| Variable               | Function  | camelCase            |           |          | privateVariable      | +        |
| Variable               | Private   | camelCase            |           | \_       | \_privateVariable    | +        |
| Variable               | Protected | camelCase            |           | \_       | \_protectedVariable  | +        |
| Variable               | Public    | camelCase            |           | \_       | \_publicVariable     | +        |
| Variable               | Global    | SCREAMING_SNAKE_CASE |           | G        | G_MY_GLOBAL_VARIABLE | +        |
| Variable               | Static    | SCREAMING_SNAKE_CASE |           | S        | S_MY_GLOBAL_VARIABLE | +        |
| Constant               | Global    | SCREAMING_SNAKE_CASE |           | C        | C_MY_GLOBAL_VARIABLE | +        |
| Function               | Private   | camelCase            |           |          | myPrivateFunction    | +        |
| Function               | Protected | camelCase            |           |          | myProtectedFunction  | +        |
| Function               | Public    | camelCase            |           |          | myPublicFunction     | +        |
| Function               | Global    | camelCase            |           |          | myGlobalFunction     | +        |
| Function Argument      |           | camelCase            |           |          | myFunctionArgument   | +        |
| Enum (class)           |           | PascalCase           |           | E        | EMyEnum              | +        |
| Enumerator (class)     |           | PascalCase           |           |          | MyEnumerator         | +        |
| Enum                   |           | SCREAMING_SNAKE_CASE |           | E        | E_MY_ENUM            | +        |
| Enumerator             |           | SCREAMING_SNAKE_CASE |           |          | MY_ENUMERATOR        | +        |
| Namespace              |           | snake_case           |           |          | my_namespace         | +        |
| Define                 |           | SCREAMING_SNAKE_CASE |           |          | MY_DEFINE            | +        |

### Includes ordering

#### Includes sections:

1.  CPP associated Header.
2.  Same application headers.
3.  RMS Libraries.
4.  All system headers.

Includes of CPP associated header and same application headers must be in quotes others in '<>'.

Each section must be separated by new line.
Same section headers are ordered alphabetically.
Example:

1.  "a.h"
2.  "aa/b/c.h"
3.  "b.h"
4.  "d/aa.h"

Example (example.cpp):

```
#include "data/example.h"

#include "data/example2.h"
#include "example1.h"
#include "utils/example3.h"

#include <rms/Log.h>
#include <rms/sql/SqlException.h>

#include <curl/curl.h>
#include <memory>
#include <mutex>
```

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
- [Bluetooth LE Module Datasheet](https://www.roboter-bausatz.de/media/pdf/b0/05/8b/JDY-08-Bluetooth-LE-Module-Datasheet.pdf)
- [Guide to Bluetooth Security (PDF)](https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-121r2.pdf)
- [BLE security example (PDF)](https://www.dialog-semiconductor.com/sites/default/files/training_05_ble_security_example_v1.2.pdf)
