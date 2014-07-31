#include "SplashState.h"
#include <nds.h>
#include "splash.h"

namespace SplashState
{
    void onInit()
    {
        videoSetMode(MODE_5_2D);
        videoSetModeSub(MODE_0_2D);

        vramSetBankA(VRAM_A_MAIN_BG);
        vramSetBankC(VRAM_C_SUB_BG);

        int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

        dmaCopy(splashBitmap, bgGetGfxPtr(bg3), 256*256);
        dmaCopy(splashPal, BG_PALETTE, 256*2);
    }

    void onUpdate()
    {
    }

    void onDestroy()
    {
    }
}
