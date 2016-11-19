#include <iostream>

#ifndef RECTANGLE_H
#define RECTANGLE_H


using namespace std;


template<class T>
class Rectangle {

private:
	T length;
	T width;

public:

	static int numberOfRectangles;



	Rectangle(T length = 0, T width = 0);

	Rectangle(const Rectangle& rectangle) {

		this->length = rectangle.length;
		this->width = rectangle.width;

		numberOfRectangles++;

	}

	~Rectangle();

	void setLength(T length);
	void setWidth(T width);

	T getLength() const;
	T getWidth() const;

	T area() const;

	T perimeter() const;

	T operator+(const Rectangle<T> & rhs) const;
	T operator+(const T value) const;

	Rectangle operator++();
	Rectangle<T> operator++(T);

	Rectangle<T> operator--();
	Rectangle<T> operator--(int);

	bool operator==(const Rectangle<T>& rhs);
	bool operator!=(const Rectangle<T>& rhs);
	bool operator<=(const Rectangle<T>& rhs);
	bool operator<(const Rectangle<T>& rhs);
	bool operator>=(const Rectangle<T>& rhs);
	bool operator>(const Rectangle<T>& rhs);

	friend ostream& operator<<(ostream& os, const Rectangle<T>& r);

};
template<class T>
	Rectangle<T>::Rectangle(T length, T width) {
		
		this->length = length;
		this-> width = width;

		numberOfRectangles++;
	}
	template<class T>
	Rectangle<T>::Rectangle(const Rectangle<T>& rectangle) {

		this->length = rectangle.length;
		this->width = rectangle.width;

		numberOfRectangles++;

	}
	template<class T>
	Rectangle<T>::~Rectangle() { numberOfRectangles--; }
	template<class T>
	void Rectangle<T>::setLength(T length) { this->length = length; }
	template<class T>
	void Rectangle<T>::setWidth(T width)   { this->width = width; }
	template<class T>
	Rectangle<T>::getLength() const { return this->length; }
	template<class T>
	Rectangle<T>::getWidth() const { return this->width; }
	template<class T>
	Rectangle<T>::area() const { return this->getLength() * this->getWidth(); }
	template<class T>
	Rectangle<T>::perimeter() const { return 2 * this->getLength()  + 2 * this->getWidth(); }
	template<class T>
	Rectangle<T>::Rectangle operator+(const Rectangle<T> & rhs) const {
		
		return Rectangle(this->getLength() + rhs.getLength(),
						 this->getWidth() + rhs.getWidth());
	}
	template<class T>
	Rectangle<T>::Rectangle operator+(const T value) const {

		return Rectangle(this->getLength() + value,
						 this->getWidth() + value);
	}
	template<class T>
	Rectangle<T>::Rectangle operator++() {
		this->setLength(this->getLength() + 1);
		this->setWidth(this->getWidth() + 1);

		return *this;
	}
	template<class T>
	Rectangle<T>::Rectangle operator++(T) {

		Rectangle temp(*this);

		this->setLength(this->getLength() + 1);
		this->setWidth(this->getWidth() + 1);

		return temp;
	}
	template<class T>
	Rectangle<T>::Rectangle operator--() {
		this->setLength(this->getLength() - 1);
		this->setWidth(this->getWidth() - 1);

		return *this;
	}
	template<class T>
	Rectangle<T>::Rectangle operator--(int) {
		Rectangle<T> temp(*this);
		this->setLength(this->getLength() - 1);
		this->setWidth(this->getWidth() - 1);

		return temp;
	}
	template<class T>
	Rectangle<T>::bool operator==(const Rectangle<T>& rhs) {
		return this->area() == rhs.area();
	}
	template<class T>
	Rectangle<T>::bool operator!=(const Rectangle<T>& rhs) {
		return this->area() != rhs.area();
	}
	template<class T>
	Rectangle<T>::bool operator<=(const Rectangle<T>& rhs) {
		return this->area() <= rhs.area();
	}
	template<class T>
	Rectangle<T>::bool operator<(const Rectangle<T>& rhs) {
		return this->area() < rhs.area();
	}
	template<class T>
	Rectangle<T>::bool operator>=(const Rectangle<T>& rhs) {
		return this->area() >= rhs.area();
	}
	template<class T>
	Rectangle<T>::bool operator>(const Rectangle<T>& rhs) {
		return this->area() > rhs.area();
	}
	template<class T>
	Rectangle<T>::ostream& operator<<(ostream& os, const Rectangle<T>& r) {
		os << "[" << r.getLength() << ", " << r.getWidth() << "]";
		return os;
	}




#endif


