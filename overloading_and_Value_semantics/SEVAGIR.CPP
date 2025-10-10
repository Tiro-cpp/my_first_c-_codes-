#include <iostream>

class person {

private:
int age;
double height;

public:

person(int i=0): age(i) {}
void print() {std::cout << age ;}
person(person& a): age(a.age) {} 

person( &&v): age(std::move(v)) {}


};
int main () {

    person a(5);
    a.print();
    person b(a);    
    b.print();
    int pop =6;
    person c(std::move(pop));
    c.print();
return 0;
}