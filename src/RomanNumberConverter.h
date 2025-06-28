#pragma once

#include <string>

class RomanNumberConverter
{
public:
    RomanNumberConverter() = default;

    int ToDecimal(const std::string &roman_numeral) const;

private:
    int GetDigitValue(char digit) const;
    bool IsSubtractionCase(const std::string &roman_number, size_t index) const;
};