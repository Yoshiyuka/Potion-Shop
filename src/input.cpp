/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "./input.h"

Input::Input() : keys(0), touchEnabled(false), touchData(new touchPosition)
{
}

Input::~Input()
{
}

void Input::processInput()
{
    scanKeys(); //must be called once per main game loop to enable keypad usage.
    keys = keysDown();

    if(touchEnabled)
    {
        touchRead(touchData.get());
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
std::shared_ptr<uint32 const> const Input::watchKeyData() const
{
    std::shared_ptr<uint32 const> result(&keys); 
    return result;
}

//return a const shared pointer to const touch data. Guarantee this function won't modify anything in the class. 
std::shared_ptr<touchPosition const> const Input::watchTouchData() const
{
    std::shared_ptr<touchPosition const> result(touchData.get());
    return result;
}
