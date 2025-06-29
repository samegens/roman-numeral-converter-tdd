#pragma once

#include <string>

using namespace std;

/// @brief Converts Roman numerals (like 'IV', 'XII', 'MCMXCIV') to decimal numbers (like 4, 12, 1994).
class RomanNumberConverter
{
public:
    RomanNumberConverter() = default;

    int ToDecimal(const string &roman_numeral) const;

private:
    int GetDigitValue(char digit) const;
    bool IsSubtractionCase(const string &roman_number, size_t index) const;
};