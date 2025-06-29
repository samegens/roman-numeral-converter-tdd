#include "RomanDigit.h"

#include <stdexcept>

RomanDigit::RomanDigit(char romanDigit) : _romanDigit(romanDigit)
{
    _decimalNumber = ConvertToDecimalNumber();
}

int RomanDigit::ToDecimalNumber() const
{
    return _decimalNumber;
}

bool RomanDigit::operator<(const RomanDigit& other) const
{
    return _decimalNumber < other._decimalNumber;
}

int RomanDigit::ConvertToDecimalNumber() const
{
    switch (_romanDigit)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            throw std::invalid_argument("Invalid Roman digit: " + std::string(1, _romanDigit));
    }
}
