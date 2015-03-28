#include "Font.h"

Font::Font()
{
}

int Font::load(glImage *glyphs, const unsigned int numFrames, const unsigned int *uvCoords, GL_TEXTURE_TYPE_ENUM type, int width, int height, int param, int paletteLength, const u16 *palette, const uint8 *texture)
{
    this->glyphs = glyphs; //should probably fail here if glyphs is null...

    int textureID = glLoadSpriteSet(this->glyphs, numFrames, uvCoords, type, width, height, param, paletteLength, palette, texture);

    return textureID; 
}

void Font::print(int x, int y, const std::string text)
{
    short font_char;
    std::string::const_iterator itr; 
    for(itr = text.begin(); itr != text.end(); itr++)
    {
        font_char = ( *itr ) - 32;
        glSprite(x, y, GL_FLIP_NONE, &glyphs[font_char]);
        x += glyphs[font_char].width;
    }
}

void Font::printCentered(int x, int y, const std::string text)
{
    short font_char;
    int totalWidth = 0;
    
    for(auto itr = text.begin(); itr != text.end(); itr++)
    {
        font_char = (*itr) - 32; 
        totalWidth += glyphs[font_char].width - 8;
    }

    x = (256 - totalWidth) / 2;

    for(auto itr = text.begin(); itr != text.end(); itr++)
    {
        font_char = (*itr) - 32;
        glSprite(x, y, GL_FLIP_NONE, &glyphs[font_char]);
        x += glyphs[font_char].width - 8;
    }
}
