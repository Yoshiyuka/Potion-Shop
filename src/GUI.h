#include <string>

class GUI
{
    public: 
        GUI();
        ~GUI();

        bool Button(const int x, const int y, const int width, const int height, const std::string &text);
        bool Radio(const bool active, const int x, const int y, const int width, const int height, const std::string &text);
        int SteppedSlider(const int x, const int y, const int width, const int height, const int steps);
        void Editable(const int x, const int y, std::string &text);
};
