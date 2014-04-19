/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "./input.h"

Input::Input() : touchEnabled(false)
{
}

Input::~Input()
{
}

void Input::processInput()
{
    scanKeys(); //must be called once per main game loop to enable keypad usage.
    keyData = keysDown();

    if(touchEnabled)
    {
        touchRead(&touchData);
    }
}

void Input::toggleTouchpad()
{
    touchEnabled = !touchEnabled;
}

void Input::enableTouchpad()
{
    touchEnabled = true;
}

void Input::disableTouchpad()
{
    touchEnabled = false;
}

//return a const shared pointer to const keypad data. Guarantee this function won't modify anything in the class.
uint32 const * const Input::watchKeyData() const
{
    //std::weak_ptr<uint32 const> result(&keys);
    return &keyData;
}

//return a const shared pointer to const touch data. Guarantee this function won't modify anything in the class. 
touchPosition const * const Input::watchTouchData() const
{
    //std::weak_ptr<touchPosition const> result(touchData.get());
    return &touchData;
}
