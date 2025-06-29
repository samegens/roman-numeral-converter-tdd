#pragma once

#include "RomanDigit.h"

#include <optional>

using namespace std;

/// @brief Represents a segment of a Roman numeral, which can be a single digit or a subtractive pair.
class RomanSegment
{
public:
    RomanSegment(const RomanDigit &leftDigit, const RomanDigit &rightDigit);
    RomanSegment(const RomanDigit &leftDigit);

    int ToDecimalNumber() const;

private:
    bool IsSubtractivePair() const;

    RomanDigit _leftRomanDigit;
    optional<RomanDigit> _rightRomanDigit;
};
