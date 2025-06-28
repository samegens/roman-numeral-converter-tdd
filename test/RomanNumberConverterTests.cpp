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

struct RomanNumberConverterTestParam
{
    string input;
    int expected;
};

// Overload the PrintTo function to provide a custom output format for the test parameters.
void PrintTo(const RomanNumberConverterTestParam& param, std::ostream* os)
{
    *os << "input: \"" << param.input << "\", expected: " << param.expected;
}

class RomanNumberConverterSingleDigitTest : public ::testing::TestWithParam<RomanNumberConverterTestParam>
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
        RomanNumberConverterTestParam{"I", 1},
        RomanNumberConverterTestParam{"V", 5},
        RomanNumberConverterTestParam{"X", 10},
        RomanNumberConverterTestParam{"L", 50},
        RomanNumberConverterTestParam{"C", 100},
        RomanNumberConverterTestParam{"D", 500},
        RomanNumberConverterTestParam{"M", 1000}
    )
);

class RomanNumberConverterMultipleAdditiveDigitTest : public ::testing::TestWithParam<RomanNumberConverterTestParam>
{
protected:
    RomanNumberConverter sut;
};

TEST_P(RomanNumberConverterMultipleAdditiveDigitTest, ComputesCorrectDecimalNumber)
{
    // Arrange
    auto [input, expected] = GetParam();

    // Act
    int actual = sut.ToDecimal(input);

    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumberConverterMultipleAdditiveDigitTestValues,
    RomanNumberConverterMultipleAdditiveDigitTest,
    ::testing::Values(
        RomanNumberConverterTestParam{"II", 2},
        RomanNumberConverterTestParam{"MDCLXVI", 1666}
    )
);

class RomanNumberConverterSubtractiveDigitTest : public ::testing::TestWithParam<RomanNumberConverterTestParam>
{
protected:
    RomanNumberConverter sut;
};

TEST_P(RomanNumberConverterSubtractiveDigitTest, ComputesCorrectDecimalNumber)
{
    // Arrange
    auto [input, expected] = GetParam();

    // Act
    int actual = sut.ToDecimal(input);

    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumberConverterSubtractiveDigitTestValues,
    RomanNumberConverterSubtractiveDigitTest,
    ::testing::Values(
        RomanNumberConverterTestParam{"IV", 4}
    )
);
