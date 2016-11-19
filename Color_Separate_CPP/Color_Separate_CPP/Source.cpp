
#include "Color.h"





int main() {

	Color p1(3, 4, 256);
	Color p2(2, 3, 4);
	Color p3;

	p3 = p1 + p2;

	//p1 = p2 - p3;
	++p1;
	cout << p3 << endl;
	cout << p1 << endl;
	if (p1 == p1) {
		cout << "True" << endl;
	}
	system("pause");
	return 0;

}