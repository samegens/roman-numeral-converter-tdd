#include "RomanDigitConverter.h"

int RomanDigitConverter::ToDecimal(const char roman_numeral)
{
    if (roman_numeral == 'I')
    {
        return 1;
    }
    else if (roman_numeral == 'V')
    {
        return 5;
    }
    else if (roman_numeral == 'X')
    {
        return 10;
    }
    else if (roman_numeral == 'L')
    {
        return 50;
    }
    else if (roman_numeral == 'C')
    {
        return 100;
    }
    else if (roman_numeral == 'D')
    {
        return 500;
    }
    else if (roman_numeral == 'M')
    {
        return 1000;
    }
    return 0;
}