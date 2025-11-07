#include <iostream>
#include <vector>
#include "animal.hpp"

int main() {
    Lion* simba = new Lion("Simba", 60, 40);
    Tiger* tony = new Tiger("Tony", 50, 30);
    Elephant* dumbo = new Elephant("Dumbo", 80, 10);
    Eagle* aquila = new Eagle("Aquila", 70, 25);
    Parrot* koko = new Parrot("Koko", 90, 20, {"Hello ", "I am Koko!"});
    Snake* sly = new Snake("Sly", 40, 60);
    Crocodile* croc = new Crocodile("Croc", 55, 45);

    std::vector<Animal*> animals = { simba, tony, dumbo, aquila, koko, sly, croc };

    std::cout << "=== BEFORE FEEDING ===" << std::endl;
    for (Animal* a : animals) {
        a->PrintInfo();
    }

    // kerakrum enq 
    std::cout << "\n=== FEEDING ANIMALS ===" << std::endl;
    for (Animal* a : animals) {
        a->Feed();
    }

    
    std::cout << "\n=== AFTER FEEDING ===" << std::endl;
    for (Animal* a : animals) {
        a->PrintInfo();
    }

    
    for (Animal* a : animals) {
        delete a;
    }

    return 0;
}
