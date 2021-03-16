#ifndef __STATE_H__
#define __STATE_H__
#include <Arduino.h>

class AbstractState
{
public:
    virtual void init() = 0;
    virtual void destroy() = 0;
};

extern AbstractState *pCurrentState;

extern void setState(AbstractState *pNewState);

#endif