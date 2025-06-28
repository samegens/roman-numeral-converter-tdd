#include "RomanNumberConverter.h"

#include <stdexcept>

int RomanNumberConverter::ToDecimal(const std::string &roman_numeral) const
{
    if (roman_numeral.empty())
    {
        throw std::invalid_argument("Input cannot be empty");
    }

    return 0;
}
