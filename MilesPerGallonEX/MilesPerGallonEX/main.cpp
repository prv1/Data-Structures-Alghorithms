/*

*/
// preprocessor directive
#include <iostream>
#include <string>;
using namespace std;

float gallons;
float mpg;

int main()
{

	cout << "Enter your fuel tank capacity? > ";
	cin >> gallons;


	cout << "Enter you MPG for your vehicle? > ";
	cin >> mpg;
	
	
	
	cout << "Total miles able to be driven " << gallons * mpg << " miles" << endl;
	system("pause");
	return 0;
}




