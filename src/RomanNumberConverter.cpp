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
    
    return 0;
}
