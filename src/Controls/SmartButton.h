#ifndef __SMART_BUTTON_H__
#define __SMART_BUTTON_H__

#include <Arduino.h>
#include "AbstractButton.h"

class SmartButton : public AbstractButton
{
public:
    SmartButton();
    SmartButton(uint16_t inputBitMask,
                const bool activeLow = true,
                const bool pullupActive = true);

    void handlePress(bool activeLevel) override;
};

#endif