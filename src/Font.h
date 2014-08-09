#ifndef FONT_H
#define FONT_H

#include <nds.h>
#include <gl2d.h>
#include <string>

class Font
{
    public: 
        Font();
        int load(glImage *glyphs, const unsigned int numFrames, const unsigned int *uvCoords, GL_TEXTURE_TYPE_ENUM type, int width, int height, int param, int paletteLength, const u16 *palette, const uint8 *texture);

        void print(int x, int y, const std::string text);
        void printCentered(int x, int y, const std::string text);

    private: 
        glImage *glyphs;
};

#endif
