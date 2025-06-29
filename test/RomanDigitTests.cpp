#include "RomanDigit.h"
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

struct RomanDigitConversionTestParam
{
    char romanDigit;
    int expected;
};

void PrintTo(const RomanDigitConversionTestParam& param, std::ostream* os)
{
    *os << "romanDigit: '" << param.romanDigit << "', expected: " << param.expected;
}

class RomanDigitConversionTest : public ::testing::TestWithParam<RomanDigitConversionTestParam>
{
protected:
};

TEST_P(RomanDigitConversionTest, ReturnsCorrectDecimalNumber)
{
    // Arrange
    auto [romanDigit, expected] = GetParam();
    RomanDigit digit(romanDigit);
    
    // Act
    int actual = digit.ToDecimalNumber();
    
    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    ValidRomanDigitValues,
    RomanDigitConversionTest,
    ::testing::Values(
        RomanDigitConversionTestParam{'I', 1},
        RomanDigitConversionTestParam{'V', 5},
        RomanDigitConversionTestParam{'X', 10},
        RomanDigitConversionTestParam{'L', 50},
        RomanDigitConversionTestParam{'C', 100},
        RomanDigitConversionTestParam{'D', 500},
        RomanDigitConversionTestParam{'M', 1000}
    )
);

struct RomanDigitComparisonTestParam
{
    char smallerRomanDigit;
    char largerRomanDigit;
    bool expected;
};

void PrintTo(const RomanDigitComparisonTestParam& param, std::ostream* os)
{
    *os << "'" << param.smallerRomanDigit << "' < '" << param.largerRomanDigit << "', expected: " << param.expected;
}

class RomanDigitComparisonTest : public ::testing::TestWithParam<RomanDigitComparisonTestParam>
{
protected:
};

TEST_P(RomanDigitComparisonTest, ComparisonReturnsExpectedResult)
{
    // Arrange
    auto [smallerRomanDigit, largerRomanDigit, expected] = GetParam();
    RomanDigit firstDigit(smallerRomanDigit);
    RomanDigit secondDigit(largerRomanDigit);
    
    // Act
    bool actual = firstDigit < secondDigit;
    
    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanDigitComparisonValues,
    RomanDigitComparisonTest,
    ::testing::Values(
        // Smaller < Larger should be true
        RomanDigitComparisonTestParam{'I', 'V', true},
        RomanDigitComparisonTestParam{'I', 'X', true},
        RomanDigitComparisonTestParam{'V', 'X', true},
        RomanDigitComparisonTestParam{'X', 'L', true},
        RomanDigitComparisonTestParam{'L', 'C', true},
        RomanDigitComparisonTestParam{'C', 'D', true},
        RomanDigitComparisonTestParam{'D', 'M', true},
        // Larger < Smaller should be false
        RomanDigitComparisonTestParam{'V', 'I', false},
        RomanDigitComparisonTestParam{'X', 'V', false},
        RomanDigitComparisonTestParam{'M', 'D', false},
        // Equal should be false
        RomanDigitComparisonTestParam{'I', 'I', false},
        RomanDigitComparisonTestParam{'V', 'V', false},
        RomanDigitComparisonTestParam{'X', 'X', false}
    )
);

class RomanDigitInvalidTest : public ::testing::Test
{
protected:
};

TEST_F(RomanDigitInvalidTest, ThrowsExceptionForInvalidDigit)
{
    // Act & Assert
    EXPECT_THROW(RomanDigit('Z'), std::invalid_argument);
}