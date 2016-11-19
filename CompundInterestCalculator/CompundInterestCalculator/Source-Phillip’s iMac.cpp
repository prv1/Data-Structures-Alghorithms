/*

5.5% interest year applied monthly for 45 years, deposit $100 monthly. How much would have at the end

How much would it last with $30000 yearly withdrawal
*/

#include <iostream>
using namespace std;
const float INTEREST_RATE = 0.055f, MONTHLY_CONTRIBUTIONS = 200.0f, YEARLY_WITHDRAWALS = 30000.0f;
const int TOTAL_YEARS = 45, MONTHS_IN_YEAR = 12;
const double COMPOUND_INTEREST_RATE = INTEREST_RATE / MONTHS_IN_YEAR;
float balance = 000.0f, totalYears = 0.0f;
int totalMonths = 0;


int main() {

	

	for (int i = 0; i < TOTAL_YEARS * MONTHS_IN_YEAR; i++) {
		balance =  (balance + (balance * COMPOUND_INTEREST_RATE)) + MONTHLY_CONTRIBUTIONS;
		cout << "Current Balance $" << balance << endl;
		
	}

	totalMonths = static_cast<int>(balance / YEARLY_WITHDRAWALS) * 12;
	totalYears = static_cast<float>(balance / YEARLY_WITHDRAWALS);

	//while (balance > 0) {

	//}

	cout << "Total Balance after " << TOTAL_YEARS << " years is $" << balance << " will last " << totalYears << " years and a total of " << totalMonths << " months" << endl;
	system("pause");
	return 0;
}