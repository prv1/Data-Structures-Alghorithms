#include <iostream>
using namespace std;


int main() {


	int* x;
	int y = 5;

	x = &y;

	x++;

	if (*x == y++)
		cout << "Holy Cow" << endl;
	else
		cout << "Agh" << endl;
	cout << *x << endl;
	cout << y << endl;
	system("pause");
	return 0;
}