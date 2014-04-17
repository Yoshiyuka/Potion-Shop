/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <nds.h>
#include "./input.h"
#include "./entity.h"
#include "splash.h"

void processInput()
{
}

void update()
{
}

void render()
{
}

void onVBlank()
{
   scanKeys();
}

void onHBlank()
{

}

int main(int argc, char **argv)
{
    videoSetMode(MODE_5_2D); //top screen
    videoSetModeSub(MODE_0_2D); //bottom screen

    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

    int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

    dmaCopy(splashBitmap, bgGetGfxPtr(bg3), 256*256);
    dmaCopy(splashPal, BG_PALETTE, 256*2);

    while(1)
    {
        processInput();
        update();
        render();

        swiWaitForVBlank();
    }
    return 0;
}
