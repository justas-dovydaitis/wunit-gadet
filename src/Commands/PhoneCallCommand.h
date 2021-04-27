#ifndef __PHONE_CALL_COMMAND_H__
#define __PHONE_CALL_COMMAND_H__

#include "Command.h"

class PhoneCallCommand : public Command
{
private:
    std::string _number;

public:
    explicit PhoneCallCommand(std::string number);
    void execute();
};

#endif