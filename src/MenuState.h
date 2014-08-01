#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"

namespace MenuState
{
    void onInit();

    void onPreUpdate();
    void onUpdate();
    void onDestroy();

    void onVBlank();

}

#endif
