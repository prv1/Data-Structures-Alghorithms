#include "Rectangle.h"

int main() {

	Rectangle r1 = Rectangle(2, 5);
	Rectangle r2 = Rectangle(7, 6);
	Rectangle r3 = Rectangle(14, 12);
	Rectangle r4 = Rectangle(75, 22);
	Rectangle r5 = Rectangle(12, 99);
	Rectangle r6;

	r6 = r2 + r1;

	r2++;
	++r3;
	cout << r6 << " (9, 11)" << endl;
	cout << r2 << " (8, 7)" << endl;
	cout << r3 << " (15, 13)" << endl;
	cout << (r1 != r2) << " !=true " << endl;
	cout << (r4 <= r2) << " <=false " << endl;
	cout << (r6 == r6) << " ==true " << endl;
	cout << (r2 >= r3) << " >=false " << endl;
	cout << (r5 > r2) << " >true " << endl;
	cout << (r1 < r2) << " <true " << endl;



	system("pause");
	return 0;
}