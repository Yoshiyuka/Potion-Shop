#include <nds.h>
#include <gl2d.h>
#include "MenuState.h"
#include "GUI.h"

#include "button.h"

namespace MenuState
{

    void onInit()
    {
        glImage Button[1]; //single sprite
        setBrightness(3, 0); //ensure we're at normal brightness after our fade shenanigans

        lcdMainOnBottom(); //main engine is the 3D one which we want on upper screen. Sub engine for 2D stuff.
        videoSetMode(MODE_5_3D);
        videoSetModeSub(MODE_0_2D);

        vramSetBankA(VRAM_A_TEXTURE);
        vramSetBankB(VRAM_B_TEXTURE);
        vramSetBankC(VRAM_C_TEXTURE);
        //vramSetBankC(VRAM_C_SUB_BG);
        //vramSetBankD(VRAM_D_TEXTURE);
        vramSetBankE(VRAM_E_TEX_PALETTE);
        glScreen2D();
 
        glLoadTileSet(Button, 64, 32, 64, 32, GL_RGB16, TEXTURE_SIZE_64, TEXTURE_SIZE_32, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF, 16, (u16*)buttonPal, (u8*)buttonBitmap);

        //temporary rendering for menu. Move to appropriate place later.
        while(1)
        {
             glBegin2D();
                glSpriteStretchHorizontal(64, 32, 128, Button);
                glSpriteStretchHorizontal(64, 64 + 16, 128, Button);
                glSpriteStretchHorizontal(64, 96 + 32, 128, Button);
            glEnd2D();
            glFlush(0);
            swiWaitForVBlank();
        }
    } 

    void onPreUpdate()
    {
    }

    void onUpdate()
    {
    }

    void onDestroy()
    {
    }

    void onVBlank()
    {
    }
}
