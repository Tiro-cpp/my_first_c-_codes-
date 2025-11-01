#ifndef COFFEESHOP_HPP
#define COFFEESHOP_HPP
#include <iostream>
#include <vector>
#include <string>

// Forward declarations

class Barista;
class Customer;
class Drink;
class Order;
class CoffeeShop {
private:
    std::string shopName;
    std::vector<Drink*> menu;
    std::vector<Barista*> baristas; // Aggregation
    std::vector<Customer*> queue;   // Association

public:
    CoffeeShop() = default;
    CoffeeShop(const std::string& name) : shopName(name) {}
    ~CoffeeShop();


    std::string getName() const { return shopName; }


    void setName(const std::string& newName) { shopName = newName; }

    void addDrink(Drink* drink);
    void removedrink(const std::string& drinkname);
	void showMenu() const;
    
	void hireBarista(Barista* barista);
    void fireBarista(Barista* barista);
    void showBaristas() const;

    void addCustomerToQueue(Customer* customer);
    void serveNextCustomer();
    void showQueue() const;
    void constructMenu();

    void displayShopInfo() const;
};

class Order;
class Customer {
private:
    std::string name;
    double balance;
    Order* currentOrder; 

public:
    Customer() = default;
    Customer(const std::string& name, double balance):name(name), balance(balance), currentOrder(nullptr) {}


    std::string getName() const { return name; }
    double getBalance() const { return balance; }
    void setBalance(double newBalance) { balance = newBalance; }

    void placeOrder(Order* order) { currentOrder = order; }
    void payOrder();
    void viewOrder() const;

    void display() const;

    Order* getorder() const { return currentOrder; }
};


class Order {
private:
    int orderId;
    std::vector<Drink> drinks;
    double totalPrice;
    bool isPrepared;
    bool isPaid;

public:

    Order();
    Order(int id): orderId(id), totalPrice(0.0), isPrepared(false), isPaid(false) {}

    int getOrderId() const { return orderId; }
    double getTotalPrice() const { return totalPrice; }
    bool getIsPrepared() const {return isPrepared; }
    bool getIsPaid() const {return isPaid; }


    void addDrink(const Drink& drink);
    void removeDrink(int index);
    void calculateTotalPrice();


    void markPrepared() { isPrepared = true; }
    void markPaid(){ isPaid = true; }

    void displayOrder() const;
};


class Drink {
public:
    enum class Size { Small, Medium, Big };

private:
    std::string name;
    Size volume;
    double price;

public:
    // Constructors
    Drink() = default;
    Drink(const std::string& Name, Size volume, double price): name(Name), volume(volume), price(price) {}

    // Getters
    std::string getName() const { return name; }
    Size getVolume() const { return volume; }
    double getPrice() const { return price; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setVolume(Size newVolume) { volume = newVolume; }
    void setPrice(double newPrice) { price = newPrice; }

    // Display
    void display() const; //cpp
};




class Barista {
private:
    std::string name;

public:
    // Constructors
    Barista() = default;
    Barista(const std::string& name): name(name) {}

    // Getters/Setters
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    // Behavior
    void prepareOrder(Order* order); // dependency
    void greetCustomer() const;
};




#endif


