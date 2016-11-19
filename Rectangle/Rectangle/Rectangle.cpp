#include "Rectangle.h"

int Rectangle::numberOfRectangles;

Rectangle::Rectangle(double length, double width) {
	this->setLength(length);
	this->setWidth(width);
	numberOfRectangles++;
}

Rectangle::Rectangle(const Rectangle& rectangle) {
	this->setLength(rectangle.getLength());
	this->setWidth(rectangle.getWidth());
}

Rectangle::~Rectangle() {numberOfRectangles--;}

void Rectangle::setLength(double length) {
	this->length = length;
}

void Rectangle::setWidth(double width) {
	this->width = width;
}

double Rectangle::getLength() const {
	return this->length;
}

double Rectangle::getWidth() const {
	return this->width;
}

double Rectangle::area() const {
	return this->getLength() * this->getWidth();
}

double Rectangle::perimeter() const {
	return this->getLength() * this->getWidth();
}

Rectangle Rectangle::operator+(const Rectangle& rhs) const {
	return Rectangle(this->getLength() + rhs.getLength(), this->getWidth() + rhs.getWidth());
}

Rectangle Rectangle::operator-(const Rectangle& rhs) const {
	return Rectangle(this->getLength() - rhs.getLength(), this->getWidth() - rhs.getWidth());
}

Rectangle Rectangle::operator++() {
	this->setLength(this->getLength() + 1);
	this->setWidth(this->getWidth() + 1);
	return *this;
}

Rectangle Rectangle::operator++(int) {
	this->setLength(this->getLength() + 1);
	this->setWidth(this->getWidth() + 1);
	return *this;
}

Rectangle Rectangle::operator--() {
	this->setLength(this->getLength() - 1);
	this->setWidth(this->getWidth() - 1);
	return *this;
}

Rectangle Rectangle::operator--(int) {
	this->setLength(this->getLength() - 1);
	this->setWidth(this->getWidth() - 1);
	return *this;
}

bool Rectangle::operator==(const Rectangle& rhs) const {
	return (this->area() == rhs.area()) ? true : false;
}

bool Rectangle::operator!=(const Rectangle& rhs) const {
	return (this->area() != rhs.area()) ? true : false;
}

bool Rectangle::operator<=(const Rectangle& rhs) const {
	return (this->area() <= rhs.area()) ? true : false;
}

bool Rectangle::operator<(const Rectangle& rhs) const {
	return (this->area() < rhs.area()) ? true : false;
}

bool Rectangle::operator>=(const Rectangle& rhs) const {
	return (this->area() >= rhs.area()) ? true : false;
}

bool Rectangle::operator>(const Rectangle& rhs) const {
	return (this->area() > rhs.area()) ? true : false;
}

ostream& operator<<(ostream& os, const Rectangle& rectangle) {
	return os << rectangle.getLength() << ", " << rectangle.getWidth();
}