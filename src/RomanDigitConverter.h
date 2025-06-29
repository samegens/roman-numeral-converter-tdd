#pragma once

/// @brief Converts a single Roman numeral digit (like 'I', 'V', 'X') to its decimal value (like 1, 5, 10).
class RomanDigitConverter
{
public:
    RomanDigitConverter() = default;

    static int ToDecimal(const char roman_numeral);
};
