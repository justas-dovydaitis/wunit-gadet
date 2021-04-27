#ifndef __SMS_COMMAND_H__
#define __SMS_COMMAND_H__

#include "Command.h"

class SMSCommand : public Command
{
private:
    std::string _number;
    std::string _text;

public:
    explicit SMSCommand(std::string param);
    explicit SMSCommand(std::string number, std::string message);
    void execute();
};

#endif