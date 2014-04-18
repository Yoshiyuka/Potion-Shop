/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef STATE_H
#define STATE_H

//Originally wanted to do templated state machines to support bitfields of various sizes (char/short/int)
//It's quicker to just implement a single type and keep it simple though. Avoid premature optimization.

class StateMachine
{
    public: 
        StateMachine(){};
        ~StateMachine(){}

        void setState(unsigned int const &state);
        void toggleState(unsigned int const &state);
        void clearState(unsigned int const &state); 

        bool isStateSet(unsigned int const &state) const; 

    private: 
        unsigned int flags;
};

struct GameStates
{
    unsigned int const STATE_NONE = 0;
    unsigned int const STATE_INIT = 1;  // 2^0
    unsigned int const STATE_MENU = 2;  // 2^1
    unsigned int const STATE_PLAYING = 4;  // 2^2
    unsigned int const STATE_PAUSED = 8; // 2^3
};

#endif

