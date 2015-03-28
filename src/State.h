/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef STATE_H
#define STATE_H

typedef void (*function)();
class State
{
    function onInit;
    function onUpdate;
    function onDestroy;

    bool active;

    public:
        State(function init, function update, function destroy);
        State(const State &rhs);
        State(State &&rhs);
        State& operator=(const State &rhs);
        State& operator=(State &&rhs); 

        void init();
        void update();
        void destroy();
};

class StateMachine
{
    public: 
        StateMachine() : currentState(State(nullptr, nullptr, nullptr)){};
        ~StateMachine(){};

        //State createState(const function init, const function update, const function destroy);
        void setState(State state);
        State getCurrentState();

    private:
        State currentState;
};

extern StateMachine gameState;
#endif
