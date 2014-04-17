/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <nds.h>
#include "./input.h"

#include <cstdio>

class InputComponent
{
    public: 
        InputComponent(); 
        InputComponent(Input const &input);
        ~InputComponent(); 

    private: 
        std::shared_ptr<uint32 const> const keyData; 
        std::shared_ptr<touchPosition const> const touchData;

};

#endif
