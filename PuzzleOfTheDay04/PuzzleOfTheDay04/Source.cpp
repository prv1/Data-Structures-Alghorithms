/*
Phillip Viau on 05/06/2016


*/

#include <iostream>
using namespace std;
// Prototype
void calculations(float num1, float num2, float& sum, float& difference);


int main() {
	float num1 = 12.0, num2 = 6.0, sum = 0.0, difference = 0.0;
	calculations(num1, num2, sum, difference);
	cout << "Sum is: "  << sum << endl;
	cout << "Difference is: " << difference << endl;

	system("pause");
	return 0;
}

void calculations(float num1, float num2, float& sum, float& difference) { // function calculates sum and difference
	sum = num1 + num2;
	if (num1 > num2)
		difference = num1 - num2;
	else
		difference = num2 - num1;


}

