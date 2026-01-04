#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Human {
protected:
    string name;
    int age;
    int experience;

public:
    Human(string n, int a, int e) : name(n), age(a), experience(e) {}

    virtual bool shoot() = 0;
    virtual string type() const = 0;

    void printResult(bool hit) const {
        cout << "Name: " << name
             << ", Age: " << age
             << ", Experience: " << experience
             << ", Type: " << type()
             << " -> ";
        if (hit)
            cout << "HIT 🎯\n";
        else
            cout << "MISS ❌\n";
    }

    virtual ~Human() {}
};

class Beginner : public Human {
public:
    Beginner(string n, int a, int e) : Human(n, a, e) {}

    bool shoot() override {
        double p = 0.01 * experience;
        return (double)rand() / RAND_MAX < p;
    }

    string type() const override {
        return "Beginner";
    }
};

class Experienced : public Human {
public:
    Experienced(string n, int a, int e) : Human(n, a, e) {}

    bool shoot() override {
        double p = 0.05 * experience;
        return (double)rand() / RAND_MAX < p;
    }

    string type() const override {
        return "Experienced";
    }
};

class Veteran : public Human {
public:
    Veteran(string n, int a, int e) : Human(n, a, e) {}

    bool shoot() override {
        double p = 0.9 - 0.01 * age;
        if (p < 0) p = 0;
        return (double)rand() / RAND_MAX < p;
    }

    string type() const override {
        return "Veteran";
    }
};

int main() {
    srand(time(nullptr));

    Human* group[7] = {
        new Beginner("Armen", 22, 1),
        new Experienced("Davit", 30, 5),
        new Veteran("Samvel", 55, 20),
        new Experienced("Artur", 28, 4),
        new Beginner("Gor", 21, 2),
        new Experienced("Vahe", 35, 6),
        new Beginner("Narek", 24, 3)
    };

    cout << "🎯 Shooting simulation started\n\n";

    bool hit = false;

    for (int i = 0; i < 7 && !hit; i++) {
        bool result = group[i]->shoot();
        group[i]->printResult(result);
        if (result) {
            cout << "\nShooting stopped: target was hit ✅\n";
            hit = true;
        }
    }

    if (!hit)
        cout << "\nNo one hit the target ❌\n";

    for (int i = 0; i < 7; i++)
        delete group[i];

    return 0;
}
