/*
Phillip Viau
Gets entire line and assigns to variables then reoutputs the information to a new file with new salary
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string firstName = "", lastName = "";
	float salary = 0.0f, salaryIncrease = 0.0f;

	
	//cout << "Enter a word: > ";
	//cin >> text;
	ifstream readFile;
	ofstream writeFile;
	readFile.open("in.txt");
	writeFile.open("out.txt");
	

	while (readFile.good()) {
		readFile >> lastName >> firstName >> salary >> salaryIncrease;
		salary = salary + (salary * (salaryIncrease/100));
		writeFile << lastName + " " << firstName + " " <<  salary  << endl;
		//cout << text << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}