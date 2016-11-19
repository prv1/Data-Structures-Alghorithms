#include <iostream>

#ifndef RECTANGLE_H
#define RECTANGLE_H


using namespace std;

class Rectangle {

private:
	double length;
	double width;

public:

	static int numberOfRectangles;



	Rectangle(double length = 0, double width = 0) {

		this->length = length;
		this->width = width;

		numberOfRectangles++;
	}

	Rectangle(const Rectangle& rectangle) {

		this->length = rectangle.length;
		this->width = rectangle.width;

		numberOfRectangles++;

	}

	~Rectangle() { numberOfRectangles--; }

	void setLength(double length) { this->length = length; }
	void setWidth(double width) { this->width = width; }

	double getLength() const { return this->length; }
	double getWidth() const { return this->width; }

	double area() const { return this->getLength() * this->getWidth(); }

	double perimeter() const { return 2 * this->getLength() + 2 * this->getWidth(); }

	Rectangle operator+(const Rectangle & rhs) const {

		return Rectangle(this->getLength() + rhs.getLength(),
			this->getWidth() + rhs.getWidth());
	}

	Rectangle operator+(const int value) const {

		return Rectangle(this->getLength() + value,
			this->getWidth() + value);
	}






	Rectangle operator++() {
		this->setLength(this->getLength() + 1);
		this->setWidth(this->getWidth() + 1);

		return *this;
	}

	// post increment
	Rectangle operator++(int) {

		Rectangle temp(*this);

		this->setLength(this->getLength() + 1);
		this->setWidth(this->getWidth() + 1);

		return temp;
	}








	Rectangle operator--() {
		this->setLength(this->getLength() - 1);
		this->setWidth(this->getWidth() - 1);

		return *this;
	}
	Rectangle operator--(int) {
		Rectangle temp(*this);
		this->setLength(this->getLength() - 1);
		this->setWidth(this->getWidth() - 1);

		return temp;
	}

	bool operator==(const Rectangle& rhs) {
		return this->area() == rhs.area();
	}

	bool operator!=(const Rectangle& rhs) {
		return this->area() != rhs.area();
	}

	bool operator<=(const Rectangle& rhs) {
		return this->area() <= rhs.area();
	}

	bool operator<(const Rectangle& rhs) {
		return this->area() < rhs.area();
	}

	bool operator>=(const Rectangle& rhs) {
		return this->area() >= rhs.area();
	}

	bool operator>(const Rectangle& rhs) {
		return this->area() > rhs.area();
	}

	friend ostream& operator<<(ostream& os, const Rectangle& r) {
		os << "[" << r.getLength() << ", " << r.getWidth() << "]";
		return os;
	}

};

#endif
