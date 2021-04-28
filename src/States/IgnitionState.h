#ifndef __IGNITION_STATE_H__
#define __IGNITION_STATE_H__

#include "State.h"

class IgnitionState : public AbstractState
{
private:
    const uint16_t _currentStateId = StateId_t::IGNITION_STATE;
    CommandInterface *_pCrashRoutine = nullptr;

    void onInit();
    void onDestroy();
};

#endif