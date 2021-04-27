#ifndef __OPEN_OUTPUT_H__
#define __OPEN_OUTPUT_H__

#include "Command.h"

class OpenOutput : public Command
{
private:
    uint8_t _outputPin;

public:
    explicit OpenOutput(uint8_t outputPin);
    void execute() override;
};

#endif