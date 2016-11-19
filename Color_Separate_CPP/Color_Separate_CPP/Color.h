/*
* Philllip Viau on 05/14/2016
* 
*
*/
#pragma once
#include <iostream>

using namespace std;
#ifndef COLOR
#define COLOR


/*
* Model a color object that could be used in any application program requiring such functionality
*
* 
*/
class Color {



private:
	int red;
	int green;
	int blue;
	int min = 0;
	int max = 255;
public:

	/*
	* Connstructor for the Color object
	* if the user specifies 0 parameters, then
	*    red, green, and blue are initialized to 0.
	* if the user specifies 1 parameters, then
	*    red will will be assigned that value
	*    and gree and blue are initialized to 0.
	* if the user specifies 2 parameters, then
	*    red will will be assigned the first parameter,
	*    the second parameter of green and the third parmeter of blue.
	*
	* param int red is the first user specified value
	* param int green is the second user specified value
	* param int blue is the third user specified value
	*/
	Color(int red = 0, int green = 0, int blue = 0);

	/*
	 * Parses Color from memory allowing reuse
	 */

	~Color();

	/*
	* mutator for the red int
	*
	* param int red is the user supplied value for
	*       the integer red
	*/
	void setRed(int colorComponent);

	/*
	* mutator for the green int
	*
	* param int green is the user supplied value for
	*       the integer green
	*/
	void setGreen(int colorComponent);

	/*
	* mutator for the blue int
	*
	* param int blue is the user supplied value for
	*       the integer green
	*/
	void setBlue(int colorComponent);

	/*
	* accessor for red integer
	*
	* return the red integer
	*/
	int getRed() const;

	/*
	* accessor for green integer
	*
	* return the green integer
	*/
	int getGreen() const;

	/*
	* accessor for blue integer
	*
	* return the blue integer
	*/
	int getBlue() const;

	/*
	* Combines invoker object and adds the variables values from rhs object to the invoker and returns the new added values from the object to the calling function
	*/
	Color& operator+(const Color& rhs) const;

	/*
	* Subtracts invoker object and subtracts the variables values from rhs object to the invoker and returns the new subtracted values from the object to the calling function
	*/
	Color& operator-(const Color& rhs) const;
	
	/*
	* Compares invoker object and adds the variables values from rhs object to the invoker and returns the boolean value from the object to the calling function
	*/
	bool operator==(Color const& rhs);
	

	/*
	* Increments invoker object and increases the variables values from invoker object by one and returns the new incremented values from the object to the calling function
	*/
	Color& Color::operator++();
	
	/*
	* Decrements invoker object and decreases the variables values from invoker object by one and returns the new decremented values from the object to the calling function
	*/
	Color& Color::operator--();

	Color Color::operator+(int i);

	Color Color::operator-(int i);

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
	* param color constant reference to the Color Object we intend to insert
	*
	* return os so that we can chain this stream to multiple objects
	*/
	friend ostream& operator<<(ostream& os, Color const& color);


};



#endif
