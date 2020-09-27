#include "math.hpp"
#include "cmath"

using namespace bigfloat;

bf math::sqrt(const bf x) {
    if (x.sign()) return bf::nan(false);

    // Double-impl guess gives us 52 bits.
    auto guess = bf(std::sqrt(double(x)));

    // Single step of the Babylonian method, which converges quadratically, gives us 104 bits.
    auto secondary = x / guess;
    return (guess + secondary) / 2;
}

bf math::exp(const bf x) {
    // Calculate a point for the linear approximation
    auto y0 = bf(std::exp(double(x)));

    // Results of double conversion
    auto x0 = bf(x.exponent, x.mantissa & ~0x7ff);

    // Perform a linear approximation. Note that d/dx e^x = e^x, giving us the slope.
    return y0 * (x - x0) + y0;
}

bf math::log(const bf x) {
    if (x.sign()) return bf::nan(false);

    // Calculate a point for the linear approximation
    auto y0 = bf(std::log(double(x)));

    // Results of double conversion
    auto x0 = bf(x.exponent, x.mantissa & ~0x7ff);

    // Perform a linear approximation. Note that d/dx log(x) = 1/x, giving us the slope.
    return (bf(1) / x) * (x - x0) + y0;
}

bf math::pow(const bf b, const bf p) {
    return bf();
}

bf math::pow(const bf b, unsigned int p) {
    // Exponentiation by squaring
    bf acc = 1;
    bf fac = b;
    while (p > 0) {
        if (p & 1) {
            acc *= fac;
        }
        p >>= 1;
        fac *= b;
    }
    return acc;
}

bf math::sin(const bf x) {
    return bf();
}

bf math::cos(const bf x) {
    return bf();
}
