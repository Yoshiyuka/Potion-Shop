/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "./Game.h"
#include "splash.h"

//check/set states before we do any further updating
void Game::preUpdate()
{
    //input.processInput();
    //I guess a switch statement will be fine for now just to move forward and get it done. 
    //TODO: possibly refactor into functors later.
    switch(peekState())
    {
        //does it really make sense to have a 'none' state? Just initialize state to init. Anyways...
        case(GameState::STATE_NONE):
        {
            //just going to display blank screen until input is received.
            //timerStart(0, ClockDivider_1024, TIMER_FREQ_1024(1), test);
            this->pushState(GameState::STATE_INIT); 
            break;
        }
        //Should only run once and immediately move to the next state. Don't set video modes and copy memory repeatedly.
        case(GameState::STATE_INIT):
        {
            //TODO: refactor to own method
            //Set main and sub screen video modes
            videoSetMode(MODE_5_2D); //top screen
            videoSetModeSub(MODE_0_2D); //bottom screen

            //use vram bank A for main screen, bank C for sub screen.
            vramSetBankA(VRAM_A_MAIN_BG);
            vramSetBankC(VRAM_C_SUB_BG);

            int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

            dmaCopy(splashBitmap, bgGetGfxPtr(bg3), 256*256);
            dmaCopy(splashPal, BG_PALETTE, 256*2);

            this->pushState(GameState::STATE_MENU);
            break;
        }
        case(GameState::STATE_MENU):
        {
            break;
        }
        case(GameState::STATE_PLAYING):
        {
            break;
        }
        case(GameState::STATE_PAUSED):
        {
            break;
        }
        default:
        {
            break;
        }

    }
}

void Game::update()
{
}

void Game::render()
{
}

void Game::pushState(GameState const &state)
{
    this->state.push(state);
}

void Game::popState()
{
    if(!state.empty())
    {
        state.pop();
    }
}

GameState Game::peekState()
{
    return !state.empty() ? state.top() : GameState::STATE_NONE;
}


