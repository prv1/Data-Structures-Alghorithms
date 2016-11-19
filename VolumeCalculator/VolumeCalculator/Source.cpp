/*
Phillip Viau
accepts mass and density input then outputs volume
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float mass, density, volume;

	cout << "Enter mass: ";
	cin >> mass;
	cout << "Enter density: ";
	cin >> density;
	volume = mass / density;
	cout << setprecision(2) << fixed << volume << endl;

	system("pause");
	return 0;

}