#pragma once

#include <string>

using namespace std;

/// @brief Converts Roman numerals (like 'IV', 'XII', 'MCMXCIV') to decimal numbers (like 4, 12, 1994).
class RomanNumberConverter
{
public:
    RomanNumberConverter() = default;

    int ToDecimal(const string &romanNumeral);

private:
    int ProcessNextRomanSegment();
    int GetDigitValue(char digit) const;
    bool IsSubtractionCase(const string &romanNumber, size_t index) const;

    string _romanNumber;
    size_t _currentRomanDigitIndex = 0;
};
