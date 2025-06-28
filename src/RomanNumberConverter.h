#pragma once

#include <string>

class RomanNumberConverter
{
public:
    RomanNumberConverter() = default;

    int ToDecimal(const std::string &roman_numeral) const;
};