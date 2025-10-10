#ifndef "HEADER_HPP"
#define "HEADER_HPP"


class Rational {

private:

	int num;
	int denum;
	static void helper_reduce(int& num, int& denum);
public:
	
	Rational(): num{0}, denum{1} {}
	Rational(int num): num{num}, denum{1} {}
	Rational(int ,int);
	Rational(const Rational& oth):num{other.nnum},denum{other.denum} {}
	Rational(Rational&& oth):num(other.num),denum{other.denum}{
		oth.num =0;
		oth.denum =1;
	
	}
	
	Rational& operator=(const Rational&);
	Rational& operator= (Rational&&);
	~Rational() = default;
public:

	Rational operator+ () const {return *this;}
	Rational operator- () const{return Rational(-num, denum);}
	Rational operator++ ();
	Rational operator++ (int);
	Rational operator--();
	Rational operator--(int);
	Rational operator!();
 	
public:

	
	Rational& operator+=(const Rational& other);
   	Rational& operator-=(const Rational& other);
    	Rational& operator*=(const Rational& other);
    	Rational& operator/=(const Rational& other);

	
public:





};











#endif 
