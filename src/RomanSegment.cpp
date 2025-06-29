#include "RomanSegment.h"

RomanSegment::RomanSegment(const RomanDigit &leftDigit, const RomanDigit &rightDigit) : _leftRomanDigit(leftDigit),
                                                                                        _rightRomanDigit(rightDigit)
{
}

RomanSegment::RomanSegment(const RomanDigit &leftDigit) : _leftRomanDigit(leftDigit),
                                                          _rightRomanDigit(std::nullopt)
{
}

int RomanSegment::ToDecimalNumber() const
{
    if (IsSubtractivePair())
    {
        return _rightRomanDigit.value().ToDecimalNumber() - _leftRomanDigit.ToDecimalNumber();
    }

    return _leftRomanDigit.ToDecimalNumber();
}

bool RomanSegment::IsSubtractivePair() const
{
    return _rightRomanDigit.has_value();;
}
