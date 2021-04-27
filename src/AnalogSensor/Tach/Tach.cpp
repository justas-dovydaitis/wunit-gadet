#include "Constants.h"
#include "Tach.h"

Tach::Tach()
{
    _pinInput = C_TACH_INPUT_PIN;
    _remapRangeToLow = 0;
    _remapRangeToHigh = 15000;
}