#include <iostream>
#include "myvector.hpp"

int main() {
    MyVector v;

    std::cout << "== init with capacity 2 ==\n";
    myvector_init(&v, 2);
    std::cout << "size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== push_back 10,20,30,40 (force resize) ==\n";
    myvector_push_back(&v, 10);
    myvector_push_back(&v, 20);
    myvector_push_back(&v, 30);
    myvector_push_back(&v, 40);
    myvector_print(&v);
    std::cout << " size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== insert at index 2 (99) ==\n";
    myvector_insert(&v, 2, 99);
    myvector_print(&v);
    std::cout << " size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== erase at index 1 ==\n";
    myvector_erase(&v, 1);
    myvector_print(&v);
    std::cout << " size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== pop_back ==\n";
    myvector_pop_back(&v);
    myvector_print(&v);
    std::cout << " size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== clear ==\n";
    myvector_clear(&v);
    myvector_print(&v);
    std::cout << " size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n\n";

    std::cout << "== destroy ==\n";
    myvector_destroy(&v);
    std::cout << "size=" << myvector_size(&v)
              << " capacity=" << myvector_capacity(&v) << "\n";

    return 0;
}

