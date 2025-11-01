#include <iostream>
#include "coffee_shop.hpp"

int main() {
    CoffeeShop shop("My CoffeeShop");
    shop.constructMenu();

    std::cout << "\n--- Menu ---\n";
    shop.showMenu();

    // Ստեղծում ենք բարիստաներ
    Barista* b1 = new Barista("Anna");
    Barista* b2 = new Barista("John");
    shop.hireBarista(b1);
    shop.hireBarista(b2);

    std::vector<Customer*> customers;
    std::vector<Order*> orders;

    bool running = true;
    while (running) {
        std::cout << "\n--- CoffeeShop Runtime Menu ---\n";
        std::cout << "1. Add Customer\n";
        std::cout << "2. Serve Next Customer\n";
        std::cout << "3. Show Queue\n";
        std::cout << "4. Show Menu\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose option: ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::string cname;
                double balance;
                std::cout << "Customer name: ";
                std::cin >> cname;
                std::cout << "Balance: ";
                std::cin >> balance;

                Customer* c = new Customer(cname, balance);
                customers.push_back(c);

                int orderId = orders.size() + 1;
                Order* o = new Order(orderId);
                orders.push_back(o);

                int nDrinks;
                std::cout << "How many drinks in order? ";
                std::cin >> nDrinks;
                for (int i = 0; i < nDrinks; ++i) {
                    std::string dname;
                    double price;
                    int size;
                    std::cout << "Drink name: ";
                    std::cin >> dname;
                    std::cout << "Price: ";
                    std::cin >> price;
                    std::cout << "Size (0=Small,1=Medium,2=Big): ";
                    std::cin >> size;
                    o->addDrink(Drink(dname, static_cast<Drink::Size>(size), price));
                }

                c->placeOrder(o);
                shop.addCustomerToQueue(c);
                break;
            }
            case 2:
                shop.serveNextCustomer();
                break;
            case 3:
                shop.showQueue();
                break;
            case 4:
                shop.showMenu();
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid option\n";
        }
    }

    // Ջնջում ենք ստեղծված objects
    for (auto o : orders) delete o;
    for (auto c : customers) delete c;

    return 0;
}
