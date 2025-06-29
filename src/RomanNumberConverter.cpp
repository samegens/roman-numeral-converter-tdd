#include "RomanNumberConverter.h"

#include "RomanDigitConverter.h"

#include <stdexcept>

using namespace std;

int RomanNumberConverter::ToDecimal(const string &romanNumber)
{
    if (romanNumber.empty())
    {
        throw std::invalid_argument("Input cannot be empty");
    }

    _romanNumber = romanNumber;
    int decimalNumber = 0;
    for (_currentRomanDigitIndex = 0; _currentRomanDigitIndex < romanNumber.size(); )
    {
        decimalNumber += ProcessNextRomanSegment();
    }
    
    return decimalNumber;
}

int RomanNumberConverter::ProcessNextRomanSegment()
{
    if (IsSubtractionCase(_romanNumber, _currentRomanDigitIndex))
    {
        int current = GetDigitValue(_romanNumber[_currentRomanDigitIndex]);
        int next = GetDigitValue(_romanNumber[_currentRomanDigitIndex + 1]);
        _currentRomanDigitIndex += 2;
        return next - current;
    }
    else
    {
        int current = GetDigitValue(_romanNumber[_currentRomanDigitIndex]);
        _currentRomanDigitIndex += 1;
        return current;
    }
}

bool RomanNumberConverter::IsSubtractionCase(const string& romanNumber, size_t index) const
{
    const int next_index = index + 1;
    if (next_index >= romanNumber.size())
        return false;
        
    int current = GetDigitValue(romanNumber[index]);
    int next = GetDigitValue(romanNumber[next_index]);
    
    return current < next;
}

int RomanNumberConverter::GetDigitValue(char digit) const
{
    int value = RomanDigitConverter::ToDecimal(digit);
    if (value == 0)
    {
        throw std::invalid_argument("Invalid Roman numeral: " + string(1, digit));
    }
    return value;
}