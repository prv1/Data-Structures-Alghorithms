/*
Phillip Viau
04/19/2016
Calculates milk profit based on user input
*/

#include <iostream>
#include <string>
using namespace std;




int main() {

	// main variables
	const float costOfLiter = 0.38f, profitOfCarton = 0.27f, capacityOfCarton = 3.78f;
	float milkProduced;
	int cartonsNeeded;
	cout << "Total amount of milk produced in morning ";
	cin >> milkProduced;
	cartonsNeeded = milkProduced / capacityOfCarton;
	cout << "Cartons needed " << static_cast<int>(milkProduced / capacityOfCarton) << endl;
	cout << "Cost of Producing milk $" << cartonsNeeded * costOfLiter << endl;
	cout << "Cost of Profit of milk $" << cartonsNeeded * profitOfCarton << endl;
	
	system("pause");
	return 0;
}

void say(string text, float num) {
	cout << text + " " << num;
}