#include "SMSCommand.h"
#include "GSM/GSM.h"
SMSCommand::SMSCommand(std::string param)
{
    uint8_t splitter = param.find(',');
    _text = param.substr(splitter + 1);
    _number = param.substr(0, splitter - 1);
}
SMSCommand::SMSCommand(std::string number, std::string message)
    : _number(number),
      _text(message)
{
}

void SMSCommand::execute()
{
    Serial.printf("%s: %s %s\n", "BBZ", _number.c_str(), _text.c_str());
    Adafruit_FONA *pFona = GSM::getInstance()->getFona();

    char *num = new char[_number.length() + 1];
    strcpy(num, _number.c_str());

    char *msg = new char[_text.length() + 1];
    strcpy(msg, _text.c_str());

    if (!pFona->sendSMS(num, msg))
    {
        Serial.println("SMS failed");
    }
}