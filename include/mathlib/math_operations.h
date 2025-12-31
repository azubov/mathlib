#pragma once

#include <cstdint>

namespace mathlib {
    std::int64_t add(std::int64_t lhs, std::int64_t rhs);

    std::int64_t subtract(std::int64_t lhs, std::int64_t rhs);

    std::int64_t multiply(std::int64_t lhs, std::int64_t rhs);

    std::int64_t divide(std::int64_t lhs, std::int64_t rhs);

    std::int64_t power(std::int64_t base, std::int64_t exponent);

    std::uint64_t factorial(std::int64_t n);
} // namespace mathlib
