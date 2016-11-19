/*

set x = 1234
set width to 10
print x 
	left justified
	right justified
	left justified filled with asterisks
	right****************
	show point
*/

#include <iostream>
#include <iomanip>


using namespace std;
int main() {
	int x = 1234;
	int width = 10;
	char fill = '*';

	cout << setfill(fill);
	cout << x << setw(width) << endl;

	system("pause");
	return 0;

}
