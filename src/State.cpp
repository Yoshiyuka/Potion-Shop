/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "./State.h"
#include <algorithm>

State::State(function init, function update, function destroy) : onInit(init), onUpdate(update), onDestroy(destroy), active(false)
{
}
State::State(const State &rhs) : onInit(rhs.onInit), onUpdate(rhs.onUpdate), onDestroy(rhs.onDestroy), active(false)
{
}
State::State(State &&rhs) : onInit(nullptr), onUpdate(nullptr), onDestroy(nullptr), active(false)
{
    onInit = rhs.onInit;
    onUpdate = rhs.onUpdate;
    onDestroy = rhs.onDestroy;

    rhs.onInit = nullptr;
    rhs.onUpdate = nullptr;
    rhs.onDestroy = nullptr;
    rhs.active = false;
}

State& State::operator=(const State &rhs)
{
    State tmp = rhs;

    std::swap(onInit, tmp.onInit);
    std::swap(onUpdate, tmp.onUpdate);
    std::swap(onDestroy, tmp.onDestroy);

    return *this;
}

State& State::operator=(State &&rhs)
{
    if(this != &rhs)
    {
        onInit = rhs.onInit;
        onUpdate = rhs.onUpdate;
        onDestroy = rhs.onDestroy;

        rhs.onInit = nullptr;
        rhs.onUpdate = nullptr;
        rhs.onDestroy = nullptr;
        rhs.active = false;
    }

    return *this;
}

void State::init()
{
    if(!onInit){ return; }

    onInit();
}

void State::update()
{
    if(!onUpdate){ return; }

    onUpdate();
}

void State::destroy()
{
    if(!onDestroy){ return; }

    onDestroy();
}

/*-----------------------------STATE MACHINE METHOD DEFINITIONS--------------------------------*/

State StateMachine::getCurrentState()
{
    return currentState;
}
