/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <nds.h>
#include "./input.h"
#include "./InputComponent.h"
#include "./entity.h"
#include "./State.h"

#include "splash.h"
#include <cstdio>

void update()
{
}

void render()
{
}

void onVBlank()
{
}

void onHBlank()
{
}

int main(int argc, char **argv)
{
    StateMachine<GameStates> gameState; 
    gameState.setState(gameState.states.STATE_INIT); 

    videoSetMode(MODE_0_2D); //top screen
    videoSetModeSub(MODE_0_2D); //bottom screen

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    //int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

    //dmaCopy(splashBitmap, bgGetGfxPtr(bg3), 256*256);
    //dmaCopy(splashPal, BG_PALETTE, 256*2);

    //TESTING METHODS
    PrintConsole console; 
    PrintConsole other; 
    consoleInit(&other, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, true, false);
    consoleInit(&console, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, false, true);
    consoleSetWindow(&console, 0, 0, 32, 8);
    consoleSelect(&console);
    printf("STATE_INIT: %s\n", gameState.isStateSet(gameState.states.STATE_INIT) ? "true" : "false");
    printf("STATE_PAUSED: %s\n", gameState.isStateSet(gameState.states.STATE_PAUSED) ? "true" : "false");
    gameState.setState(gameState.states.STATE_PAUSED);
    printf("STATE_INIT: %s\n", gameState.isStateSet(gameState.states.STATE_INIT) ? "true" : "false");
    printf("STATE_PAUSED: %s\n", gameState.isStateSet(gameState.states.STATE_PAUSED) ? "true" : "false");
    /*Input input; 
    InputComponent inputComponent(input);
    inputComponent.printKeyData(&console);
    input.printKeyData(&console);
    inputComponent.printTouchData(&console);
    input.printTouchData(&console);
    */

    while(1)
    {
        update();
        render();

        swiWaitForVBlank();
    }
    return 0;
}
