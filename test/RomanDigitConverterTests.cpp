#include "RomanDigitConverter.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

struct RomanDigitConverterTestParam
{
    char input;
    int expected;
};

// Overload the PrintTo function to provide a custom output format for the test parameters.
void PrintTo(const RomanDigitConverterTestParam& param, std::ostream* os)
{
    *os << "input: \"" << param.input << "\", expected: " << param.expected;
}

class RomanDigitConverterTest : public ::testing::TestWithParam<RomanDigitConverterTestParam>
{
protected:
    RomanDigitConverter sut;
};

TEST_P(RomanDigitConverterTest, ComputesCorrectDecimalNumber)
{
    // Arrange
    auto [input, expected] = GetParam();

    // Act
    int actual = sut.ToDecimal(input);

    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanDigitConverterTestValues,
    RomanDigitConverterTest,
    ::testing::Values(
        RomanDigitConverterTestParam{'I', 1},
        RomanDigitConverterTestParam{'V', 5},
        RomanDigitConverterTestParam{'X', 10},
        RomanDigitConverterTestParam{'L', 50},
        RomanDigitConverterTestParam{'C', 100},
        RomanDigitConverterTestParam{'D', 500},
        RomanDigitConverterTestParam{'M', 1000}
    )
);
