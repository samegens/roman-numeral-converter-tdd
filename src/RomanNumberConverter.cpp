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
        int current_value = GetDigitValue(roman_number[i]);
        
        if (IsSubtractionCase(roman_number, i))
        {
            int next_value = GetDigitValue(roman_number[i + 1]);
            decimal_number += (next_value - current_value);
            ++i; // Skip next digit
        }
        else
        {
            decimal_number += current_value;
        }
    }
    
    return decimal_number;
}

bool RomanNumberConverter::IsSubtractionCase(const std::string& roman_number, size_t index) const
{
    const int next_index = index + 1;
    if (next_index >= roman_number.size())
        return false;
        
    int current = GetDigitValue(roman_number[index]);
    int next = GetDigitValue(roman_number[next_index]);
    
    return current < next;
}

int RomanNumberConverter::GetDigitValue(char digit) const
{
    int value = RomanDigitConverter::ToDecimal(digit);
    if (value == 0)
    {
        throw std::invalid_argument("Invalid Roman numeral: " + std::string(1, digit));
    }
    return value;
}