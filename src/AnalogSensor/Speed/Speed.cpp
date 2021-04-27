#include "Constants.h"
#include "Speed.h"

Speed::Speed()
{
    _pinInput = C_SPEED_INPUT_PIN;
    remapRangeFrom = 0;
    remapRangeTo = 299;
}