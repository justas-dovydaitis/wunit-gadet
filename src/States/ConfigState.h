#ifndef __CONFIG_STATE_H__
#define __CONFIG_STATE_H__

#include "State.h"

class ConfigState : public AbstractState
{
private:
    const uint16_t _currentStateId = StateId_t::CONFIG_STATE;

    void onInit();
    void onDestroy();
};

#endif