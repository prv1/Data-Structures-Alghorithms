#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct NumbNut{
	string name;
	int ID_Number;
	int* arrayOfNumbNuts;

	NumbNut() {}

	NumbNut(NumbNut& n) {
		this->name = n.name;
	}

	NumbNut operator=(const NumbNut& rhs) {
		this->name = rhs.name;
		this->ID_Number = rhs.ID_Number;
		this->arrayOfNumbNuts = new int[5];
		for (int i = 0; i < 5; ++i) {
			this->arrayOfNumbNuts[i] = rhs.arrayOfNumbNuts[i];
		}

		return *this;
	}

};

void print(NumbNut& numbNut) {

	cout << "Here is numbNut" << endl;
	cout << numbNut.name << endl;
	for (int i = 0; i < 5; ++i) {
		cout << setw(10) << right << numbNut.arrayOfNumbNuts[i] << endl;
	}


}



int main() {
	char inputName[15];

	NumbNut n1;
	cout << "Enter a persons name: ";
	cin.getline(inputName, 15);
	n1.name = inputName;
	n1.arrayOfNumbNuts = new int[15];
	for (int i = 0; i < 5; ++i) {
		
		n1.arrayOfNumbNuts[i] = rand() % 25 + 1;
	}

	print(n1);

	system("pause");


	NumbNut n2;
	n2 = n1;
	print(n2);
	n2.arrayOfNumbNuts[3] = 22;
	n1.name = "test";
	print(n1);
	print(n2);
	system("pause");

	return 0;
}