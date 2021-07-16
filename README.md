# WUnit™ Gadget

## Intro

WUnit™ Gadget is an Arduino based gadget that makes any motorcycle smarter. Get a unit of the WUnit™ and ride smarter!

## Competitors

- [Motogadget mo.unit](https://motogadget.com)
- [B-BOX](https://www.elektronikbox.de/shop/index.php?main_page=product_info&cPath=10&products_id=1)

### Feature comparison

| Feature                                                                             | WUnit™            | mo.Unit   | B-BOX |
| ----------------------------------------------------------------------------------- | ----------------- | --------- | ----- |
| Complete digital control using buttons possible with 4 or 5-button operation.       | [x]               | [x]       |       |
| Complete replacement for the fuse box.                                              | [ ] Future task   | [x]       |       |
| Integrated alarm system that can be installed in any position.                      | [x]               | [x]       |       |
| Integrated digital flasher relay that is load-independent                           | [x]               | [x]       |       |
| Integrated hazard warning light.                                                    | [x]               | [x]       |       |
| Turn signal can optionally be set as a positioning light.                           | [x]               | [x]       |       |
| Integrated parking light and headlight flashing.                                    | [x]               | [x]       |       |
| Lo-beam and Hi-beam can be controlled using only one button.                        | [x]               | [x]       |       |
| Integrated, digital brake light modulator; flashing mode can be configured by user. | [x]               | [x]       |       |
| Acceleration-controlled emergency brake light (automatic warning signal).           | [ ] Future task   | [x]       |       |
| Integrated starter relay for the starter system with solenoid.                      | [ ] Future task   | [x]       |       |
| Integrated, digital horn relay.                                                     | [x]               | [x]       |       |
| Configurable outputs.                                                               | All 16            | 2         |       |
| Calibration and current measurement enables faults to be detected on all lamps.     | [ ] Future task   | [x]       |       |
| Encrypted connection via Bluetooth LE. (BLE)                                        | [x]               | [x]       |       |
| Keyless go.                                                                         | [x]               | [x]       |       |
| Alarm events are sent to the App.                                                   | [x] (BLE and SMS) | [x] (BLE) |       |
| Remote control.                                                                     | [x]               | [x]       |       |
| GPS tracking.                                                                       | [ ] Future task   | [ ]       |       |
| Internet connectivity.                                                              | [ ] Future task   | [ ]       |       |
| Lean angle detection.                                                               | [x]               | [ ]       |       |
| Crash detection.                                                                    | [x]               | [ ]       |       |
| Emergency notification.                                                             | [x]               | [ ]       |       |

# Requirements

## Functional requirements

### Gadget

- [ ] Communicate with app via BLE.
- [ ] Communicate with server via internet when Bluetooth is disconnected.
- [ ] Communicate with server via app when Bluetooth is connected.
- [ ] Must be able to turn off power of unused modules for less power consumption.
- [ ] Bluetooth connection should be reliable.

### App

- [ ] App is running in background with minimal system resources.
- [ ] Should be compatible with Android 10+.
- [ ] Communicate and control WUnit Gadget via BLE when bluetooth connected.
- [ ] Communicate and control WUnit Gadget via Server through internet when bluetooth is disconnected.
- [ ] Live speed tracking.
- [ ] Dashboard indicators.
- [ ] Navigation.
- [ ] Light and Dark Themes.

### Website

Nothing yet...

### General

- [x] I/O behavior must be user configurable.
- [ ] Remote output control via Bluetooth.
- [ ] Bluetooth connect/disconnect event must be user configurable using app.
- [x] Keyless go function.
- [ ] Gadget should detect crash.
- [ ] Emergency Notification.
- [ ] Live location GPS tracking via app or website.
- [ ] Save vehicle data in SD card and database ( mileage, etc... ).
- [ ] More than 1 vehicle per user.
- [ ] Live tracking of electrical current.
- [ ] Live statistics tracking (lean angles, max and average speeds, etc like mo.ride).
- [ ] Tracking trip's data (mileage, route, speeds, time, corners, etc like mo.ride).
- [ ] Maintenance reminders.
- [ ] Ability to lend/transfer ownership of vehicle key to other user.

## Non-functional requirements

Nothing yet...

## Selected hardware

- ESP32 dual core microcontroler with 8MB flash memory (ESP32-WROOVER-E).
- SCA60C tilt (lean) angle sensor.
- SIM800L GSM/GPRS module.
- PCF8575 16-bit IO expansion module.

## Selected tools

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO](https://platformio.org/)

## Frameworks and libraries

- [Arduino-ESP32](https://github.com/espressif/arduino-esp32) framework. Built on top on [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) to be compatible with Arduino environment.
  - [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) - some functions that haven't been wrapped to [Arduino-ESP32](https://github.com/espressif/arduino-esp32) framework.
  - [FreeRTOS™](https://www.freertos.org/) - Part of [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) framework.
- [PCF8574 library](https://github.com/xreef/PCF8574_library) used for communication with PCF8575 16 IO expansion board.
- [ArduinoJson](https://arduinojson.org/) save and load configurations.
- [LittleFS](https://github.com/lorol/LITTLEFS)
- [Adafruit PCA9685 PWM Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)
- [Adafruit FONA](https://github.com/adafruit/Adafruit_FONA)

## Conventions

### Code style

#### Naming convention

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

#### Includes ordering

##### Includes sections:

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

```c++
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

#### GIT Brach naming

Every branch name should start with one of several prefixes:

- `feature` - for developing new features.
- `fix`- for fixing bugs.
- `chore` - for other stuff.

Hyphens should be used as separator of words in branch name.

For example `feature-add-bluetooth-communication` or `fix-gyroscope-drifting`

## Implementation

### Circuit table

| Sensor  | Connection description       | Controller Pin      | Sensor Pin |
| ------- | ---------------------------- | ------------------- | ---------- |
| SCA60C  | Power                        | 5V                  | VCC        |
| SCA60C  | Ground                       | GND                 | GND        |
| SCA60C  | Angle value                  | GPIO34 (ADC6)       | Vo         |
| SCA60C  | D1 alarm                     | NC                  | Do1        |
| SCA60C  | D2 alarm                     | NC                  | Do2        |
| SIM800L | Ground                       | GND                 | GND        |
| SIM800L | Ground                       | NC (external power) | GND        |
| SIM800L | Power                        | NC (external power) | 5V         |
| SIM800L | Serial communication voltage | 3V3                 | VDD        |
| SIM800L | Reset pin                    | NC                  | RST        |
| SIM800L | Transmitter                  | 16                  | TXD        |
| SIM800L | Receiver                     | 17                  | RXD        |
| PCF8575 | Ground                       | GND                 | GND        |
| PCF8575 | Power                        | 5V                  | VCC        |
| PCF8575 | I<sup>2</sup>C Data          | 21                  | SDA        |
| PCF8575 | I<sup>2</sup>C Clock         | 22                  | SCL        |
| PCF8575 | Interrupt invoker            | 34                  | INT        |
| PCA9685 | Ground                       | GND                 | GND        |
| PCA9685 | Power                        | 5V                  | VCC        |
| PCA9685 | I<sup>2</sup>C Data          | 21                  | SDA        |
| PCA9685 | I<sup>2</sup>C Clock         | 22                  | SCL        |
| PCA9685 | Output Enabled               | NC                  | OE         |

### Implemented Design patterns

| Pattern   | Where                      | Why                                                                            |
| --------- | -------------------------- | ------------------------------------------------------------------------------ |
| State     | Creating device states     | For managing device behavior on different states. Whole device is based on it. |
| Strategy  | Different button types     | Types of button should have different strategies.                              |
| Command   | Buttons executes commands. | For better maintainability / future expandability.                             |
| Singleton | Configuration class        | There should be only one config for whole thing.                               |
| Singleton | Bluetooth class            | There should be only one Bluetooth config for whole thing.                     |
| Singleton | GSM class                  |                                                                                |
| Singleton | Outputs class              |                                                                                |

### Tests

TODOs:

- Write unit tests.
- Write integration tests.

### Communication via BLE

There are 3 services:

- Dashboard Service `25be9010-7a82-11eb-9439-0242ac130002`

  - Dashboard Characteristic [Read|Notify] `95265482-7a97-11eb-9439-0242ac130002`

    Gives Angle, Speed, RPMs and Odometer values separated by comma.

    `{angle},{speed},{rpm},{odo}`

  - angle - 8-bit signed integer
  - speed - 16-bit unsigned integer
  - rpm - 16-bit unsigned integer
  - odo - 32-bit unsigned integer

  - Instruments characteristic [Read|Notify] `95265483-7a97-11eb-9439-0242ac130002`

    Gives real time instruments status. Value is 16-bit unsigned integer. Should parse it to binary value to see whitch bits are on.

    Example: value is `12561`(dec) or `0x3111`(hex) so binary value is `0011000100010001` so we can see that outputs with indexes 0,4,8,12,13 are on. (Reading bits from a left to right).

- Config Service `21386056-7a82-11eb-9439-0242ac130002`

  - Passkey characteristic [Write] `1b4b6220-7a82-11eb-9439-0242ac130002`

    Characteristic for setting passkey. Paskey should be 6 digit length and cannot start with 0{?}.

  - Config characteristic [Write] `1b4b6221-7a82-11eb-9439-0242ac130002`

    Characteristic for setting config. Write serialized JSON string to it and it will be set.

    Format is simple:

    ```json
    {}
    ```

  - OTA Update characteristic [Write] `1b4b6222-7a82-11eb-9439-0242ac130002`

    Characterisitc for updating over ther air. Write a new firmware object to it.

  - Version characteristic [Read] `1b4b6223-7a82-11eb-9439-0242ac130002`

    Characteristic that holds hardware and software versions separated by comma.

    `"hardware_version,software_version"`
    For example `"0.0.1,2.0.0"`

  - OTA Update ID characteristic [Read] `1b4b6222-7a82-11eb-9439-0242ac130002`

    Not sure yet

- Control Service `213860ca-7a82-11eb-9439-0242ac130002`

  - Control Characteristic [Write] `21386057-7a82-11eb-9439-0242ac130002`

    Characteristic to control WUnit remotely.
    Way to use it is to write a command ID and then params.

    All values are unsigned integers.

    `{commandId},{param1},{param2}...`

    If command does not need any parameters, then do not write any.
    Or write, but they will be ignored.

    CommandId is unsigned integer

    - `COMMAND_OPEN_OUTPUT`

      - id = 0
      - output [0-15]

    - `COMMAND_CLOSE_OUTPUT`

      - id = 1
      - output [0-15]

    - `COMMAND_TOGGLE_OUTPUT`

      - id = 2
      - output [0-16]
      - initialState [0|1]

    - `COMMAND_LOCK_BIKE`

      - id = 3

    - `COMMAND_UNLOCK_BIKE`

      - id = 4

    - `COMMAND_ENTER_CONFIG_STATE`

      - id = 5

    - `COMMAND_EXIT_CONFIG_STATE`

      - id = 6

## Sources

- [Arduino Documentation](https://www.arduino.cc/reference/en/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [IO Expander board](https://create.arduino.cc/projecthub/xreef/pcf8575-i2c-16-bit-digital-input-output-expander-48a7c6)
- [Button combo click logic inspiration](http://www.mathertel.de/Arduino/OneButtonLibrary.aspx)
- [OTA update tutorial](https://learn.sparkfun.com/tutorials/esp32-ota-updates-over-ble-from-a-react-web-application/all)
