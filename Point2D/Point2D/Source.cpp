/*
* driver program for the Point2D Class demo
*
* author james t. madine
*/

#include <iostream>

#include "ColorH.h"
//#include "Point2D.h"
using namespace std;


int main() {

	ColorH p1(3, 4, 5);
	ColorH p2(2, 3, 4);
	ColorH p3;

	p3 = p1 + p2;

	//p1 = p2 - p3;

	cout << p3 << endl;
	cout << p1 << endl;
	if (p1 == p1) {
		cout << "True" << endl;
	}
	system("pause");
	return 0;
}