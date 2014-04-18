/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef STATE_H
#define STATE_H

//Originally wanted to do templated state machines to support bitfields of various sizes (char/short/int)
//It's quicker to just implement a single type and keep it simple though. Avoid premature optimization.

template<class T> class StateMachine
{
    public: 
        StateMachine(){};
        ~StateMachine(){}

        void setState(unsigned int const &state){ flags |= state; };
        void toggleState(unsigned int const &state){ flags ^= state; };
        void clearState(unsigned int const &state){ flags &= state; };

        bool isStateSet(unsigned int const &state) const{ return ((flags & state) == state); };


        T const states;

    private: 
        unsigned int flags;
};

struct GameStates
{
    unsigned int const STATE_INIT = 1 << 0;  // 2^0
    unsigned int const STATE_MENU = 1 << 1;  // 2^1
    unsigned int const STATE_PLAYING = 1 << 2;  // 2^2
    unsigned int const STATE_PAUSED = 1 << 3; // 2^3
};

struct PlayerStates
{
    unsigned int const STATE_SNEAKING = 1 << 0; 
    unsigned int const STATE_WALKING = 1 << 1; 
    unsigned int const STATE_RUNNING = 1 << 2; 
    unsigned int const STATE_JUMPING = 1 << 3; 
    unsigned int const STATE_IDLE = 1 << 4; 
    unsigned int const STATE_DEAD = 1 << 5; 
};


#endif

