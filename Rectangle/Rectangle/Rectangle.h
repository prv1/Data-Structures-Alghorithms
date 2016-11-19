
#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
using namespace std;

class Rectangle {

private:
	double length, width;
	

public:

	static int numberOfRectangles;

	/*
	* Connstructor for the Rectangle object
	* if the user specifies 0 parameters, then
	*    both length and width are initialized to 0.
	* if the user specifies 1 parameters, then
	*    length will will be assigned that value
	*    and width are initialized to 0.
	* if the user specifies 2 parameters, then
	*    length will will be assigned the first parameter
	*    and width the second parameter.
	*
	* param int length is the first user specified value
	* param int width is the second user specified value
	*/
	Rectangle(double length = 0, double width = 0);

	Rectangle(const Rectangle& rectangle);
	/*
	Removes the Rectangle from memory allowing that memory to be reused
	*/
	~Rectangle();
	/*
	* mutator for the length coordinate
	*
	* param double length is the user supplied value for
	*       the coordinate length
	*/
	void setLength(double length);
	/*
	* mutator for the width coordinate
	*
	* param double width is the user supplied value for
	*       the coordinate width
	*/
	void setWidth(double width);
	/*
	* accessor for length coordinate
	*
	* return the length coordinate
	*/
	double getLength() const;
	/*
	* accessor for width coordinate
	*
	* return the width coordinate
	*/
	double getWidth() const;
	/*
	* accessor for area of param length and width
	*
	* return the double
	*/
	double area() const;
	/*
	* accessor for perimeter of param length and width
	*
	* return the double
	*/
	double perimeter() const;
	/*
	* Combines invoker object and adds the variables values from rhs object to the invoker and returns the new added values from the object to the calling function
	*/
	Rectangle Rectangle::operator+(const Rectangle& rhs) const;
	/*
	* Subtracts invoker object and adds the variables values from rhs object to the invoker and returns the new subtracted values from the object to the calling function
	*/
	Rectangle Rectangle::operator-(const Rectangle& rhs) const;
	/*
	* Incremements invoker object and decreases the variables values from invoker object by one and returns the new incremented values from the object to the calling function
	*/
	Rectangle Rectangle::operator++();
	/*
	* Increments invoker object and decreases the variables values from invoker object by one and returns the new Incremented values from the object to the calling function
	*/
	Rectangle Rectangle::operator++(int);
	/*
	* Decrements invoker object and decreases the variables values from invoker object by one and returns the new decremented values from the object to the calling function
	*/
	Rectangle Rectangle::operator--();
	/*
	* Decrements invoker object and decreases the variables values from invoker object by one and returns the new decremented values from the object to the calling function
	*/
	Rectangle Rectangle::operator--(int);
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator==(const Rectangle& rhs) const;
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator!=(const Rectangle& rhs) const;
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator<=(const Rectangle& rhs) const;
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator<(const Rectangle& rhs) const;
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator>=(const Rectangle& rhs) const;
	/*
	* Compares invoker object of the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool Rectangle::operator>(const Rectangle& rhs) const;
	/*
	* Defines how to insert a Point2D object into a stream
	* The word friend gives us the ability to have dissimilar types on the left and right of the binary operator
	* has access to all the data fields in the class regarless of access modifiers
	* marks this method as a free function
	*
	* param os stream where we will insert into
	* param is constant reference to the Point2D Object we intend to insert
	*
	* return os so that we can chain this stream to multiple objects
	*/
	friend ostream& Rectangle::operator<<(ostream& os, const Rectangle& rectangle);

};

#endif

