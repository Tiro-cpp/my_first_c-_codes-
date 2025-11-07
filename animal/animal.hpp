#include <vector>
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

enum class Kind {
    Animal, Mammal, Bird, Reptile,
    Lion, Tiger, Elephant,
    Eagle, Parrot,
    Snake, Crocodile
};

class Animal {
    
protected:
    
    std::string name;
    int health;     // 0..100
    int hunger;     // 0..100
    Kind _kind;
    int id;    
    static int Id;

public:
    
    Animal():name("unname"), id{Id++}, health{100}, hunger{}, _kind{Kind::Animal} {}
    
    Animal( const std::string& name, int health, int hunger, Kind k = Kind::Animal);
    
        
public:    

    void PrintInfo()const; 
    void Feed();
    
    

};

class Mammal: public Animal {
    protected:
        bool warmBlooded;
        

    public:
        Mammal():Animal(), warmBlooded(true) {}
        Mammal(const  std::string& n, int he , int hu, Kind k = Kind::Mammal);
        void MakeSound()const;
};

class Bird: public Animal {
    protected:
        double wingspan;         //teveri bacvatsq
        

    public:
        Bird():Animal(), wingspan(0.5) {}
        Bird(const std::string& n,int he, int hu, Kind k = Kind::Bird);
        void fly()const;
};

class Reptile: public Animal {
    protected:
        bool coldBlood;
        

    public:
        Reptile():Animal(), coldBlood(true) {}
        Reptile(const std::string& n,int he, int hu, Kind k = Kind::Reptile);
        void Sumbathe()const;
         
};



class Lion: public Mammal {
    private:
        int roarRower;

    public:
        Lion():Mammal(), roarRower(7) {}

        Lion(const std::string& n, int he , int hu );
    public:
        void MakeSound()const; 
        void PrintInfo()const; 
};

class Tiger:public Mammal{
    private:
        double jumpHeight;        
   
    public:
        Tiger():Mammal(), jumpHeight(3.2) {}
        Tiger(const std::string& n, int he , int hu);    
        void MakeSound()const;
        void Jump()const;
        void PrintInfo()const; 

};

class Elephant:public Mammal {
    private:
    double trunkLength;

    public:
        Elephant():Mammal(), trunkLength(3.5) {}
        Elephant(const std::string& n, int he, int hu);

        void MakeSound()const;
        void UseTrunk()const;
        void PrintInfo()const; 

};
class Eagle:public Bird {
    private:
    double visionRange; // meters
    public:
        Eagle():Bird(), visionRange(1.3){}
        Eagle(const std::string& n, int he , int hu);

        void Soar()const;
        void fly()const; 
        void PrintInfo()const; 

};

class Parrot:public Bird {
    private:
        std::vector<std::string> vocabulary;     // words it can "say"
    public:
        Parrot():Bird() {}
        Parrot(const std::string& n,int he, int hu, const std::vector<std::string> say);
        
        void fly()const;
        void Speak()const;   
        void PrintInfo()const; 


};
class Snake:public Reptile {
    private:
        bool poisonous;
    
    public:
        Snake():Reptile(), poisonous(true) {}
        Snake(const std::string& n, int he , int hu);

        void Hiss()const;
        void PrintInfo()const; 
};
class Crocodile:public Reptile {
    private:
        int biteForce;      // 1..10
    public:
        Crocodile():Reptile(), biteForce(5) {}
        Crocodile(const std::string& n, int he , int hu);

        void Snap()const;
        void PrintInfo()const; 
};


#endif