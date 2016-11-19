#ifndef RATIONAL
#define RATIONAL
#include <iostream>
using namespace std;
/*
* Model a rational and return calculated values
*
* author phillip r viau on 05/30/2016
*/
class Rational {

private:
	/*
	* param numerator
	* param denominator
	* 
	*/
	int numerator, denominator;


public:

	static int numberOfRationals;

	/*
	* Connstructor for the Rational object
	* if the user specifies 0 parameters, then
	*    both numerator and denominator are initialized to 0.
	* if the user specifies 1 parameters, then
	*    numerator will will be assigned that value
	*    and denominator are initialized to 0.
	* if the user specifies 2 parameters, then
	*    numerator will will be assigned the first parameter
	*    and denominator the second parameter.
	*
	* param int numerator is the first user specified value
	* param int denominator is the second user specified value
	*/
	Rational(int numerator, int denominator) {
		this->setNumerator(numerator);
		this->setDenominator(denominator);
		numberOfRationals++;
	}


	Rational(const Rational& r) {
		this->setNumerator(r.getNumerator());
		this->setDenominator(r.getDenominator());
	}
	/*
	Removes the Rational from memory allowing that memory to be reused
	*/
	~Rational() { numberOfRationals--; }
	/*
	* mutator for the numerator coordinate
	*
	* param int numerator is the user supplied value for
	*       the coordinate numerator
	*/
	void setNumerator(int numerator) {
		this->numerator = numerator == 0 ? 1 : numerator;
	}
	/*
	* mutator for the denominator coordinate
	*
	* param int denominator is the user supplied value for
	*       the coordinate denominator
	*/
	void setDenominator(int denominator) {
		this->denominator = denominator == 0 ? 1 : denominator;
	}
	/*
	* accessor for numerator coordinate
	*
	* return the numerator coordinate
	*/
	int getNumerator() const {
		return this->numerator == 0 ? 1 : numerator;
	}
	/*
	* accessor for denominator coordinate
	*
	* return the denominator coordinate
	*/
	int getDenominator() const {
		return this->denominator == 0 ? 1 : denominator;
	}
	/*
	* Combines invoker object and adds the variables values from rhs object to the invoker and returns the new added values from the object to the calling function
	*/
	Rational& operator+(const Rational& rhs) const {
		if (this->getDenominator() == rhs.getDenominator())
			return Rational(this->getNumerator() + rhs.getNumerator(), this->getDenominator());


		return Rational(((this->getNumerator() * rhs.getDenominator()) + (this->getDenominator() * this->getNumerator())), this->getDenominator() * rhs.getDenominator());
	}
	/*
	* Subtracts invoker object and adds the variables values from rhs object to the invoker and returns the new subtracted values from the object to the calling function
	*/
	Rational& operator-(const Rational& rhs) const {
		if (this->getDenominator() == rhs.getDenominator())
			return Rational(this->getNumerator() - rhs.getNumerator(), this->getDenominator());


		return Rational((this->getNumerator() * rhs.getDenominator()) - (rhs.getDenominator() * this->getNumerator()), this->getDenominator() * rhs.getDenominator());
	}
	/*
	* Multiplies invoker object and the variables values from rhs object to the invoker and returns the new multiplied numerators from the object to the calling function
	*/
	Rational& operator*(const Rational& rational) const {
		return Rational(this->getNumerator() * rational.getNumerator(), this->getDenominator() * rational.getDenominator());
	}
	/*
	* Divides invoker object and the variables values from rhs object to the invoker and returns the new divised numerators from the object to the calling function
	*/
	Rational& operator/(const Rational& rational) const { 
		return Rational(this->getNumerator() / rational.getDenominator(), this->getDenominator() / rational.getNumerator()); 
	}
	
	/*
	* Incremements invoker object and decreases the variables values from invoker object by one and returns the new incremented values from the object to the calling function
	*/
	Rational& operator++() {
		this->setNumerator(this->getNumerator() + 1);
		this->setDenominator(this->getDenominator());
		return *this;
	}
	/*
	* Increments invoker object and decreases the variables values from invoker object by one and returns the new Incremented values from the object to the calling function
	*/
	Rational& operator++(int) {
		this->setNumerator(this->getNumerator() + 1);
		this->setDenominator(this->getDenominator());
		return *this;
	}
	/*
	* Decrements invoker object and decreases the variables values from invoker object by one and returns the new decremented values from the object to the calling function
	*/
	Rational& operator--() {
		this->setNumerator(this->getNumerator() - 1);
		this->setDenominator(this->getDenominator());
		return *this;
	}
	/*
	* Decrements invoker object and decreases the variables values from invoker object by one and returns the new decremented values from the object to the calling function
	*/
	Rational& operator--(int) {
		this->setNumerator(this->getNumerator() - 1);
		this->setDenominator(this->getDenominator());
		return *this;
	}

	/*
	* Defines how to insert a Rational object into a stream
	* The word friend gives us the ability to have dissimilar types on the left and right of the binary operator
	* has access to all the data fields in the class regarless of access modifiers
	* marks this method as a free function
	*
	* param os stream where we will insert into
	* param is constant reference to the Rational Object we intend to insert
	*
	* return os so that we can chain this stream to multiple objects
	*/

	friend ostream& operator<<(ostream& os, const Rational& rational) {
		return os << rational.getNumerator() << "/" << rational.getDenominator();
	}


	
};

#endif
