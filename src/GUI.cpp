#include "GUI.h"

GUI::GUI(){}
GUI::~GUI(){}

bool GUI::Button(const int x, const int y, const int width, const int height, const std::string &text)
{
    return true;
}

bool GUI::Radio(const bool active, const int x, const int y, const int width, const int height, const std::string &text)
{
    return true;
}

int GUI::SteppedSlider(const int x, const int y, const int width, const int height, const int steps)
{
    return 0;
}

void GUI::Editable(const int x, const int y, std::string &text)
{
}
