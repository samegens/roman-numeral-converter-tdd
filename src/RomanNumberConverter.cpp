#include "RomanNumberConverter.h"

#include "RomanDigitConverter.h"

#include <stdexcept>
#include "RomanSegment.h"

using namespace std;

int RomanNumberConverter::ToDecimal(const string &romanNumber)
{
    if (romanNumber.empty())
    {
        throw std::invalid_argument("Input cannot be empty");
    }

    _romanDigits.assign(romanNumber.begin(), romanNumber.end());
    int decimalNumber = 0;
    for (_currentRomanDigitIndex = 0; _currentRomanDigitIndex < romanNumber.size(); )
    {
        decimalNumber += ProcessNextRomanSegment();
    }
    
    return decimalNumber;
}

int RomanNumberConverter::ProcessNextRomanSegment()
{
    if (IsSubtractionCase(_currentRomanDigitIndex))
    {
        auto romanSegment = RomanSegment(
            _romanDigits[_currentRomanDigitIndex],
            _romanDigits[_currentRomanDigitIndex + 1]
        );
        _currentRomanDigitIndex += 2;
        return romanSegment.ToDecimalNumber();
    }
    else
    {
        auto romanSegment = RomanSegment(_romanDigits[_currentRomanDigitIndex]);
        _currentRomanDigitIndex += 1;
        return romanSegment.ToDecimalNumber();
    }
}

bool RomanNumberConverter::IsSubtractionCase(size_t index) const
{
    const int next_index = index + 1;
    if (next_index >= _romanDigits.size())
        return false;
        
    RomanDigit current = _romanDigits[index];
    RomanDigit next = _romanDigits[next_index];
    
    return current < next;
}
