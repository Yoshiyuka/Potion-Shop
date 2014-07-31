#ifndef MAIN_H
#define MAIN_H
#include <nds.h>

#include "./State.h"
#include "./input.h"

class Game
{
    public: 
        void preUpdate(); 
        void update(); 
        void render(); 

    private: 
        Input input; 
        StateMachine states;
};

#endif
