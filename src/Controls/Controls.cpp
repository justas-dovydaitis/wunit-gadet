#include "Controls.h"
#include "IOConfig/IOConfig.h"

Control::Control() {}
Control::Control(uint16_t inputBitMask,
                 const bool activeLow,
                 const bool pullupActive)
    : _inputBitMask(inputBitMask)
{
    _buttonPressed = activeLow ? LOW : HIGH;
}

void Control::setDebounceTime(ulong millis)
{
    _debounceTime = millis;
}

void Control::setClickTime(ulong millis)
{
    _clickTime = millis;
}

void Control::setPressTime(ulong millis)
{
    _pressTime = millis;
}

void Control::attachPress(Command *func)
{
    _clickFunc = func;
}

void Control::attachDoublePress(Command *func)
{
    _doubleClickFunc = func;
}

void Control::attachDuringLongPress(Command *func)
{
    _duringLongPressFunc = func;
}

void Control::attachLongPressStart(Command *func)
{
    _longPressStartFunc = func;
}

void Control::attachLongPressStop(Command *func)
{
    _longPressStopFunc = func;
}

void Control::reset(void)
{
    _state = CONTROL_STATE_INIT;
    _lastState = CONTROL_STATE_INIT;
    _nClicks = 0;
    _startTime = 0;
}

void Control::setState(ControlState_t newState)
{
    _lastState = _state;
    _state = newState;
}

int Control::getNumberClicks(void)
{
    return _nClicks;
}

void Control::check(void)
{
    uint16_t pinVal = ioExpander.read16();
    check(pinVal == _inputBitMask);
}

void Control::check(bool activeLevel)
{
    ulong currentTime = millis();
    ulong waitTime = currentTime - _startTime;

    switch (_state)
    {
    case CONTROL_STATE_INIT:
        if (activeLevel)
        {
            setState(CONTROL_STATE_DOWN);
            _startTime = currentTime;
            _nClicks = 0;
        }
        break;
    case CONTROL_STATE_DOWN:

        if ((!activeLevel) && (waitTime < _debounceTime))
        {
            setState(_lastState);
        }
        else if (!activeLevel)
        {
            setState(CONTROL_STATE_UP);
            _startTime = currentTime;
        }
        else if ((activeLevel) && (waitTime > _pressTime))
        {
            if (_longPressStartFunc)
            {
                _longPressStartFunc->execute();
            }

            setState(CONTROL_STATE_PRESS);
        }
        break;
    case CONTROL_STATE_UP:

        if ((activeLevel) && (waitTime < _debounceTime))
        {
            setState(_lastState);
        }
        else if (waitTime >= _debounceTime)
        {
            _nClicks++;
            setState(CONTROL_STATE_COUNT);
        }
        break;

    case CONTROL_STATE_COUNT:
        if (activeLevel)
        {
            setState(CONTROL_STATE_DOWN);
            _startTime = currentTime;
        }
        else if ((waitTime > _clickTime) || (_nClicks == _maxClicks))
        {
            if (_nClicks == 1)
            {
                if (_clickFunc)
                {
                    _clickFunc->execute();
                }
            }
            else if (_nClicks == 2)
            {
                if (_doubleClickFunc)
                {
                    _doubleClickFunc->execute();
                }
            }
            reset();
        }
        break;

    case CONTROL_STATE_PRESS:
        if (!activeLevel)
        {
            setState(CONTROL_STATE_PRESS_END);
            _startTime = currentTime;
        }
        else
        {
            if (_duringLongPressFunc)
            {
                _duringLongPressFunc->execute();
            }
        }
        break;

    case CONTROL_STATE_PRESS_END:
        if (activeLevel && (waitTime < _debounceTime))
        {
            setState(_lastState);
        }
        else if (waitTime >= _debounceTime)
        {
            if (_longPressStopFunc)
            {
                _longPressStopFunc->execute();
            }

            reset();
        }
        break;

    default:
        setState(CONTROL_STATE_INIT);
        break;
    }
}

Control controls[] = {
    Control(makeWord(B11111111, B11111110)),
    // Control(2),
    // Control(4),
    // Control(8),
    // Control(16),
    // Control(32),
    // Control(64),
    // Control(128)
};