#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include <Arduino.h>
#include <FreeRTOS.h>

#define MAX_CONTROLS 8

typedef uint8_t ControlMode_t;
typedef void (*ControlFunction_t)(void);
typedef void (*ControlFunctionWithParam_t)(void *);

class Control
{
public:
    Control();
    Control(uint16_t inputBitMask, const bool activeLow = true, const bool pullupActive = true);
    void setDebounceTime(const ulong millis);
    void setClickTime(const ulong millis);
    void setPressTime(const ulong millis);

    void attachPress(ControlFunction_t func);
    void attachDoublePress(ControlFunction_t func);
    void attachLongPressStart(ControlFunction_t func);
    void attachLongPressStop(ControlFunction_t func);
    void attachDuringLongPress(ControlFunction_t func);

    void check(void);
    void check(bool level);
    void reset(void);
    int getNumberClicks(void);
    bool isLongPressed() const { return _state == CONTROL_STATE_PRESS; };

private:
    uint16_t _inputBitMask;        
    unsigned int _debounceTime = 10; // number of ticks for debounce times.
    unsigned int _clickTime = 600;   // number of msecs before a click is detected.
    unsigned int _pressTime = 700;   // number of msecs before a long button press is detected

    int _buttonPressed;

    ControlFunction_t _clickFunc = NULL;
    ControlFunctionWithParam_t _paramClickFunc = NULL;
    void *_clickFuncParam = nullptr;

    ControlFunction_t _doubleClickFunc = NULL;
    ControlFunctionWithParam_t _paramDoubleClickFunc = NULL;
    void *_doubleClickFuncParam = nullptr;

    ControlFunction_t _multiClickFunc = NULL;
    ControlFunctionWithParam_t _paramMultiClickFunc = NULL;
    void *_multiClickFuncParam = nullptr;

    ControlFunction_t _longPressStartFunc = NULL;
    ControlFunctionWithParam_t _paramLongPressStartFunc = NULL;
    void *_longPressStartFuncParam = nullptr;

    ControlFunction_t _longPressStopFunc = NULL;
    ControlFunctionWithParam_t _paramLongPressStopFunc = NULL;
    void *_longPressStopFuncParam = nullptr;

    ControlFunction_t _duringLongPressFunc = NULL;
    ControlFunctionWithParam_t _paramDuringLongPressFunc = NULL;
    void *_duringLongPressFuncParam = nullptr;

    enum ControlState_t : uint8_t
    {
        CONTROL_STATE_INIT = 0,
        CONTROL_STATE_DOWN = 1,
        CONTROL_STATE_UP = 2,
        CONTROL_STATE_COUNT = 3,
        CONTROL_STATE_PRESS = 6,
        CONTROL_STATE_PRESS_END = 7,
        CONTROL_STATE_UNKNOWN = 99
    };

    void setState(ControlState_t nextState);

    ControlState_t _state = CONTROL_STATE_INIT;
    ControlState_t _lastState = CONTROL_STATE_INIT;

    ulong _startTime;
    int _nClicks;
    int _maxClicks = 1;
};

extern Control controls[];

#endif