#include "RomanNumberConverter.h"

#include <stdexcept>

int RomanNumberConverter::ToDecimal(const std::string &roman_numeral) const
{
    if (roman_numeral.empty())
    {
        throw std::invalid_argument("Input cannot be empty");
    }

    if (roman_numeral == "I")
    {
        return 1;
    }
    else if (roman_numeral == "V")
    {
        return 5;
    }
    else if (roman_numeral == "X")
    {
        return 10;
    }
    else if (roman_numeral == "L")
    {
        return 50;
    }
    else if (roman_numeral == "C")
    {
        return 100;
    }
    else if (roman_numeral == "D")
    {
        return 500;
    }
    else if (roman_numeral == "M")
    {
        return 1000;
    }

    return 0;
}
