#ifndef __OPEN_OUTPUT_H__
#define __OPEN_OUTPUT_H__

#include "Command.h"

class OpenOutput : public CommandInterface
{
private:
    uint8_t _outputPin;

public:
    explicit OpenOutput(uint8_t outputPin);
    void execute() override;
};

#endif