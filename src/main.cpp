/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "./main.h"

StateMachine gameState;
void onVBlank()
{
}

void onHBlank()
{
}

int main(int argc, char **argv)
{
    Game game; 



    //TESTING METHODS
/*    PrintConsole console; 
    PrintConsole other; 
    consoleInit(&other, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, true, false);
    consoleInit(&console, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, false, true);
    consoleSetWindow(&console, 0, 0, 32, 8);
    consoleSelect(&console);
    //Input input; 
    printf("Current State: %d", (int)game.peekState());
    game.pushState(GameState::STATE_INIT);
    printf("Current State: %d", (int)game.peekState());
    game.pushState(GameState::STATE_PLAYING);
    printf("Current State: %d", (int)game.peekState());
    game.popState();
    printf("Current State: %d", (int)game.peekState());
    //InputComponent inputComponent(input);
    //inputComponent.printKeyData(&console);
    //input.printKeyData(&console);
    //inputComponent.printTouchData(&console);
    //input.printTouchData(&console);
*/
    while(1)
    {
        game.preUpdate();
        game.update();
        game.render();
    }
    return 0;
}
