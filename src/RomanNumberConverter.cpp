#include "RomanNumberConverter.h"

#include "RomanDigitConverter.h"

#include <stdexcept>

int RomanNumberConverter::ToDecimal(const std::string &roman_number) const
{
    if (roman_number.empty())
    {
        throw std::invalid_argument("Input cannot be empty");
    }

    int decimal_number = 0;
    for (const char &roman_digit : roman_number)
    {
        int value = RomanDigitConverter::ToDecimal(roman_digit);
        if (value == 0)
        {
            throw std::invalid_argument("Invalid Roman numeral: " + roman_digit);
        }
        decimal_number += value;
    }

    return decimal_number;
}
