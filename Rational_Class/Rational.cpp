#include <iostream>

void Rational::helper_reduce(int& num , int& denum) {
	int result = std::gcd(num, denum);
	if(result != 0) {
	num = num / result;
	denum = denum / result;
	}
}



void Rational::Rational(int _num , int _denum) {
	if(denum == 0) {
	std::cout << "__ERROR__ ";
	std::exit;	
	}
	helper_reduce( _num, _denum);
	if(_denum < 0 ) _num *= -1;
}

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
Rational& Rational:: operator++ () {
	num += denum;
return *this;
}
Rational& Rational:: operator++(int) {
	Rational temp = *this;
	num += denum;	
return temp;
}
Rational& Rational:: operator-- () {
	num -= denum;
return *this;
}
Rational& Rational:: operator-- (int) {
	Rational temp = *this;
	num -= denum;
return temp;
}
bool Rational::operator!(){
	return (num==0);
}
Rational& Rational:: operator+= (const Rational& other){
	int res = std::lcm(denum, other.denum);
	
	num = (res/denum*num) + (res/other.denum*other.num);
	denum = res;
	helper_reduce(num ,denum);
return *this;						
}

Rational& Rational:: operator-=(const Rational& other) {
 	int res = std::lcm(denum, other.denum);
  
        num = (res/denum*num) - (res/other.denum*other.num);
        denum = res;
        helper_reduce(num ,denum);
return *this;
}
Rational& Rational:: operator*=(const Rational& other) {
	num *= other.num;
	denum *= other.denum;
	helper_reduce(num, denum); 
return *this;
}
 Rational& Rational:: operator/=(const Rational& other) {
        num *= other.denum;
        denum *= other.num;
        helper_reduce(num, denum);
return *this;
}
  



