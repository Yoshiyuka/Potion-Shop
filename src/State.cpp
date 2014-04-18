/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "./State.h"

void StateMachine::setState(unsigned int const &state)
{
    flags |= state;
}

void StateMachine::toggleState(unsigned int const &state)
{
    flags ^= state;
}

void StateMachine::clearState(unsigned int const &state)
{
    flags &= ~state;
}

bool StateMachine::isStateSet(unsigned int const &state) const
{
    return ((flags & state) == state);
}
