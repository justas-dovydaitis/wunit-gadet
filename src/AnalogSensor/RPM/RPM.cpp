#include "Constants.h"
#include "RPM.h"

RPM::RPM()
{
    _pinInput = C_TACH_INPUT_PIN;
    _remapRangeToLow = 0;
    _remapRangeToHigh = 15000;
}