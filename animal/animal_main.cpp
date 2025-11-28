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

    

    for (Animal* a : animals) {
        a->PrintInfo();

        if (IFeedable* item = dynamic_cast<IFeedable*>(a)) {
            item->I_feedable();
        }

        if (Ifly* item = dynamic_cast<Ifly*>(a)) {
            item->fly();
        }

        a->PrintInfo();
        std::cout << std::endl;
    }

    for (Animal* a : animals) delete a;

    return 0;
}
