#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "State.h"

class RunningState : public AbstractState
{
private:
    const uint16_t _currentStateId = StateId_t::RUNNING_STATE;

public:
    void onInit();
    void onDestroy();
};

#endif