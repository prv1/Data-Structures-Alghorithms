/*
Phillip Viau on 05/06/2016
Allows user to enter name and hours worked, then calculates pay and displays entered inforamtion
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// prototypes
void  input(string& employeeName, float& hoursWorkedPerWeek);
float calculatePay(float hoursWorkedPerWeek);
void display(string& employeesName, float netPay);

void main() {

	string employeeName = "";
	float hoursWorkedPerWeek = 0.0f, netPay = 0.0f;
	
	// INPUT
	input(employeeName, hoursWorkedPerWeek);

	// PROCESS
	//netPay = calculatePay(hoursWorkedPerWeek); // process not even needed, can be completed by using function within display function

	// OUTPUT
	display(employeeName, calculatePay(hoursWorkedPerWeek)); // function outputs data and passes 

	system("pause");
}

void input(string& employeeName, float& hoursWorkedPerWeek) { // pass-by-reference of employee name and hours worked per week variables
	cout << "Please enter employee name: ";
	cin >> employeeName;
	cout << "Please enter hours worked per week: ";
	cin >> hoursWorkedPerWeek;
}

float calculatePay(float hoursWorkedPerWeek) {
	float hourlyRate = 10.00f; // defines hourly rate for pay
	if (hoursWorkedPerWeek > 40) { // if value passed is greater than 40 then runs this block
		hoursWorkedPerWeek = hoursWorkedPerWeek - 40; // subtracts 40 from value
		return ((hoursWorkedPerWeek * hourlyRate * 1.5f) + (40 * hourlyRate)) * 0.75f; // returns calulated pay with tima and half
	}
	
	return (hoursWorkedPerWeek * hourlyRate) * 0.75f; // returns netpay if less than 40 hours
}

void display(string& employeesName, float netPay) { // displays name and netpay based on entered info
	cout << "Employees Name: " << employeesName << " Net pay: $" << fixed << setprecision(2) << setw(10) << setfill('#') << netPay << endl; // displays employee name and formatted netpay
}