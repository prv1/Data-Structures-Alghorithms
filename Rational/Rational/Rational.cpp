//#include "Rational.h"
//
//int Rational::numberOfRationals = 0;
//
//Rational::Rational(int numerator, int denominator) {
//	this->setNumerator(numerator);
//	this->setDenominator(denominator);
//	numberOfRationals++;
//}
//
//
//Rational::Rational(const Rational& r) {
//	this->setNumerator(r.getNumerator());
//	this->setDenominator(r.getDenominator());
//}
//
//Rational::~Rational() { numberOfRationals--; }
//
//void Rational::setNumerator(int numerator) {
//	this->numerator = numerator;
//}
//
//void Rational::setDenominator(int denominator) {
//	this->denominator = denominator;
//}
//
//int Rational::getNumerator() const {
//	return this->numerator;
//}
//
//int Rational::getDenominator() const {
//	return this->denominator;
//}
//
////Rational Rational::operator+(const Rational& rhs) const {
////	return Rational(this->getNumerator() + rhs.getNumerator(), this->getDenominator() + rhs.getDenominator());
////}
////
////Rational Rational::operator-(const Rational& rhs) const {
////	return Rational(this->getNumerator() - rhs.getNumerator(), this->getDenominator() - rhs.getDenominator());
////}
//
//Rational Rational::operator++() {
//	this->setNumerator(this->getNumerator() + 1);
//	this->setDenominator(this->getDenominator() + 1);
//	return *this;
//}
//
//Rational Rational::operator++(int) {
//	this->setNumerator(this->getNumerator() + 1);
//	this->setDenominator(this->getDenominator() + 1);
//	return *this;
//}
//
//Rational Rational::operator--() {
//	this->setNumerator(this->getNumerator() - 1);
//	this->setDenominator(this->getDenominator() - 1);
//	return *this;
//}
//
//Rational Rational::operator--(int) {
//	this->setNumerator(this->getNumerator() - 1);
//	this->setDenominator(this->getDenominator() - 1);
//	return *this;
//}
//
//Rational& operator+(const Rational& rational) { return Rational(this->getNumerator() + rational.getNumerator(), this->getDenominator() + rational.getDenominator()); }
//
//Rational& operator-(const Rational& rational) const { return Rational(this->getNumerator() - rational.getNumerator(), this->getDenominator() - rational.getDenominator()); }
//
//Rational& operator*(const Rational& rational) const { return Rational(this->getNumerator() * rational.getNumerator(), this->getDenominator() * rational.getDenominator()); }
//
//Rational& operator/(const Rational& rational) const { return Rational(this->getNumerator() / rational.getNumerator(), this->getDenominator() / rational.getDenominator()); }
//
//
//ostream& operator<<(ostream& os, const Rational& rectangle) {
//	return os << rectangle.getNumerator() << "/" << rectangle.getDenominator();
//}