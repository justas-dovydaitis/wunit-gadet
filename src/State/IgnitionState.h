#ifndef __IGNITION_STATE_H__
#define __IGNITION_STATE_H__

#include "State.h"

class IgnitionState : public AbstractState
{
private:
    /* data */
public:
    void init();
    void destroy();
};

#endif