#include "PhoneCallCommand.h"
#include "GSM/GSM.h"

PhoneCallCommand::PhoneCallCommand(std::string number)
{
    _number = number;
}

void PhoneCallCommand::execute()
{
    Adafruit_FONA *pFona = GSM::getInstance()->getFona();
    char *num = new char[_number.length() + 1];
    strcpy(num, _number.c_str());
    pFona->callPhone(num);

    if (!pFona->callPhone(num))
    {
        Serial.println("CALL failed");
    }
}