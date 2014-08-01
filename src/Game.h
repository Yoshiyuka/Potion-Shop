#ifndef GAME_H
#define GAME_H
#include <nds.h>

#include "./State.h"
#include "./input.h"

class Game
{
    public: 
        Game();
        void preUpdate(); 
        void update(); 
        void render(); 

    private: 
        Input input; 
};

#endif
