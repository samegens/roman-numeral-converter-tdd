#pragma once

#include "RomanDigit.h"

#include <string>
#include <vector>

using namespace std;

/// @brief Converts Roman numerals (like 'IV', 'XII', 'MCMXCIV') to decimal numbers (like 4, 12, 1994).
class RomanNumberConverter
{
public:
    RomanNumberConverter() = default;

    int ToDecimal(const string &romanNumber);

private:
    int ProcessNextRomanSegment();
    int GetDigitValue(char digit) const;
    bool IsSubtractionCase(size_t index) const;

    vector<RomanDigit> _romanDigits;
    string _romanNumber;
    size_t _currentRomanDigitIndex = 0;
};
