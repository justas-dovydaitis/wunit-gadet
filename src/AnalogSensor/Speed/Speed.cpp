#include "Constants.h"
#include "Speed.h"

Speed::Speed()
{
    _pinInput = C_SPEED_INPUT_PIN;
    _remapRangeToLow = 0;
    _remapRangeToHigh = 299;
}