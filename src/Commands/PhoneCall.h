#ifndef __PHONE_CALL_H__
#define __PHONE_CALL_H__

#include "Command.h"

class PhoneCall : public CommandInterface
{
private:
    std::string _number;

public:
    explicit PhoneCall(std::string number);
    void execute();
};

#endif