
#include <iostream>
#include <cstdint>

class RGBA
{
private:
    std::uint8_t m_red, m_green, m_blue, m_alpha;
public:

    void setRGBA(int red, int green, int blue, int alpha)
    {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }

    RGBA()
    {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }

    RGBA(int red, int green, int blue, int alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    void print(int red, int green, int blue, int alpha)
    {
        std::cout << red << " " << green << " " << blue << " " << alpha;
    }

};

int main()
{
    RGBA value;
    value.setRGBA(0, 0, 0, 255);

    value.print(0, 0, 0, 255);
}