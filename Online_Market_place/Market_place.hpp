#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <string>

class Clothes;
class Accessories;
class Book;
class sport;

class OMP {
    private:
        std::vector<Clothes*> Clo;
        std::vector<Accessories*> Acc;
        std::vector<Book*> B;
        std::vector<sport*> S;   
       
    public:
    
        void get_manu()const;
        void push_back(Clothes* ptr);
        void push_back(Accessories* ptr);    
        void push_back(Book* ptr);
        void push_back(sport* ptr);
    
};

class Clothes {
    protected:
        double Price;
        std::string Name;

    public:
        Clothes(double price , std::string name ) : Price{price}, Name{name} {}


        virtual void buy(std::string _size) = 0;
        virtual void get_product()const = 0;


};
class Man: public Clothes {
    private:
        std::vector<std::string> size;


    public:
         Man(std::vector<std::string>& _size, double price, std::string name ) :Clothes(price , name), size{_size} {}    
    
        virtual void buy(std::string _size)override;
        virtual void get_product()const override;
        
        
};


class Woman: public Clothes {
    private:
        std::vector<std::string> size;


    public:
         Woman(std::vector<std::string>& _size, double price, std::string name ) :Clothes(price , name), size{_size}{}     
    
        virtual void buy(std::string _size)override;
        virtual void get_product()const override;
        
        
};
class Child: public Clothes {
    private:
        std::vector<std::string> size;


    public:
         Child(std::vector<std::string>& _size, double price, std::string name ) :Clothes(price , name), size{_size} {}   
    
        virtual void buy(std::string _size)override;
        virtual void get_product()const override;
        
        
};


//=====================================================================================
class Accessories {
    protected:
        int Quantity;
        std::string Name;
        std::string materialComposition;
        double Price;

    public:
        Accessories(int _Quantity, double _price, std::string _name, std::string _material )
        : Quantity{_Quantity}, Price{_price}, Name{_name}, materialComposition{_material} {}

        virtual void buy() = 0;
        virtual void get_product()const =0;;
};

class Necklace: public Accessories{
    private:
        float gram;
    public:
        Necklace(int _Quantity, double _price, std::string _name,std::string _material, float _gram)
        :Accessories(_Quantity, _price, _name, _material), gram{_gram} {} 


        virtual void buy()override;
        virtual void get_product()const override;
};

class Bracelet: public Accessories{
    private:
        float gram;
    public:
        Bracelet(int _Quantity, double _price, std::string _name, std::string _material, float _gram)
        :Accessories(_Quantity, _price, _name, _material), gram{_gram} {} 


        virtual void buy()override;
        virtual void get_product()const override;

};

class Watch: public Accessories{
    private:

    public:
        Watch(int _Quantity, double _price, std::string _name, std::string _material)
        :Accessories(_Quantity, _price, _name, _material) {} 

        virtual void buy()override;
        virtual void get_product()const override;
};

class Ring: public Accessories{
    private:
        float ring;
    public:
        Ring(int _Quantity, double _price, std::string _name, std::string _material, float _ring)
        :Accessories(_Quantity, _price, _name, _material), ring{_ring} {}


        virtual void buy()override;
        virtual void get_product()const override;
};


//================================================================================

class Book{
    private:
        int Page;
        std::string Author;
        int Quantity;
        double Price;

    public:        
        Book(int page, std::string author, int quantity, double price):Page{page}, Author{author}, Quantity{quantity}, Price{price} {} 


        virtual void buy();
        virtual void get_product()const ;
};
class sport {
    private:
        std::string Name;
        double Price;
        int Quantity;

    public:
        sport(int quantity, double price, std::string name): Quantity{quantity}, Price{price}, Name{name} {}

        virtual void buy();
        virtual void get_product()const;

}; 


#endif