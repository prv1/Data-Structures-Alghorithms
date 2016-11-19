/*

*/


#include <iostream>

using namespace std;

// prototypes

	float add(float num1, float num2);
	float subtract(float num1, float num2);
	float multiply(float num1, float num2);
	float divide(float num1, float num2);
	float returnLargest(float num1, float num2);
	void swapValues(float num1, float num2);


int main() {
	float num1, num2;
	cout << "Enter two numbers \nFirst Number: >";
	cin >> num1;
	cout << "Second Number: >";
	cin >> num2;

	cout << "You numbers added is: " << add(num1, num2) << endl <<
		" Subtracted is " << subtract(num1, num2) << endl <<
		" Multiplied is " << multiply(num1, num2) << endl <<
		" Divided is " << divide(num1, num2) << endl << 
	" Largest number is " << returnLargest(num1, num2) << endl <<
	" Numbers swapped " << swapValues(num1, num2) << endl;
	system("pause");
	return 0;

}

float swapValues(float num1, float num2) {



	float temp = num1;
	num1 = num2;
	num2 = temp;
	
	return num2;
}

float returnLargest(float num1, float num2) {
	return (num1 > num2) ? num1 : num2;
}


float add(float num1, float num2) {
	return num1 + num2;
}

float subtract(float num1, float num2) {
	return num1 - num2;
}

float multiply(float num1, float num2) {
	return num1 * num2;
}

float divide(float num1, float num2) {
	return num1 / num2;
}