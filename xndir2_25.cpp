#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;   // ապրանքի անվանում
    double price;  // ապրանքի գին
    int year;      // թողարկման տարի

public:
    // Լռելյայն կոնստրուկտոր
    Product() {
        name = "Անհայտ";
        price = 0.0;
        year = 0;
    }

    // Կոնստրուկտոր պարամետրերով
    Product(string n, double p, int y) {
        name = n;
        price = p;
        year = y;
    }

    // Դեստրուկտոր
    ~Product() {
        cout << "Օբյեկտը ոչնչացվեց: " << name << endl;
    }

    // Քանի տարի առաջ է թողարկվել ապրանքը
    int yearsFromRelease(int currentYear) const {
        return currentYear - year;
    }

    // Գնի ավելացում 20%, եթե անվանման մեջ կա "TV"
    void increasePriceIfTV() {
        if (name.find("TV") != string::npos) {
            price *= 1.20;
        }
    }

    // Տեղեկատվական տող
    string info() const {
        return "Անվանում: " + name +
               ", Գին: " + to_string(price) +
               ", Թողարկման տարի: " + to_string(year);
    }
};

int main() {
    // Օբյեկտ՝ հաստատուն արժեքներով
    Product p1("Samsung TV", 300000, 2020);

    cout << p1.info() << endl;
    cout << "Թողարկվել է "
         << p1.yearsFromRelease(2025)
         << " տարի առաջ" << endl;

    p1.increasePriceIfTV();
    cout << "Գնի փոփոխությունից հետո -> "
         << p1.info() << endl;

    cout << "------------------------" << endl;

    // Օբյեկտ՝ օգտագործողի մուտքագրած տվյալներով
    string name;
    double price;
    int year;

    cout << "Մուտքագրեք ապրանքի անվանումը: ";
    getline(cin, name);

    cout << "Մուտքագրեք գինը: ";
    cin >> price;

    cout << "Մուտքագրեք թողարկման տարին: ";
    cin >> year;

    Product p2(name, price, year);

    cout << p2.info() << endl;
    cout << "Թողարկվել է "
         << p2.yearsFromRelease(2025)
         << " տարի առաջ" << endl;

    p2.increasePriceIfTV();
    cout << "Վերջնական տվյալներ -> "
         << p2.info() << endl;

    return 0;
}
