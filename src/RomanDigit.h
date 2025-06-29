#pragma once

class RomanDigit {
public:
    RomanDigit(char romanDigit);
    
    int ToDecimalNumber() const;
    bool operator<(const RomanDigit& other) const;

private:
    int ConvertToDecimalNumber() const;

    char _romanDigit;
    int _decimalNumber;
};
