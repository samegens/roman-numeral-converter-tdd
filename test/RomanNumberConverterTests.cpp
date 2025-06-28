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

// class RomanNumberConverterParamTest : public ::testing::TestWithParam<FibParam>
// {
// protected:
//     RomanNumberConverter sut;
// };

// TEST_P(RomanNumberConverterParamTest, ComputesCorrectRomanNumberConverter)
// {
//     auto [input, expected] = GetParam();
//     EXPECT_EQ(sut.compute(input), expected);
// }

// INSTANTIATE_TEST_SUITE_P(
//     RomanNumberConverterValues,
//     RomanNumberConverterParamTest,
//     ::testing::Values(
//         TestParam{0, 0},
//         TestParam{1, 1},
//         TestParam{6, 8},
//         TestParam{7, 13},
//         TestParam{8, 21},
//         TestParam{9, 34},
//         TestParam{11, 89}));
