#pragma once
#include <iostream>

using namespace std;
#ifndef POINT_2D
#define POINT_2D



/*
* Model a point in 2D space in any of the 4 quardrents
*
* author james t. madine
*/
class Point2D {

private:
	int x;
	int y;

public:

	/*
	* Connstructor for the Point2D object
	* if the user specifies 0 parameters, then
	*    both x and y are initialized to 0.
	* if the user specifies 1 parameters, then
	*    x will will be assigned that value
	*    and y are initialized to 0.
	* if the user specifies 2 parameters, then
	*    x will will be assigned the first parameter
	*    and y the second parameter.
	*
	* param int x is the first user specified value
	* param int y is the second user specified value
	*/
	Point2D(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
		
	}
	/*
	Removes the Point2D from memory allowing that memory to be reused
	*/

	~Point2D() {

	}

	/*
	* accessor for x coordinate
	*
	* return the x coordinate
	*/
	int getX() const { return this->x; }

	/*
	* accessor for y coordinate
	*
	* return the y coordinate
	*/
	int getY() const { return this->y; }

	/*
	* mutator for the x coordinate
	*
	* param int x is the user supplied value for
	*       the coordinate x
	*/
	void setX(int x) { this->x = x; }

	/*
	* mutator for the y coordinate
	*
	* param int y is the user supplied value for
	*       the coordinate y
	*/
	void setY(int y) { this->y = y; }

	/*
	* Combines invoker object and adds the variables values from rhs object to the invoker and returns the new added values from the object to the calling function
	*/
	Point2D& operator+(const Point2D& rhs) const {
		return Point2D(this->getX() + rhs.getX(), this->getY() + rhs.getY());
	}

	/*
	* Combines invoker object and subtracts the variables values from rhs object to the invoker and returns the new subtracted values from the object to the calling function
	
	Point2D& operator+(const Point2D& rhs) const {
		return Point2D(this->getX() + rhs.getX(), this->getY() + rhs.getY());
	}*/
	

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
	friend ostream& operator<<(ostream& os, const Point2D& p) { 
		return os << "(" << p.getX() << ", " << p.getY() << ")";
	}
};

#endif // !POINT_2D