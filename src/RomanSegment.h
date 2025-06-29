#pragma once

/// @brief Represents a segment of a Roman numeral, which can be a single digit or a subtractive pair.
class RomanSegment
{
public:
    RomanSegment(char leftDigit, char rightDigit = '\0') : _leftRomanDigit(leftDigit),
                                                           _rightRomanDigit(rightDigit)
    {
    }

    int ToDecimalNumber() const;

private:
    bool IsSubtractivePair() const;

    char _leftRomanDigit;
    char _rightRomanDigit;
};
