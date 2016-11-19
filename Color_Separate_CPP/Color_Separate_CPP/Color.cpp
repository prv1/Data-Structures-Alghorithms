#include "Color.h"
Color::Color(int red, int green, int blue) {
	setRed(red);
	setGreen(green);
	setBlue(blue);
}

/*
* Parses Color from memory allowing reuse
*/

Color::~Color() {

}

void Color::setRed(int colorComponent) { this->red = colorComponent > max ? max : colorComponent < min ? min : colorComponent; }

void Color::setGreen(int colorComponent) { this->green = colorComponent > max ? max : colorComponent < min ? min : colorComponent; }

void Color::setBlue(int colorComponent) { this->blue = colorComponent > max ? max : colorComponent < min ? min : colorComponent; }

int Color::getRed() const { return this->red; }// > max ? max : this->red < min ? min : this->red; }

int Color::getGreen() const { return this->green; }// > max ? max : this->green < min ? min : this->green; }

int Color::getBlue() const { return this->blue; }// > max ? max : this->blue < min ? min : this->blue; }

Color& Color::operator+(const Color& rhs) const { return Color(this->getRed() + rhs.getRed(), this->getGreen() + rhs.getGreen(), this->getBlue() + rhs.getBlue()); }

Color& Color::operator-(const Color& rhs) const { return Color(this->getRed() - rhs.getRed(), this->getGreen() - rhs.getGreen(), this->getBlue() - rhs.getBlue()); }

bool Color::operator==(Color const& rhs) {
	return (this->getRed() == rhs.getRed() && this->getGreen() == rhs.getGreen() && this->getBlue() == rhs.getBlue()) ? true : false;
}

Color& Color::operator++() {
	this->setRed(this->getRed() + 1);
	this->setGreen(this->getGreen() + 1);
	this->setBlue(this->getBlue() + 1);
	return *this;
}

Color& Color::operator--() {
	this->setRed(this->getRed() - 1);
	this->setGreen(this->getGreen() - 1);
	this->setBlue(this->getBlue() - 1);
	return *this;
}

Color Color::operator+(int i) {
	this->setRed(this->getRed() + i);
	this->setGreen(this->getGreen() + i);
	this->setBlue(this->getBlue() + i);
	return *this;
}

Color Color::operator-(int i) {
	this->setRed(this->getRed() - i);
	this->setGreen(this->getGreen() - i);
	this->setBlue(this->getBlue() - i);
	return *this;
}

ostream& operator<<(ostream& os, Color const& color) {
	return os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();

}