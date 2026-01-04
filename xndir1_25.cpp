#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


class CircleArc {
private:
    double radius; 
    double angle;  

public:
    CircleArc(double r, double a) {
        radius = r;
        angle = a;
    }

   
    string info() const {
        stringstream ss;
        ss << "Շառավիղ = " << radius
           << ", Անկյուն (ռադիան) = " << angle;
        return ss.str();
    }

   
    double arcLength() const {
        return radius * angle;
    }
};

int main() {
    double r, a;

    cout << "Մուտքագրեք շառավիղը: ";
    cin >> r;

    cout << "Մուտքագրեք անկյունը (ռադիաններով): ";
    cin >> a;

   
    CircleArc arc(r, a);

   
    cout << arc.info() << endl;
    cout << fixed << setprecision(4)
         << "Աղեղի երկարությունը = "
         << arc.arcLength() << endl;

    return 0;
}
