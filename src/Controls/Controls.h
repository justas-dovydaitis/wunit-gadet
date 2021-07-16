// #ifndef __CONTROLS_H__
// #define __CONTROLS_H__

// #include <Arduino.h>
// #include <FreeRTOS.h>

// #include "Commands/Command.h"

// #define MAX_CONTROLS 8

// class Control
// {
// private:
//     uint16_t _inputBitMask;
//     unsigned int _debounceTime = 10; // number of ticks for debounce times.
//     unsigned int _clickTime = 600;   // number of msecs before a click is detected.
//     unsigned int _pressTime = 700;   // number of msecs before a long button press is detected

//     int _buttonPressed;

//     Command *_clickFunc = nullptr;
//     Command *_doubleClickFunc = nullptr;
//     Command *_multiClickFunc = nullptr;
//     Command *_longPressStartFunc = nullptr;
//     Command *_longPressStopFunc = nullptr;
//     Command *_duringLongPressFunc = nullptr;

//     enum ControlState_t : uint8_t
//     {
//         CONTROL_STATE_INIT = 0,
//         CONTROL_STATE_DOWN = 1,
//         CONTROL_STATE_UP = 2,
//         CONTROL_STATE_COUNT = 3,
//         CONTROL_STATE_PRESS = 6,
//         CONTROL_STATE_PRESS_END = 7,
//         CONTROL_STATE_UNKNOWN = 99
//     };

//     void setState(ControlState_t nextState);

//     ControlState_t _state = CONTROL_STATE_INIT;
//     ControlState_t _lastState = CONTROL_STATE_INIT;

//     ulong _startTime;
//     int _nClicks;
//     int _maxClicks = 1;

// public:
//     Control();
//     Control(uint16_t inputBitMask, const bool activeLow = true, const bool pullupActive = true);
//     void setDebounceTime(const ulong millis);
//     void setClickTime(const ulong millis);
//     void setPressTime(const ulong millis);

//     void attachPress(Command *func);
//     void attachDoublePress(Command *func);
//     void attachLongPressStart(Command *func);
//     void attachLongPressStop(Command *func);
//     void attachDuringLongPress(Command *func);

//     void check(void);
//     void check(bool level);
//     void reset(void);
//     int getNumberClicks(void);
//     bool isLongPressed() const { return _state == CONTROL_STATE_PRESS; };
// };

// extern Control controls[];

// #endif