#include <iostream>
#include "Manual.hpp"


int main() {
    Virtualizable* v = new Derived;

    if (Derived* d = dinamicCast<Derived>(v)) {
        std::cout << "asxhatuma-";
    }

    if (Base* b = dinamicCast<Base>(v)) {
        std::cout << "esela ashxatum";
    }

    return 0;
}
