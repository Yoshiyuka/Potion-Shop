#include <nds.h>
#include <gl2d.h>
#include "MenuState.h"
#include "GUI.h"
#include "Font.h"
#include "uvcoord_glyphs.h"
//#include "glyphs.h"

//#include "button.h"

namespace MenuState
{

    void onInit()
    {
        glImage fontGlyphs[FONT_16X16_NUM_IMAGES];
        Font font;
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
        font.load(fontGlyphs, FONT_16X16_NUM_IMAGES, font_16x16_texcoords, GL_RGB256, TEXTURE_SIZE_64, TEXTURE_SIZE_512, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT, 256, (u16*)glyphsPal, (u8*)glyphsBitmap);
 
        glLoadTileSet(Button, 64, 32, 64, 32, GL_RGB16, TEXTURE_SIZE_64, TEXTURE_SIZE_32, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF, 16, (u16*)buttonPal, (u8*)buttonBitmap);

        //temporary rendering for menu. Move to appropriate place later.
        while(1)
        {
             glBegin2D();
                glSpriteStretchHorizontal(64, 32, 128, Button);
                font.printCentered(0, 32 + 8, "NEW GAME"); //button height + 1/4 button height to center.
                glSpriteStretchHorizontal(64, 64 + 16, 128, Button);
                font.printCentered(0, 64+24, "LOAD GAME");
                glSpriteStretchHorizontal(64, 96 + 32, 128, Button);
                font.printCentered(0, 96+40, "OPTIONS");
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
