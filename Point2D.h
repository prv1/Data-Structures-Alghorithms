#include <iostream>

using namespace std;

/*
 * Model a point in 2D space in any of the 4 quardrents
 *
 * author james t. madine
 */

template<class T>
class Point2D {


private:
	T x;
	T y;

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
	Point2D(T x = 0, T y = 0) {
		this->x = x;
		this->y = y;
	}

	/*
	 * accessor for x coordinate
	 *
	 * return the x coordinate
	 */
	T getX() const { return this->x; }

	/*
	* accessor for y coordinate
	*
	* return the y coordinate
	*/
	T getY() const { return this->y; }

	/*
	 * mutator for the x coordinate 
	 *
	 * param int x is the user supplied value for
	 *       the coordinate x
	 */
	void Point2D<T>::setX(T x) { this->x = x; }

	/*
	* mutator for the y coordinate
	*
	* param int y is the user supplied value for
	*       the coordinate y
	*/
	void Point2D<T>::setY(T y) { this->y = y; }

	Point2D<T>& Point2D<T>::operator+(const Point2D&<T> lhs) const {
		return Point2D<T>(this->getX() + lhs.getX(), this->getY() + lhs.getY());
	}

	

	friend ostream& operator<<(ostream& os, const Point2D<T>& p) {
		os << "(" << p.getX() << ", " << p.getY() << ")";
		return os;
	}
};

