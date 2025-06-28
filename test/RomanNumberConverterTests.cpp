#include "RomanNumberConverter.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace std;

class RomanNumberConverterTest : public ::testing::Test
{
protected:
    RomanNumberConverter sut;
};

TEST_F(RomanNumberConverterTest, ThrowsOnEmptyInput)
{
    EXPECT_THROW(sut.ToDecimal(""), std::invalid_argument);
}

struct TestParam
{
    string input;
    int expected;
};

// Overload the PrintTo function to provide a custom output format for the test parameters.
void PrintTo(const TestParam& param, std::ostream* os)
{
    *os << "input: \"" << param.input << "\", expected: " << param.expected;
}

class RomanNumberConverterSingleDigitTest : public ::testing::TestWithParam<TestParam>
{
protected:
    RomanNumberConverter sut;
};

TEST_P(RomanNumberConverterSingleDigitTest, ComputesCorrectDecimalNumber)
{
    // Arrange
    auto [input, expected] = GetParam();

    // Act
    int actual = sut.ToDecimal(input);

    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumberConverterSingleDigitTestValues,
    RomanNumberConverterSingleDigitTest,
    ::testing::Values(
        TestParam{"I", 1},
        TestParam{"V", 5},
        TestParam{"X", 10},
        TestParam{"L", 50},
        TestParam{"C", 100},
        TestParam{"D", 500},
        TestParam{"M", 1000}
    )
);
