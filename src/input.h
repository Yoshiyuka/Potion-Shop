/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef INPUT_H
#define INPUT_H

#include <nds.h>
#include <memory>

class Input
{
    public: 
        Input();
        ~Input();

        void processInput();

        void toggleTouchpad();
        void enableTouchpad();
        void disableTouchpad();

        //return read-only pointers to private data in this class. Allows outside classes to peek, but not alter.
        std::weak_ptr<uint32 const> const watchKeyData() const; 
        std::weak_ptr<touchPosition const> const watchTouchData() const;

    private:
        std::shared_ptr<uint32> keyData; //bitmask of all held keys on keypad
        bool touchEnabled; //enable/disable touchpad

        std::shared_ptr<touchPosition> touchData;
};

#endif
