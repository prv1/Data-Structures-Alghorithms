/*
* driver program for the Point2D Class demo
*
* author james t. madine
*/

#include <iostream>

#include "Point2D.h"
using namespace std;


int main() {

	Point2D p1(3, 4);
	Point2D p2(2, 3);
	Point2D p3;
	cout << "We now have " << Point2D::numberOfPoints2D << " created." << endl;
	p3 = p1 + p2;

	//p1 = p2 - p3;
	cout << "We now have " << Point2D::numberOfPoints2D << " created." << endl;
	cout << p3 << endl;
	cout << p1 << endl;
	//if (p1 == p1) {
		//cout << "True" << endl;
	//}
	system("pause");
	return 0;
}