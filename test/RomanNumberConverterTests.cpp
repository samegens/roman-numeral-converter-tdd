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

class RomanNumberConverterParamTest : public ::testing::TestWithParam<TestParam>
{
protected:
    RomanNumberConverter sut;
};

TEST_P(RomanNumberConverterParamTest, ComputesCorrectRomanNumberConverter)
{
    // Arrange
    auto [input, expected] = GetParam();

    // Act
    int actual = sut.ToDecimal(input);

    // Assert
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanNumberConverterValues,
    RomanNumberConverterParamTest,
    ::testing::Values(
        TestParam{"I", 1}
    )
);
