#include "mathlib/math_operations.h"

#include <cstdint>
#include <limits>
#include <stdexcept>

namespace {
    constexpr std::uint64_t kMaxFactorialInput = 20ULL;
}

namespace mathlib {
    std::int64_t add(std::int64_t lhs, std::int64_t rhs) {
        if (rhs > 0 && lhs > std::numeric_limits<std::int64_t>::max() - rhs) {
            throw std::overflow_error("Overflow detected");
        }
        if (rhs < 0 && lhs < std::numeric_limits<std::int64_t>::min() - rhs) {
            throw std::overflow_error("Overflow detected");
        }
        return lhs + rhs;
    }

    std::int64_t subtract(std::int64_t lhs, std::int64_t rhs) {
        return add(lhs, -rhs);
    }

    std::int64_t multiply(std::int64_t lhs, std::int64_t rhs) {
        if (lhs == 0 || rhs == 0) {
            return 0;
        }
        if (lhs > 0) {
            if (rhs > 0 && lhs > std::numeric_limits<std::int64_t>::max() / rhs) {
                throw std::overflow_error("Overflow detected");
            }
            if (rhs < 0 && rhs < std::numeric_limits<std::int64_t>::min() / lhs) {
                throw std::overflow_error("Overflow detected");
            }
        } else {
            if (rhs > 0 && lhs < std::numeric_limits<std::int64_t>::min() / rhs) {
                throw std::overflow_error("Overflow detected");
            }
            if (rhs < 0 && lhs < std::numeric_limits<std::int64_t>::max() / rhs) {
                throw std::overflow_error("Overflow detected");
            }
        }
        return lhs * rhs;
    }

    std::int64_t divide(std::int64_t lhs, std::int64_t rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Division by zero");
        }
        if (lhs == std::numeric_limits<std::int64_t>::min() && rhs == -1) {
            throw std::overflow_error("Overflow detected");
        }
        return lhs / rhs;
    }

    std::int64_t power(std::int64_t base, std::int64_t exponent) {
        if (exponent < 0) {
            throw std::invalid_argument("Negative exponent not supported");
        }

        std::int64_t result = 1;
        for (std::int64_t i = 0; i < exponent; ++i) {
            result = multiply(result, base);
        }
        return result;
    }

    std::uint64_t factorial(std::int64_t n) {
        if (n < 0) {
            throw std::invalid_argument("Factorial is not defined for negative numbers");
        }
        if (n > kMaxFactorialInput) {
            throw std::overflow_error("Factorial exceeds uint64_t range");
        }

        if (n == 0 || n == 1) {
            return 1ULL;
        }
        return static_cast<std::uint64_t>(n) * factorial(n - 1);
    }
} // namespace mathlib
