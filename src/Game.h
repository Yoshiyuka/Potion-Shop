#ifndef MAIN_H
#define MAIN_H
#include <nds.h>
#include <stack>

#include "./State.h"
#include "./input.h"

class Game
{
    public: 
        void preUpdate(); 
        void update(); 
        void render(); 

        void pushState(GameState const &state);
        void popState(); 
        GameState peekState();

    private: 
        Input input; 
        std::stack<GameState> state; 
};

#endif
