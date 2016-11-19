
#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
using namespace std;

class Rectangle {

private:
double length, width;
static int numberOfRectangles;

public:

Rectangle(double length = 0, double width = 0) {
this->setLength(length);
this->setWidth(width);
}

Rectangle(const Rectangle& rectangle) {
    this-> Rectangle(rectangle.getLength(), rectangle.getWidth());
}

~Rectangle(){}

void setLength(double length) {
    this->length = length;
}

void setWidth(double width) {
    this->width = width;
}

double area() const {
    return this->getLength() * this->getWidth();
}

double perimeter() const {
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
    return (Rectangle(this->getLength() == rhs.getLength(), this->getWidth() == rhs.getWidth()) ? true : false);
}

bool Rectangle::operator!=(const Rectangle& rhs) const {
    return (Rectangle(this->getLength() != rhs.getLength(), this->getWidth() != rhs.getWidth()) ? true : false);
}

bool Rectangle::operator<=(const Rectangle& rhs) const {
    return (Rectangle(this->getLength() <= rhs.getLength(), this->getWidth() <= rhs.getWidth()) ? true : false);
}

bool Rectangle::operator<(const Rectangle& rhs) const {
    return (Rectangle(this->getLength() < rhs.getLength(), this->getWidth() < rhs.getWidth()) ? true : false);
}

bool Rectangle::operator>=(const Rectangle& rhs) const {
    return (Rectangle(this->getLength() >= rhs.getLength(), this->getWidth() >= rhs.getWidth()) ? true : false);
}

bool Rectangle::operator>(const Rectangle& rhs) const {
    return (Rectangle(this->getLength() > rhs.getLength(), this->getWidth() > rhs.getWidth()) ? true : false);
}

friend ostream& Rectangle::operator<<(ostream& os, const Rectangle& rectangle) {
    return os << this->getLength() << ", " << this->getWidth();
}

};

#endif

