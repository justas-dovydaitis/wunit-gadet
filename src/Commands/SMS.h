#ifndef __SMS_H__
#define __SMS_H__

#include "Command.h"

class SMS : public CommandInterface
{
private:
    std::string _number;
    std::string _text;

public:
    explicit SMS(std::string param);
    explicit SMS(std::string number, std::string message);
    void execute();
};

#endif