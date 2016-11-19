#include "Rational.h"


int Rational::numberOfRationals = 0;

int main() {
	
	Rational r1(1, 3);
	Rational r2(1, 4);
	Rational r3(2, 4);
	Rational r4(1, 7);
	Rational r5(1, 8);


	//cout << "Before Post-Inc " << r1;
	//r1++;
	//cout << " After Post-Inc " << r1 << endl;

	//cout << "Before Pre-Inc " << r2;
	//++r2;
	//cout << " After Pre-tInc " << r2 << endl;

	//cout << "Before Post-Dec " << r3;
	//r3--;
	//cout << " After Post-Dec " << r3 << endl;

	//cout << "Before Pre-Dec " << r4;
	//--r4;
	//cout << " After Pre-Dec " << r4 << endl;


	r5 = r1 + r2;
	cout << r5 << " = " << r1 << " + " << r2 << endl;

	r5 = r1 - r2;
	cout << r5 << " = " << r1 << " - " << r2 << endl;
	r5 = r1 - r2;
	cout << r5 << " = " << r1 << " * " << r2 << endl;
	r5 = r1 * r2;
	cout << r5 << " = " << r1 << " / " << r2 << endl;
	r5 = r1 / r2;

	cout << "Before Post Inc " << r1++ << " After Post Inc " << r1 << endl;
	cout << "Before Pre inc " << ++r2 << " After Pre Inc " << r2 << endl;
	cout << "Before Post Dec " << r3-- << " After Post Dec " << r3 << endl;
	cout << "Before Pre Dec " << --r4 << " After Pre Dec " << r4 << endl;

	cout << "There are " << Rational::numberOfRationals << endl;
	
	system("pause");
	return 0;
}