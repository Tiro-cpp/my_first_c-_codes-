#include <iostream>
#include "Market_place.hpp"
//===================================//
void Man::get_product()const {
    std::cout<<"in stock"<<std::endl;
    for(size_t i{0}; i < size.size(); ++i ) {
        std::cout<< size[i] << "==";
    }
    std::cout<<std::endl;
    std::cout << Name << "   the price is = " << Price << std::endl;
    std::cout<<"========================="<<std::endl;
}
void Woman::get_product()const {
    std::cout<<"in stock"<<std::endl;
    for(size_t i{0}; i < size.size(); ++i ) {
        std::cout<< size[i] << "==";
    }
    std::cout<<std::endl;
    std::cout << Name << "   the price is = " << Price << std::endl;
    std::cout<<"========================="<<std::endl;
}
void Child::get_product()const {
    std::cout<<"in stock"<<std::endl;
    for(size_t i{0}; i < size.size(); ++i ) {
        std::cout<< size[i] << "==";
    }
    std::cout<<std::endl;
    std::cout << Name << " the price is = " << Price << std::endl;
    std::cout<<"========================="<<std::endl;
}

void Man::buy(std::string _size)  {
    
    for (size_t i = 0; i < size.size(); ++i) {
        if (_size == size[i]) {
            size.erase(size.begin() + i);
            break;   
        }
    }

}
void Woman::buy(std::string _size)  {
    
    for (size_t i = 0; i < size.size(); ++i) {
    if (_size == size[i]) {
        size.erase(size.begin() + i);
        break;   
    }
}

}
void Child::buy(std::string _size)  {
    
    for (size_t i = 0; i < size.size(); ++i) {
        if (_size == size[i]) {
            size.erase(size.begin() + i);
            break;   
        }
    }

}

//===================================//
//====Accesories======//

void Necklace::get_product()const {
    std::cout << Name << "   the price is = " << Price << std::endl;
}
void Bracelet::get_product()const {
    std::cout << Name << "   the price is = " << Price << std::endl;
}
void Watch::get_product()const {
    std::cout << Name << "   the price is = " << Price << std::endl;
}
void Ring::get_product()const {
    std::cout << Name << "   the price is = " << Price << std::endl;
}

void Necklace::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}
void Bracelet::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}
void Watch::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}
void Ring::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}

//================//
//=====Book=======//



void Book::get_product()const {
    std::cout << Author << "   the price is = " << Price << std::endl;
}
void Book::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}
//================//

//====Sport========//
void sport::get_product()const {
    std::cout << Name << "   the price is = " << Price << std::endl;
}

void sport::buy()  {
    if(Quantity == 0)std::cout<<"Not available at this moment"<<std::endl;
    else --Quantity;
}
//=================//

// 
void OMP::get_manu()const{
    for (const Clothes* item : Clo) {
    item->get_product();
    }
    for (const Accessories* item : Acc) {
    item->get_product();
    }

    for (const Book* item : B) {
    item->get_product();
    }
    for (const sport* item : S) {
    item->get_product();
    }


}



void OMP::push_back(Clothes* ptr){
    Clo.push_back(ptr);
}
void OMP::push_back(Accessories* ptr){
    Acc.push_back(ptr);
}
void OMP::push_back(sport* ptr){
    S.push_back(ptr);
}
void OMP::push_back(Book* ptr){
    B.push_back(ptr);
}
