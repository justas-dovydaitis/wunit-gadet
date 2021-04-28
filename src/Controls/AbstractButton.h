#ifndef __ABSTRACT_BUTTON_H__
#define __ABSTRACT_BUTTON_H__

#include <Arduino.h>

#include "Commands/CompositeCommand.h"

class AbstractButton
{
public:
    virtual ~AbstractButton();
    virtual void handlePress(bool level) = 0;

    AbstractButton();
    AbstractButton(uint16_t inputBitMask,
                   const bool activeLow = true,
                   const bool pullupActive = true);

    void attachPress(AbstractCompositeCommand *func);
    void attachDoublePress(AbstractCompositeCommand *func);
    void attachLongPressStart(AbstractCompositeCommand *func);
    void attachLongPressStop(AbstractCompositeCommand *func);
    void attachDuringLongPress(AbstractCompositeCommand *func);

    void setDebounceTime(const ulong millis);
    void setClickTime(const ulong millis);
    void setPressTime(const ulong millis);

    void check(void);
    void reset(void);
    int getNumberClicks(void);
    bool isLongPressed() const;

protected:
    uint16_t _inputBitMask;
    uint _debounceTime = 10; // number of ticks for debounce times.
    uint _clickTime = 600;   // number of msecs before a click is detected.
    uint _pressTime = 700;   // number of msecs before a long button press is detected

    int _buttonPressed;

    AbstractCompositeCommand *_clickFunc = nullptr;
    AbstractCompositeCommand *_doubleClickFunc = nullptr;
    AbstractCompositeCommand *_multiClickFunc = nullptr;
    AbstractCompositeCommand *_longPressStartFunc = nullptr;
    AbstractCompositeCommand *_longPressStopFunc = nullptr;
    AbstractCompositeCommand *_duringLongPressFunc = nullptr;

    enum ControlState_t : uint8_t
    {
        BUTTON_STATE_INIT = 0,
        BUTTON_STATE_DOWN = 1,
        BUTTON_STATE_UP = 2,
        BUTTON_STATE_COUNT = 3,
        BUTTON_STATE_PRESS = 6,
        BUTTON_STATE_PRESS_END = 7,
        BUTTON_STATE_UNKNOWN = 99
    };

    void setState(ControlState_t nextState);

    ControlState_t _state = BUTTON_STATE_INIT;
    ControlState_t _lastState = BUTTON_STATE_INIT;

    ulong _startTime;
    int _nClicks;
    int _maxClicks = 1;
};

#endif