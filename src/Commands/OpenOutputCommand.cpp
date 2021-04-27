#include "OpenOutputCommand.h"
#include "Outputs/Outputs.h"

OpenOutputCommand::OpenOutputCommand(uint8_t outputPin)
    : _outputPin(outputPin)
{
}
void OpenOutputCommand::execute()
{
    Serial.println("OPEN OUTPUT");

    Outputs::getInstance()->setPinOn(_outputPin);
}
