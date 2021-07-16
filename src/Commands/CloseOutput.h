#ifndef __CLOSE_OUTPUT_H__
#define __CLOSE_OUTPUT_H__
#include "Command.h"

class CloseOutput : public CommandInterface
{
private:
    uint8_t _outputPin;

public:
    explicit CloseOutput(uint8_t outputPin);
    void execute() override;
};

#endif