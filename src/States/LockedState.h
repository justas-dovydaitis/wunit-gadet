#ifndef __LOCKED_STATE_H__
#define __LOCKED_STATE_H__

#include "State.h"

class LockedState : public AbstractState
{
private:
    const uint16_t _currentStateId = StateId_t::LOCKED_STATE;

public:
    void onInit();
    void onDestroy();
};

#endif