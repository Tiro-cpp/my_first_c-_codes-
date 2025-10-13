#include <iostream>
#include <numeric>
#include "Rational.hpp"
void Rational::helper_reduce() {
	int result = std::gcd(num, denum);

	num = num / result;
	denum = denum / result;
	if(denum < 0 ) {
	num *= -1;
	denum = -denum;
	}
}
/////////



Rational::Rational(int _num , int _denum): num{_num}, denum{_denum} {
	if(denum == 0) {
	std::cout << "__ERROR__ ";
	std::exit(EXIT_FAILURE);	
	}
	helper_reduce();
}
//constructors
Rational& Rational::operator= (const Rational& other ) {
	if(this != &other) {
	num = other.num;
	denum = other.denum;
	
	}

	
return *this;
}
Rational& Rational::operator= (Rational&& other) {
	if(this != &other) {
	num = other.num;
	denum = other.denum;
	other.num =0;
	other.denum=1;

	}
return *this;
}

/////


//unary operators
 
Rational& Rational::operator++ () {
	num += denum;
return *this;
}
Rational Rational::operator++(int) {
	Rational temp = *this;
	num += denum;	
return temp;
}
Rational& Rational::operator-- () {
	num -= denum;
return *this;
}
Rational Rational::operator-- (int) {
	Rational temp = *this;
	num -= denum;
return temp;
}
bool Rational::operator!(){
	return (num==0);
}
/////



//binary operators

Rational& Rational:: operator+= (const Rational& other){
	int res = std::lcm(denum, other.denum);
	
	num = (res/denum*num) + (res/other.denum*other.num);
	denum = res;
	helper_reduce();
return *this;						
}

Rational& Rational:: operator-=(const Rational& other) {
 	int res = std::lcm(denum, other.denum);
  
        num = (res/denum*num) - (res/other.denum*other.num);
        denum = res;
        helper_reduce();
return *this;
}
Rational& Rational:: operator*=(const Rational& other) {
	num *= other.num;
	denum *= other.denum;
	helper_reduce(); 
return *this;
}
 Rational& Rational:: operator/=(const Rational& other) {
        num *= other.denum;
        denum *= other.num;
        helper_reduce();
return *this;
}
  

Rational operator+ (const Rational& other1 , const Rational other2) {
	Rational pop(other1);
	pop += other2;
	return pop;
}

Rational operator- (const Rational& other1 , const Rational other2) {
	Rational pop(other1);
	pop -= other2;
	return pop;
}



Rational operator* (const Rational& other1, const Rational other2) {
	Rational pop(other1);
	pop *= other2;
	return pop;	
}
Rational operator/ (const Rational& other1 , const Rational other2) {
	Rational pop(other1);
	pop /= other2;	
	return pop;
}
////////

///Comparison operators

bool operator==(const Rational& other1, const Rational& other2) {
	return other1.num==other2.num && other1.denum==other2.denum;
}

bool operator!=(const Rational& other1, const Rational& other2) {
	return other1.num != other2.num && other1.denum != other2.denum;
}
bool operator>=(const Rational& other1, const Rational& other2) {
         return other1.num >= other2.num && other1.denum >= other2.denum;
 }
 bool operator<=(const Rational& other1, const Rational& other2) {
         return other1.num <= other2.num && other1.denum <= other2.denum;
}
bool operator<(const Rational& other1, const Rational& other2) {
          return other1.num < other2.num && other1.denum < other2.denum;
 }
bool operator>(const Rational& other1, const Rational& other2) {
          return other1.num > other2.num && other1.denum > other2.denum;
}  

///////


///Stream operators

std::ostream& operator<< (std::ostream& ost, const Rational& other) {
	ost << other.num << "/" << other.denum;
	return ost;
}
std::istream& operator>> (std::istream& ist, Rational& other) {	
	ist >> other.num >> other.denum;	
	return ist;
}











































