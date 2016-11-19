#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	string name = "Phillip Viau";
	string course = "SSD552";
	string description = "Data Structures and Alghorithms";

	cout << left;
	cout << setw(35) << setfill('*') << name ;
	cout << setw(10) << course;
	cout << setw(15) << description << endl;

	system("pause");
	return 0;

}