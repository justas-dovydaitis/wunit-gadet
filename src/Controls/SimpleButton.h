#ifndef __SIMPLE_BUTTON_H__
#define __SIMPLE_BUTTON_H__

#include <Arduino.h>
#include "AbstractButton.h"

class SimpleButton : public AbstractButton
{
private:
    uint _debounceTime = 10;
    uint _clickTime = 0;
    uint _pressTime = 10;

public:
    SimpleButton();
    SimpleButton(uint16_t inputBitMask,
                 const bool activeLow = true,
                 const bool pullupActive = true);

    void handlePress(bool level) override;
};

#endif