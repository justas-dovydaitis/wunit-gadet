#include "SmartButton.h"

SmartButton::SmartButton() {}
SmartButton::SmartButton(uint16_t inputBitMask,
                         const bool activeLow,
                         const bool pullupActive)
    : AbstractButton(inputBitMask, activeLow, pullupActive)
{
}

void SmartButton::handlePress(bool activeLevel)
{
    ulong currentTime = millis();
    ulong waitTime = currentTime - _startTime;

    switch (_state)
    {
    case BUTTON_STATE_INIT:
        if (activeLevel)
        {
            setState(BUTTON_STATE_DOWN);
            _startTime = currentTime;
            _nClicks = 0;
        }
        break;
    case BUTTON_STATE_DOWN:

        if ((!activeLevel) && (waitTime < _debounceTime))
        {
            setState(_lastState);
        }
        else if (!activeLevel)
        {
            setState(BUTTON_STATE_UP);
            _startTime = currentTime;
        }
        else if ((activeLevel) && (waitTime > _pressTime))
        {
            if (_longPressStartFunc)
            {
                _longPressStartFunc->execute();
            }

            setState(BUTTON_STATE_PRESS);
        }
        break;
    case BUTTON_STATE_UP:

        if ((activeLevel) && (waitTime < _debounceTime))
        {
            setState(_lastState);
        }
        else if (waitTime >= _debounceTime)
        {
            _nClicks++;
            setState(BUTTON_STATE_COUNT);
        }
        break;

    case BUTTON_STATE_COUNT:
        if (activeLevel)
        {
            setState(BUTTON_STATE_DOWN);
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

    case BUTTON_STATE_PRESS:
        if (!activeLevel)
        {
            setState(BUTTON_STATE_PRESS_END);
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

    case BUTTON_STATE_PRESS_END:
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
        setState(BUTTON_STATE_INIT);
        break;
    }
}