#pragma once
using Byte = unsigned char;

namespace MathClasses
{
    struct Colour
    {
    public:
        unsigned int colour; //this is the "colour value integer"

    public:
        Colour() : colour(0x000000FF) {}

        Colour(Byte red, Byte green, Byte blue, Byte alpha) 
        {
            SetRed(red);
            SetGreen(green);
            SetBlue(blue);
            SetAlpha(alpha);
        }

        Byte GetRed() const {
            return (colour >> 24) & 0xFF;
        }

        void SetRed(Byte red) {
            colour = (colour & 0x00FFFFFF) | (red << 24);
        }

        // Getter and setter for the green component
        Byte GetGreen() const {
            return (colour >> 16) & 0xFF;
        }

        void SetGreen(Byte green) {
            colour = (colour & 0xFF00FFFF) | (green << 16);
        }

        // Getter and setter for the blue component
        Byte GetBlue() const {
            return (colour >> 8) & 0xFF;
        }

        void SetBlue(Byte blue) {
            colour = (colour & 0xFFFF00FF) | (blue << 8);
        }

        // Getter and setter for the alpha component
        Byte GetAlpha() const {
            return colour & 0xFF;
        }

        void SetAlpha(Byte alpha) {
            colour = (colour & 0xFFFFFF00) | alpha;
        }

        // Equality operator
        bool operator==(const Colour& other) const {
            return colour == other.colour;
        }

        // Inequality operator
        bool operator!=(const Colour& other) const {
            return !(*this == other);
        }
    };
}