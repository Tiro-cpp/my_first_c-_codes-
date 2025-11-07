#include <iostream>
#include "animal.hpp"
#include <string>
int Animal::Id = 0;
/////////////////////////////////////////////////////////////////////////////////
//mammal constructoors
Animal::Animal( const std::string& name, int health = 100, int hunger = 0, Kind k )
:name{name}, id{Id++}, health{health}, hunger{hunger}, _kind{k} {}


Mammal::Mammal(const  std::string& n,int he , int hu, Kind k )
:Animal(n, he, hu, k), warmBlooded(true) {}

//bird ctor
Bird::Bird(const std::string& n,int he , int hu, Kind k )
:Animal(n, he, hu, k), wingspan(0.5) {}

 //reptile ctor
Reptile::Reptile(const std::string& n, int he , int hu, Kind k )
:Animal(n, he, hu, k), coldBlood(true) {}


Lion::Lion(const std::string& n, int he , int hu ):Mammal(n, he, hu, Kind::Lion ), roarRower(7) { }

Tiger::Tiger(const std::string& n, int he , int hu):Mammal(n, he, hu , Kind::Tiger), jumpHeight(3.2) {}
  

Elephant::Elephant(const std::string& n, int he , int hu):Mammal(n, he, hu, Kind::Elephant), trunkLength(3.5) {}

Eagle::Eagle(const std::string& n,int he , int hu ):Bird(n, he, hu,Kind::Eagle), visionRange(1.5) {}

Parrot::Parrot(const std::string& n, int he , int hu ,const std::vector<std::string> say):Bird(n, he, hu,Kind::Parrot) {
    
    for(size_t i{0}; i < say.size(); ++i) {
        vocabulary.push_back(say[i]);
    }
}

Snake::Snake(const std::string& n, int he , int hu):Reptile(n,he, hu, Kind::Snake), poisonous(true) {}

Crocodile::Crocodile(const std::string& n, int he , int hu):Reptile(n, he, hu, Kind::Crocodile), biteForce(5) {}


////////////////////////////////////////////////////////////////////////////////


void Animal::PrintInfo() const {
    switch(_kind) {
    case Kind::Lion: 
        static_cast<const Lion *>(this)->PrintInfo() ;    
        break;
    case Kind::Tiger: 
        static_cast<const Tiger *>(this)->PrintInfo();
        break;
    case Kind::Elephant: 
        static_cast<const Elephant *>(this)->PrintInfo();
        break;
    case Kind::Eagle: 
        static_cast<const Eagle *>(this)->PrintInfo();
        break;
    case Kind::Parrot: 
         (static_cast<const Parrot *>(this))->PrintInfo();
        break;
    case Kind::Snake: 
         (static_cast<const Snake * >(this))->PrintInfo();
        break;
    case Kind::Crocodile: 
        (static_cast<const Crocodile* >(this))->PrintInfo();
        break;
    default:
        std::cout << "novu";

    } 
}
void Animal::Feed() {
    int food = 100 - health;
    if(food > 0){
        if(hunger >= food ){
             health += food; 
             hunger -= food; 
        }
        else {
            health += hunger;
            hunger = 0;
        }
    }    
}
void Mammal::MakeSound()const {
    std::cout << "  RrrrrrrRrrrrrrRRrrrrrr" << std::endl;
}    
void Bird::fly()const {
    std::cout << name << "  can fly" << std::endl;
}

void Reptile::Sumbathe()const {
    std::cout << "  reptile warms itself in sun" << std::endl;
}
void Lion::MakeSound()const {
    std::cout << name << "  braaaaauuuuuu" << std::endl;
}

//
void Lion::PrintInfo()const{
    std::cout << name << " health is" << health <<"  hunger is "<< hunger<<std::endl;
    MakeSound();
}
void Tiger::MakeSound()const { 
    std::cout << name << "  veauuuuuu" << std::endl;
}
//
void Tiger::PrintInfo()const{
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     Jump();
}

void Tiger::Jump() const {
    std::cout << name << "  jumping the" << jumpHeight << "{km/h}" <<std::endl;
}
void Elephant::UseTrunk()const{
    std::cout << name << "  the trunk lenght is" << trunkLength << std::endl;
}
void Elephant::MakeSound()const { 
    std::cout << name << " Ppppppixxx" << std::endl;
}
//
void Elephant::PrintInfo()const{
     std::cout << name << " health is" << health <<"  hunger is "<< hunger<<std::endl;
     MakeSound();
}

void Eagle::Soar()const {
    std::cout<< " flying vision nage is " << visionRange << std::endl;
}
void Eagle::fly()const {
    std::cout << name << "   flying in 1 km/h " << std::endl;
}
//
void Eagle::PrintInfo()const{
     std::cout << name << "  health is" << health <<"   hunger is "<< hunger<<std::endl;
     fly();

} 

void Parrot::Speak()const {
    for(size_t i{0} ; i < vocabulary.size() ; ++i) {
        std::cout << vocabulary[i];
    }
}
void Parrot::fly()const {
    std::cout << "A" << name << "can fly a certain distance depending on its speed and the time it flies." << std::endl;
}
//
void Parrot::PrintInfo()const {
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     fly();
}
void Snake::Hiss() const {
        std::cout << "Sssss! " << std::endl;
}
void Snake::PrintInfo()const {
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     Hiss();
}
//
void Crocodile::PrintInfo()const{
     std::cout << name << "health is" << health <<"hunger is "<< hunger<<std::endl;
     Snap();
} 

void Crocodile::Snap()const {
    std::cout << name << "snaps it's jews with force " << biteForce << std::endl;
}




 
