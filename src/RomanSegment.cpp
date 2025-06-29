#include "RomanSegment.h"

#include "RomanDigitConverter.h"

int RomanSegment::ToDecimalNumber() const
{
    int leftDecimalNumber = RomanDigitConverter::ToDecimal(_leftRomanDigit);
    int rightDecimalNumber = RomanDigitConverter::ToDecimal(_rightRomanDigit);
    if (IsSubtractivePair())
    {
        return rightDecimalNumber - leftDecimalNumber;
    }

    return leftDecimalNumber;
}

bool RomanSegment::IsSubtractivePair() const
{
    return _rightRomanDigit > 0;
}
