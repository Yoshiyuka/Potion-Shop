/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef STATE_H
#define STATE_H

//Originally wanted to do templated state machines to support bitfields of various sizes (char/short/int)
//It's quicker to just implement a single type and keep it simple though. Avoid premature optimization.

enum class GameState
{
    STATE_NONE = 0,
    STATE_INIT,
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSED,
};

#endif

