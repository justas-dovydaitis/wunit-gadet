#include "Constants.h"
#include "Tach.h"

Tach::Tach()
{
    _pinInput = C_TACH_INPUT_PIN;
    remapRangeFrom = 0;
    remapRangeTo = 15000;
}