#ifndef HEADER_HPP
#define HEADER_HPP
#include <numeric>

class Rational {

private:

	int num;
	int denum;
	void helper_reduce();
public:
	
	Rational(): num{0}, denum{1} {}
	Rational(int num): num{num}, denum{1} {}
	Rational(int ,int);
	Rational(const Rational& other):num{other.num},denum{other.denum} {}
	Rational(Rational&& other):num(other.num),denum{other.denum}{
		other.num =0;
		other.denum =1;
	
	}
	
	Rational& operator=(const Rational&);
	Rational& operator= (Rational&&);
	~Rational() = default;
public:

	Rational operator+ () const {return *this;}
	Rational operator- () const{return Rational(-num, denum);}
	Rational& operator++ ();
	Rational operator++ (int);
	Rational& operator--();
	Rational operator--(int);
	bool operator!();
 	
public:

	
	Rational& operator+=(const Rational& other);
   	Rational& operator-=(const Rational& other);
    	Rational& operator*=(const Rational& other);
    	Rational& operator/=(const Rational& other);

	
public:

	friend Rational operator+ (const Rational& other1 , const Rational other2);
	friend Rational operator- (const Rational& other1 , const Rational other2);
 	friend Rational operator* (const Rational& other1 , const Rational other2);
 	friend Rational operator/ (const Rational& other1 , const Rational other2);



public:
	bool friend operator==(const Rational& other1, const Rational& other2);
	bool friend operator!=(const Rational& other1, const Rational& other2);	
	bool friend operator>=(const Rational& other1, const Rational& other2);
	bool friend operator<=(const Rational& other1, const Rational& other2);
	bool friend operator>(const Rational& other1, const Rational& other2);
	bool friend operator<(const Rational& other1, const Rational& other2);

public:
	friend std::ostream& operator<< (std::ostream& ost,const  Rational& other);
	friend std::istream& operator>> (std::istream& ist, Rational& other);

public:
	int numerator()const { return num;}
	int denumerator()const {return denum;}

public:
	
	explicit operator double()const { 
	return static_cast<double>(num)/denum ;
}
};







#endif 
