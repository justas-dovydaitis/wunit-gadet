#include "AbstractButton.h"

void AbstractButton::setDebounceTime(ulong millis)
{
    _debounceTime = millis;
}

void AbstractButton::setClickTime(ulong millis)
{
    _clickTime = millis;
}

void AbstractButton::setPressTime(ulong millis)
{
    _pressTime = millis;
}

void AbstractButton::reset(void)
{
    _state = BUTTON_STATE_INIT;
    _lastState = BUTTON_STATE_INIT;
    _nClicks = 0;
    _startTime = 0;
}

void AbstractButton::setState(ControlState_t newState)
{
    _lastState = _state;
    _state = newState;
}

int AbstractButton::getNumberClicks(void)
{
    return _nClicks;
}

bool AbstractButton::isLongPressed() const
{
    return _state == BUTTON_STATE_PRESS;
}

void AbstractButton::attachPress(CommandInterface *func)
{
    _clickFunc = func;
}

void AbstractButton::attachDoublePress(CommandInterface *func)
{
    _doubleClickFunc = func;
}

void AbstractButton::attachDuringLongPress(CommandInterface *func)
{
    _duringLongPressFunc = func;
}

void AbstractButton::attachLongPressStart(CommandInterface *func)
{
    _longPressStartFunc = func;
}

void AbstractButton::attachLongPressStop(CommandInterface *func)
{
    _longPressStopFunc = func;
}