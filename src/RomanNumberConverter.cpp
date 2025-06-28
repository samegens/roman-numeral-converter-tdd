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
    for (size_t i = 0; i < roman_number.size(); ++i)
    {
        int current_value = RomanDigitConverter::ToDecimal(roman_number[i]);
        if (current_value == 0)
        {
            throw std::invalid_argument("Invalid Roman numeral: " + std::string(1, roman_number[i]));
        }
        
        // Look ahead: if current < next, subtract current from next
        if (i + 1 < roman_number.size())
        {
            int next_value = RomanDigitConverter::ToDecimal(roman_number[i + 1]);
            if (current_value < next_value)
            {
                decimal_number += (next_value - current_value);
                ++i; // Skip next character since we processed it
                continue;
            }
        }
        
        // Normal additive case
        decimal_number += current_value;
    }
    
    return decimal_number;
}
