#include <iostream>
#include <string>

using namespace std;

class Aircraft {
protected:
    string brand;
    int engines;
    double altitude;

public:
    Aircraft(string b, int e, double a) {
        brand = b;
        engines = e;
        altitude = a;
    }

    virtual double quality() const {
        return (engines * altitude) / 1000.0;
    }

    virtual void print() const {
        cout << "Aircraft (level 1)\n";
        cout << "Brand: " << brand << endl;
        cout << "Engines: " << engines << endl;
        cout << "Altitude: " << altitude << endl;
        cout << "Q = " << quality() << endl;
    }

    virtual ~Aircraft() {}
};

class AircraftEx : public Aircraft {
private:
    string country;

public:
    AircraftEx(string b, int e, double a, string c)
        : Aircraft(b, e, a) {
        country = c;
    }

    double quality() const override {
        double Q = Aircraft::quality();

        if (country == "Russia")
            return Q + 1;
        else if (country == "France")
            return Q + 0.5;
        else
            return Q;
    }

    void print() const override {
        cout << "Aircraft (level 2)\n";
        cout << "Brand: " << brand << endl;
        cout << "Engines: " << engines << endl;
        cout << "Altitude: " << altitude << endl;
        cout << "Country: " << country << endl;
        cout << "Qp = " << quality() << endl;
    }
};

int main() {
    Aircraft a("Boeing", 2, 10000);
    a.print();

    cout << "----------------------\n";

    AircraftEx a2("Sukhoi", 2, 11000, "Russia");
    a2.print();

    cout << "----------------------\n";

    Aircraft* ptr = new AircraftEx("Airbus", 4, 12000, "France");
    ptr->print();

    delete ptr;
    return 0;
}
