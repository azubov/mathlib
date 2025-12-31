#include "mathlib/math_operations.h"

#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <stdexcept>

TEST(MathlibTest, sum) {
    EXPECT_EQ(mathlib::add(3, 5), 8);
    EXPECT_THROW(mathlib::add(std::numeric_limits<std::int64_t>::max(), 1), std::overflow_error);
}

TEST(MathlibTest, subtraction) {
    EXPECT_EQ(mathlib::subtract(10, 7), 3);
    EXPECT_THROW(mathlib::subtract(std::numeric_limits<std::int64_t>::min(), 1), std::overflow_error);
}

TEST(MathlibTest, multiplication) {
    EXPECT_EQ(mathlib::multiply(2, 3), 6);
    EXPECT_THROW(mathlib::multiply(std::numeric_limits<std::int64_t>::max(), 2), std::overflow_error);
}

TEST(MathlibTest, division) {
    EXPECT_EQ(mathlib::divide(10, 2), 5);
    EXPECT_THROW(mathlib::divide(1, 0), std::invalid_argument);
    EXPECT_THROW(mathlib::divide(std::numeric_limits<std::int64_t>::min(), -1), std::overflow_error);
}

TEST(MathlibTest, exponentiation) {
    EXPECT_EQ(mathlib::power(2, 3), 8);
    EXPECT_THROW(mathlib::power(2, 63), std::overflow_error);
}

TEST(MathlibTest, factorial) {
    EXPECT_EQ(mathlib::factorial(4), 24ULL);
    EXPECT_THROW(mathlib::factorial(-1), std::invalid_argument);
    EXPECT_THROW(mathlib::factorial(21), std::overflow_error);
}
