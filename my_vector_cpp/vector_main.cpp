#include <iostream>
#include "my_vector_cpp.hpp"

int main() {
    Vector v;

    std::cout << "== CASE 1: init(capacity) ==\n";
    v.init(3);
    std::cout << "size = " << v.size()
              << " capacity = " << v.capacity() << "\n";

    std::cout << "\n== CASE 2: push_back elements ==\n";
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40); // realloc_helper() expected

    std::cout << "After push_back:\n";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v.get_data()[i] << " ";  // ✅ փոփոխված getter
    std::cout << "\nsize = " << v.size()
              << " capacity = " << v.capacity() << "\n";


    std::cout << "\n== CASE 3: insert at index ==\n";
    v.insert(2, 99);
    std::cout << "After insert(2, 99): ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v.get_data()[i] << " ";
    std::cout << "\nsize = " << v.size() << "\n";


    std::cout << "\n== CASE 4: erase index 1 ==\n";
    v.erase(1);
    std::cout << "After erase(1): ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v.get_data()[i] << " ";
    std::cout << "\nsize = " << v.size() << "\n";


    std::cout << "\n== CASE 5: pop_back ==\n";
    v.pop_back();
    std::cout << "After pop_back(): ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v.get_data()[i] << " ";
    std::cout << "\nsize = " << v.size() << "\n";


    std::cout << "\n== CASE 6: clear() ==\n";
    v.clear();
    std::cout << "After clear(): size = " << v.size()
              << " capacity = " << v.capacity() << "\n";

    std::cout << "\n== CASE 7: destroy() ==\n";
    v.destroy();
    std::cout << "After destroy(): size = " << v.size()
              << " capacity = " << v.capacity() << "\n";

    return 0;
}

