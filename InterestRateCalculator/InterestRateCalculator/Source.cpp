/*
Phillip Viau on 04/27/2016
Calculates unpaid balance using daily average balance
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



int main() {
	float averageDailyBalance, netBalance, d1, d2, interest, payment, interestRate;

	cout << "Enter you balance: > ";
	cin >> setprecision(2) >> netBalance;
	cout << "Enter amount paid: > ";
	cin >> setprecision(2) >> payment;
	cout << "Enter days in billing cycle: > ";
	cin >> setprecision(0) >> d1;
	cout << "Enter number of days payment is made before billing cycle: > ";
	cin >> setprecision(0) >> d2;
	cout << "Enter interest rate: > ";
	cin >> setprecision(4) >> interestRate;

	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
	interest = averageDailyBalance * interestRate;

	cout << "Your interest is: $" << setprecision(2) << interest << endl;

	system("pause");
	return 0;
}

