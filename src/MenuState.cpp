#include <nds.h>
#include "MenuState.h"
#include "GUI.h"

namespace MenuState
{
    void onInit()
    {
        setBrightness(3, 0); //ensure we're at normal brightness after our fade shenanigans

        lcdMainOnTop(); //main engine is the 3D one which we want on upper screen. Sub engine for 2D stuff.
        videoSetMode(MODE_5_3D);
        videoSetModeSub(MODE_5_2D);

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
