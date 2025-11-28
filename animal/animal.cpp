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


void Lion::MakeSound() {
    std::cout << name << "  braaaaauuuuuu" << std::endl;
}
void Lion::I_Walk() {
    std::cout << "Lion can walk-"<<std::endl;

}
void Lion::I_feedable() {
    std::cout << "A lion can stay hungry for a long time.*"<<std::endl;

}


void Lion::PrintInfo(){
    std::cout << name << " health is" << health <<"  hunger is "<< hunger<<std::endl;
}
/////////////////////////////////////
//Tiger
void Tiger::MakeSound() { 
    std::cout << name << "  veauuuuuu" << std::endl;
}
void Tiger::I_Walk(){
    std::cout<< "Tiger is walk "<<std::endl;
}
void Tiger::I_feedable() {
    std::cout << "A Tiger can stay hungry for a long time.*"<<std::endl;
}

void Tiger::PrintInfo(){
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     Jump();
     MakeSound();
     I_Walk();
     I_feedable();
}

void Tiger::Jump() const {
    std::cout << name << "  jumping the" << jumpHeight << "{km/h}" <<std::endl;
}
/////Elephant

void Elephant::UseTrunk() {
    std::cout << name << "  the trunk lenght is" << trunkLength << std::endl;
}
void Elephant::MakeSound() { 
    std::cout << name << " Ppppppixxx" << std::endl;
}
void Elephant::I_Walk() {
    std::cout<< "Elephant is walk "<<std::endl;
}
void Elephant::I_feedable() {
    std::cout << "A Elephant can stay hungry for a long time.*"<<std::endl;
}
//
void Elephant::PrintInfo() {
     std::cout << name << " health is" << health <<"  hunger is "<< hunger<<std::endl;
     MakeSound();
     I_feedable();
     I_Walk();
     UseTrunk();
}
//////////Eagle
void Eagle::Soar()const {
    std::cout<< " flying vision nage is " << visionRange << std::endl;
}
void Eagle::fly() {
    std::cout << name << "   flying in 1 km/h " << std::endl;
}
void Eagle::I_Walk() {
    std::cout<< "Eaglel is walk "<<std::endl;
}
void Eagle::I_feedable() {
    std::cout << "A Eagle can stay hungry for a long time.*"<<std::endl;
}
void Eagle::MakeSound(){
    std::cout<< "jhjhjhjhjhjh"<<std::endl;
}

void Eagle::PrintInfo(){
     std::cout << name << "  health is" << health <<"   hunger is "<< hunger<<std::endl;
     fly();

} 
////Parot
void Parrot::I_Walk() {
    std::cout<< "Parrot is walk "<<std::endl;
}
void Parrot::I_feedable() {
    std::cout << "A Parott can stay hungry for a long time.*"<<std::endl;
}
void Parrot::fly() {
    std::cout << "A" << name << "can fly a certain distance depending on its speed and the time it flies." << std::endl;
}
void Parrot::MakeSound() {
    for(size_t i{0} ; i < vocabulary.size() ; ++i) {
        std::cout << vocabulary[i];
    }
}
void Parrot::PrintInfo() {
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     fly();
     MakeSound();
     fly();
     I_Walk();
     I_feedable();
}
////Snake


void Snake::MakeSound()  {
        std::cout << "Sssss! " << std::endl;
}
void Snake::I_Walk(){
    std::cout<<"snake is walk"<<std::endl;
}
void Snake::I_feedable() {
    std::cout << "A Snake can stay hungry for a long time.*"<<std::endl;
}
void Snake::PrintInfo() {
     std::cout << name << "  health is" << health <<"  hunger is "<< hunger<<std::endl;
     I_feedable();
     MakeSound();

}
//
void Crocodile::MakeSound(){
    std::cout<<"mkau"<<std::endl;
}
void Crocodile::I_swim() {
    std::cout << "crocodile is swimming "<< std::endl;
}
void Crocodile::I_feedable() {
    std::cout << "A crocodile can stay hungry for a long time.*"<<std::endl;

}
void Crocodile::Snap() {
    std::cout << name << "snaps it's jews with force " << biteForce << std::endl;
}
void Crocodile::PrintInfo(){
     std::cout << name << "health is" << health <<"hunger is "<< hunger<<std::endl;
     Snap();
     I_feedable();
     I_swim();
} 






 
