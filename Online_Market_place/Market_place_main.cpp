#include "Market_place.hpp"
#include <iostream>

int main() {

    OMP shop;

    // ---------------- sizes ----------------
    std::vector<std::string> manSizes = {"s", "m", "l", "xl"};
    std::vector<std::string> womanSizes = {"xs", "s", "m", "l"};
    std::vector<std::string> childSizes = {"2y", "4y", "6y"};
    std::vector<std::string> shoesSizes_child = {"35","36", "37", "38", "39", "40"};
    std::vector<std::string> shoesSizes_adult = { "40", "41", "42", "43", "44"};
    //-----------------------------------------

    Clothes* manShirt   = new Man(manSizes, 12000, "Man Shirt");
    Clothes* manshoes   = new Man(shoesSizes_adult, 26000, "Man shoes");
    Clothes* manhoody   = new Man(manSizes, 17000, "Man Hoody");
    Clothes* manjacket   = new Man(manSizes, 22000, "Man Jacket");
    Clothes* mancostum  = new Man(manSizes, 70000, "Man Costum");
    Clothes* manblazer   = new Man(manSizes, 30000, "Man Blazer");

    Clothes* womanDress = new Woman(womanSizes, 18000, "Woman Dress");
    Clothes* Womanshoes   = new Woman(shoesSizes_adult, 26000, "Woman shoes");
    Clothes* Womanhoody   = new Woman(womanSizes, 17000, "Woman Hoody");
    Clothes* Womanjacket   = new Woman(womanSizes, 22000, "Woman Jacket");
    Clothes* Womancostum  = new Woman(womanSizes, 70000, "Woman Costum");
    Clothes* Womanblazer   = new Woman(womanSizes, 30000, "Woman Blazer");


    Clothes* childTee   = new Child(childSizes, 8000, "Child T-shirt");
    Clothes* childshoes   = new Child(shoesSizes_child, 8000, "Child shoes");
    Clothes* childhoody   = new Child(childSizes, 8000, "Child hoody");
    Clothes* childjacket   = new Child(childSizes, 8000, "Child jacket");
    Clothes* childcostum   = new Child(childSizes, 8000, "Child costum");
    Clothes* childblazer   = new Child(childSizes, 8000, "Child blazer");
   

    Accessories* ring = new Ring(10, 55000, "Gold Ring", "Gold 585", 7.5f);
    Accessories* watch = new Watch(5, 120000, "Casio Watch", "Steel");
    Accessories* bracelet = new Bracelet(7, 42000, "Silver Bracelet", "Silver 925", 12.3f);
    Book* book1 = new Book(320, "Dostoyevsky", 15, 9000);
    sport* ball = new sport(20, 7000, "BALL");
    
    //---------------------------------------
    shop.push_back(manShirt);
    shop.push_back(manshoes);
    shop.push_back(manhoody);
    shop.push_back(manjacket);
    shop.push_back(mancostum);
    shop.push_back(manblazer);

    shop.push_back(womanDress);
    shop.push_back(Womanshoes);
    shop.push_back(Womanhoody);
    shop.push_back(Womanjacket);
    shop.push_back(Womancostum);
    shop.push_back(Womanblazer);

    shop.push_back(childTee); 
    shop.push_back(childshoes);   
    shop.push_back(childhoody);
    shop.push_back(childjacket);
    shop.push_back(childcostum);
    shop.push_back(childblazer);

    shop.push_back(ring);
    shop.push_back(watch);
    shop.push_back(bracelet);
    shop.push_back(book1);
    shop.push_back(ball);

    std::cout<<"======================================================="<<std::endl;
    shop.get_manu();
    // ---------------- CLEANUP ----------------
    delete manShirt;
    delete womanDress;
    delete childTee;

    delete ring;
    delete watch;
    delete bracelet;

    delete book1;
    delete ball;

    return 0;
}
