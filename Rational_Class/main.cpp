#include <iostream>
#include "Rational.hpp"
int main() {
    // Constructors
    Rational r1;               // default 0/1
    Rational r2(5);            // 5/1
    Rational r3(2, 3);         // 2/3
    Rational r4(r3);           // copy constructor
    Rational r5(std::move(r2)); // move constructor

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 (moved) = " << r2 << "\n";
    std::cout << "r3 = " << r3 << "\n";
    std::cout << "r4 (copy of r3) = " << r4 << "\n";
    std::cout << "r5 (moved from r2) = " << r5 << "\n\n";

    // Assignment operators
    Rational r6;
    r6 = r3; // copy assignment
    Rational r7;
    r7 = std::move(r6); // move assignment

    std::cout << "r6 = " << r6 << "\n";
    std::cout << "r7 = " << r7 << "\n\n";

    // Unary operators
    Rational r8(3, 4);
    std::cout << "+r8 = " << +r8 << "\n";
    std::cout << "-r8 = " << -r8 << "\n";

    std::cout << "++r8 = " << ++r8 << "\n";
    std::cout << "r8++ = " << r8++ << " (after: " << r8 << ")\n";
    std::cout << "--r8 = " << --r8 << "\n";
    std::cout << "r8-- = " << r8-- << " (after: " << r8 << ")\n";

    std::cout << "!r1 = " << !r1 << "\n";
    std::cout << "!r8 = " << !r8 << "\n\n";

    // Compound assignment operators
    Rational r9(1, 2);
    Rational r10(1, 3);

    r9 += r10;
    std::cout << "r9 += r10 -> " << r9 << "\n";

    r9 -= r10;
    std::cout << "r9 -= r10 -> " << r9 << "\n";

    r9 *= r10;
    std::cout << "r9 *= r10 -> " << r9 << "\n";

    r9 /= r10;
    std::cout << "r9 /= r10 -> " << r9 << "\n\n";

    // Binary operators
    Rational r11 = r9 + r10;
    Rational r12 = r9 - r10;
    Rational r13 = r9 * r10;
    Rational r14 = r9 / r10;

    std::cout << "r11 = r9 + r10 -> " << r11 << "\n";
    std::cout << "r12 = r9 - r10 -> " << r12 << "\n";
    std::cout << "r13 = r9 * r10 -> " << r13 << "\n";
    std::cout << "r14 = r9 / r10 -> " << r14 << "\n\n";

    // Comparison operators
    std::cout << std::boolalpha;
    std::cout << "r9 == r10 ? " << (r9 == r10) << "\n";
    std::cout << "r9 != r10 ? " << (r9 != r10) << "\n";
    std::cout << "r9 > r10 ? " << (r9 > r10) << "\n";
    std::cout << "r9 < r10 ? " << (r9 < r10) << "\n";
    std::cout << "r9 >= r10 ? " << (r9 >= r10) << "\n";
    std::cout << "r9 <= r10 ? " << (r9 <= r10) << "\n\n";

    // Conversion to double
    double d = static_cast<double>(r9);
    std::cout << "r9 as double = " << d << "\n\n";

    // Stream operators
    Rational r_input;
    std::cout << "Enter a rational number (numerator denominator): ";
    std::cin >> r_input;
    std::cout << "You entered: " << r_input << "\n";

    return 0;
}

