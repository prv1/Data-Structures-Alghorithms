#include <iostream>
#include <string>
using namespace std;
int inputValue, result;

int input(string);

int main() {
	result = input("Please enter an integer number to square: > ");
	cout << "You input " << inputValue << " is squared " << result << endl;
	system("pause");
	return 0;
}

int input(string text) {
	cout << text;
	cin >> inputValue;

	return inputValue * inputValue;
}