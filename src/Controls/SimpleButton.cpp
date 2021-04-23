#include "SimpleButton.h"

SimpleButton::SimpleButton(uint16_t inputBitMask,
                           const bool activeLow,
                           const bool pullupActive)
    : AbstractButton(inputBitMask, activeLow, pullupActive)
{
}

void SimpleButton::handlePress(bool activeLevel)
{
    ulong currentTime = millis();
    ulong waitTime = currentTime - _startTime;

    switch (_state)
    {
    case BUTTON_STATE_INIT:
        if (activeLevel)
        {
            setState(BUTTON_STATE_DOWN);
        }

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