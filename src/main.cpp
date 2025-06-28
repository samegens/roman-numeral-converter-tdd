#include "RomanNumberConverter.h"

#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <roman_numeral>" << endl;
        return 1;
    }

    string roman_input = argv[1];

    auto romanNumberConverter = RomanNumberConverter();
    int decimalNumber = romanNumberConverter.ToDecimal(roman_input);

    cout << decimalNumber << endl;

    return 0;
}
