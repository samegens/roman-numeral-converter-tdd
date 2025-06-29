#include "RomanSegment.h"
#include <gtest/gtest.h>

using namespace std;

class RomanSegmentTest : public ::testing::Test
{
protected:
};

struct RomanSegmentTestParam
{
    char left_digit;
    char right_digit;
    int expected;
    string description;
};

void PrintTo(const RomanSegmentTestParam& param, std::ostream* os)
{
    *os << "segment: \"" << param.left_digit;
    if (param.right_digit != '\0') {
        *os << param.right_digit;
    }
    *os << "\", expected: " << param.expected;
}

class RomanSegmentSingleDigitTest : public ::testing::TestWithParam<RomanSegmentTestParam>
{
protected:
};

TEST_P(RomanSegmentSingleDigitTest, ReturnsCorrectDecimalValue)
{
    // Arrange
    auto [left_digit, right_digit, expected, description] = GetParam();
    RomanSegment segment(left_digit);
    
    // Act
    int actual = segment.ToDecimalNumber();
    
    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    SingleDigitValues,
    RomanSegmentSingleDigitTest,
    ::testing::Values(
        RomanSegmentTestParam{'I', '\0', 1, "I"},
        RomanSegmentTestParam{'V', '\0', 5, "V"},
        RomanSegmentTestParam{'X', '\0', 10, "X"},
        RomanSegmentTestParam{'L', '\0', 50, "L"},
        RomanSegmentTestParam{'C', '\0', 100, "C"},
        RomanSegmentTestParam{'D', '\0', 500, "D"},
        RomanSegmentTestParam{'M', '\0', 1000, "M"}
    )
);

class RomanSegmentSubtractiveTest : public ::testing::TestWithParam<RomanSegmentTestParam>
{
protected:
};

TEST_P(RomanSegmentSubtractiveTest, ReturnsCorrectDecimalValue)
{
    // Arrange
    auto [left_digit, right_digit, expected, description] = GetParam();
    RomanSegment segment(left_digit, right_digit);
    
    // Act
    int actual = segment.ToDecimalNumber();
    
    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    SubtractiveValues,
    RomanSegmentSubtractiveTest,
    ::testing::Values(
        RomanSegmentTestParam{'I', 'V', 4, "IV"},
        RomanSegmentTestParam{'I', 'X', 9, "IX"},
        RomanSegmentTestParam{'X', 'L', 40, "XL"},
        RomanSegmentTestParam{'X', 'C', 90, "XC"},
        RomanSegmentTestParam{'C', 'D', 400, "CD"},
        RomanSegmentTestParam{'C', 'M', 900, "CM"}
    )
);