#include <vector>
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

enum class Kind {
    Animal, Mammal, Bird, Reptile,
    Lion, Tiger, Elephant,
    Eagle, Parrot,
    Snake, Crocodile
};
class Ifly {
    public:
        virtual void fly() = 0;     
};
class Iswim {
    public:
    virtual void I_swim() =0;
};
class Iwalk {
    public:
    virtual void I_Walk() =0;
};
class Ivoice{
    public:
    virtual void MakeSound() =0;
};
class IFeedable {
    public:
    virtual void I_feedable() =0;
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
    virtual ~Animal() = default;
        
public:    

    virtual void PrintInfo() = 0; 
    void Feed();
 


};

class Mammal: public Animal {
    protected:
        bool warmBlooded;
        

    public:
        Mammal():Animal(), warmBlooded(true) {}
        Mammal(const  std::string& n, int he , int hu, Kind k = Kind::Mammal);
};

class Bird: public Animal {
    protected:
        double wingspan;         //teveri bacvatsq

    public:
        Bird():Animal(), wingspan(0.5) {}
        Bird(const std::string& n, int he, int hu, Kind k = Kind::Bird);
        
};

class Reptile: public Animal {
    protected:
        bool coldBlood;
        

    public:
        Reptile():Animal(), coldBlood(true) {}
        Reptile(const std::string& n, int he, int hu, Kind k = Kind::Reptile);
        void Sumbathe()const;
         
};



class Lion: public Mammal, public Ivoice, public Iwalk, public IFeedable{
    private:
        int roarRower;

    public:
        Lion():Mammal(), roarRower(7) {}

        Lion(const std::string& n, int he , int hu );
    public:
        void PrintInfo();
    public:    
        virtual void MakeSound()override;  
        virtual void I_Walk() override;////////
        virtual void I_feedable() override;/////
};

class Tiger:public Mammal, public Ivoice, public Iwalk, public IFeedable{
    private:
        double jumpHeight;        
   
    public:
        Tiger():Mammal(), jumpHeight(3.2) {}
        Tiger(const std::string& n, int he , int hu);    
    public:    
        void Jump()const;
        void PrintInfo(); 
    public:    
        virtual void MakeSound() override;
        virtual void I_Walk() override;////////
        virtual void I_feedable() override;//////
};

class Elephant:public Mammal, public Ivoice,public Iwalk, public IFeedable {
    private:
    double trunkLength;

    public:
        Elephant():Mammal(), trunkLength(3.5) {}
        Elephant(const std::string& n, int he, int hu);
        void UseTrunk();
        void PrintInfo() override;

     void MakeSound() override;
        virtual void I_Walk() override;//////
        virtual void I_feedable() override;

};
class Eagle : public Bird, public Ivoice, public Iwalk, public IFeedable, public Ifly {
    private:
    double visionRange; // meters
    public:
        Eagle():Bird(), visionRange(1.3){}
        Eagle(const std::string& n, int he , int hu);
        virtual void MakeSound()override; 
        virtual void fly() override; ////
        virtual void I_Walk() override;//// 
        virtual void I_feedable() override;/////
        void PrintInfo() override;
        void Soar()const;
};

class Parrot:public Bird, public Ivoice, public Iwalk, public IFeedable, public Ifly {
    private:
        std::vector<std::string> vocabulary;     // words it can "say"
    public:
        Parrot():Bird() {}
        Parrot(const std::string& n,int he, int hu, const std::vector<std::string> say);
        void PrintInfo() override;
     void MakeSound() override;   
        
        virtual void I_Walk() override;////
        virtual void I_feedable() override;////
        virtual void fly() override;/// 


};
class Snake:public Reptile, public Ivoice,public Iwalk, public IFeedable  {
    private:
        bool poisonous;
    
    public:
        Snake():Reptile(), poisonous(true) {}
        Snake(const std::string& n, int he , int hu);

        
        void PrintInfo() override; 
     void MakeSound() override;////
        virtual void I_feedable() override;////
        virtual void I_Walk() override;////
};
class Crocodile:public Reptile, public Ivoice, public Iswim, public IFeedable {
    private:
        int biteForce;      // 1..10
    public:
        Crocodile():Reptile(), biteForce(5) {}
        Crocodile(const std::string& n, int he , int hu);

        void Snap();
        void PrintInfo() override;
     void MakeSound() override; 
        virtual void I_swim() override;///
        virtual void I_feedable() override;////
};


#endif