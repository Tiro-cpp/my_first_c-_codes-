#include <iostream>
#include <vector>
#include "coffee_shop.hpp"



CoffeeShop::~CoffeeShop() {
    for (auto d : menu) delete d;
}
void Drink::display() const {

	std::cout << name << std::endl;
	switch(volume) {
		case Size::Small: std::cout<< ":::Small:::" << std::endl;	
		break;							
		case Size::Medium: std::cout << ":::Medium:::" << std::endl;
		break;
		case Size::Big: std::cout << ":::Big:::" <<  std::endl;
		break;
		default: std::cout << "::::" << std::endl; break;
				
	}
	std::cout << "The" << name << "is" << price << "$" << std::endl;
}


void CoffeeShop::addDrink(Drink* drink) {
		if(drink == nullptr) return;

		menu.push_back(drink);
}

void CoffeeShop::removedrink(const std::string& drinkname) {
	for(size_t i =0; i < menu.size() ; ++i) {
		if(menu[i]->getName() == drinkname ) {
			delete menu[i];
			menu.erase(menu.begin() + i);
			return;
		}
	}
 }
 
void CoffeeShop::showMenu() const {
	
	for( size_t i =0; i < menu.size() ; ++i) {
		menu[i]->display();
		std::cout<<"\n";
	}
}
void CoffeeShop::hireBarista(Barista* barista) {
	if(barista == nullptr) return;
	baristas.push_back(barista);
}
void CoffeeShop::fireBarista(Barista* barista){
	for(size_t i =0; i < baristas.size(); ++i) {
		if(baristas[i] == barista ){
			baristas.erase(baristas.begin() + i);
			return;
		}
	}
}
void CoffeeShop::showBaristas() const {
	for(size_t i =0; i < baristas.size(); ++i) {
		std::cout << baristas[i]->getName() << std::endl;
	}
}

void CoffeeShop::addCustomerToQueue(Customer* customer) {
	if(customer == nullptr) return; 
	queue.push_back(customer);
}

void CoffeeShop::serveNextCustomer() {
    if (queue.empty() || baristas.empty()) return;  // Ստուգում դատարկություն

    Customer* c = queue[0];
    if (!c || !c->getorder()) {  // Ստուգում null pointers
        queue.erase(queue.begin());
        return;
    }

    baristas[0]->prepareOrder(c->getorder());
    queue.erase(queue.begin());
}


void CoffeeShop::showQueue() const {
	for(size_t i =0; i < queue.size() ; ++i) {
		queue[i]->display();
		std::cout<<"\n";
	}
}

void CoffeeShop::constructMenu() {
    menu.clear();
    addDrink(new Drink("Espresso",Drink::Size::Small, 2.50));
    addDrink(new Drink("Latte",Drink::Size::Small, 3.00));
    addDrink(new Drink("Cappuccino",Drink::Size::Small, 3.20));
    addDrink(new Drink("Americano",Drink::Size::Small, 2.80));
    addDrink(new Drink("Mocha",Drink::Size::Small, 3.50));
    std::cout << "Menu constructed successfully! ☕️" << std::endl;
}

void Order::addDrink(const Drink& drink) {
	drinks.push_back(drink);
	calculateTotalPrice();
}
void Order::removeDrink(int index) {
	if(index < 0 || index >= drinks.size()) {
		std::cout<< "invalid drink indexx----";
		return;
	}
	drinks.erase(drinks.begin() + index);

}
void Order::calculateTotalPrice() {
	totalPrice = 0.0;

	for(size_t i =0; i < drinks.size(); ++i) {
		totalPrice += drinks[i].getPrice();
	}
 }
  void Order::displayOrder() const {
	std::cout<<getOrderId()<<std::endl;
	for(size_t i =0; i < drinks.size(); ++i) {
		drinks[i].display();
		std::cout << std::endl;
	}
	std::cout<<getTotalPrice()<<std::endl;
	std::cout<<getIsPrepared()<<std::endl;
	std::cout<<getIsPaid()<<std::endl;
  }

void Barista::prepareOrder(Order* order) {
	greetCustomer();
	if(order == nullptr) return;
	order->markPrepared();

   }
void Barista::greetCustomer() const {
	std::cout<< "---HELLO---"<<std::endl;
}

void Customer::payOrder() {
    if (balance < currentOrder->getTotalPrice()) {
        std::cout << "Not enough money on your balance!" << std::endl;
        return;
    }
    balance -= currentOrder->getTotalPrice();
    currentOrder->markPaid();
}

void Customer::display() const {
	std::cout<< name<<std::endl;
	std::cout<<balance<<std::endl;
	viewOrder();
}

void Customer::viewOrder() const {
	if (!currentOrder) {
        std::cout << "[viewOrder] No order for customer " << name << std::endl;
        return;
    }
	currentOrder->displayOrder();
}
