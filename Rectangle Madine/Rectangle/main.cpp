#include "Rectangle.h"
#include <string>
#include <iostream>

using namespace std;

int Rectangle<double>::numberOfRectangles = 0;

/*
 * Knonw bugs, calling Rectangle r1 calls the default constructor not my defined constructor
 */
void main() {
	char charInput[40];
	string name ;

	cout << "please enter your full name ";
	cin.getline(charInput, 24);
	name = charInput;
	cout << "Thank you " << name << endl << endl;
	
	Rectangle<int> r1;
	Rectangle<float> r2(2);
	Rectangle<int> r3(2, 3);
	Rectangle<int> r4(2, 3);
	Rectangle<int> r5(5, 6);
	Rectangle<int> r6(2, 3);
	Rectangle<int> r7(5, 6);
	Rectangle<int> r8(5, 6);
	Rectangle<int> r9(5, 6);
	
	cout << "Constructor test" << endl;
	cout << "There are 9 Rectangles, are there ? -> " << Rectangle<double>::numberOfRectangles << endl;
	

	//cout << "Accessor test" << endl;
	if (r3.getLength() == 2 && r3.getWidth() == 3)		
		cout << "Accessor Test \t\tPASSED!" << endl;
	else
			cout << "\tAccessor Test FAILED**!" << endl;		


	//cout << "Mutator test test" << endl;
	r1.setLength(5);
	r1.setWidth(6);
	if (r1.getLength() == 5 && r1.getWidth() == 6)
		cout << "Mutator Test \t\tPASSED!" << endl;
	else
		cout << "\tMutator Test FAILED**!" << endl;

	//cout << "Area test" << endl;
	if (r4.area() == 6)
		cout << "Mutator Test \t\tPASSED!" << endl;
	else
		cout << "Mutator Test \tFAILED**!" << endl;

	//cout << "Perimeter test" << endl;
	if (r4.perimeter() == 10)
		cout << "Perimeter Test \t\tPASSED!" << endl;
	else
		cout << "\tPerimeter Test FAILED**!" << endl;
		

	//cout << "operator+(const Rectangle& rhs) overload test" << endl;
	r1 = r4 + r5;
	if (r1.getLength() == 7 && r1.getWidth()  == 9)
		cout << "operator+(...) \t\tPASSED!" << endl;
	else
		cout << "\toperator+(...) FAILED**!" << endl;
	

	/*
	//*******************************
	//cout << r4 << endl;
	//cout << ++r4 << endl;
	//cout << r4++ << endl;
	//cout << r4 << endl;
	//cout << endl;
	//system("pause");
	//*******************************
	*/

	//cout << "operator++() overload test" << endl;
	r4++;
	if (r4.getLength() == 3 && r4.getWidth() == 4)
		cout << "operator++() \t\tPASSED!" << endl;
	else
		cout << "\toperator++() FAILED**!" << endl;
	
		

	//cout << "operator++(int) overload test" << endl;
	++r5;
	if (r5.getLength() == 6 && r5.getWidth() == 7)
		cout << "operator++(int) \tPASSED!" << endl;
	else
		cout << "\toperator++(int) FAILED**!" << endl;
	
		

	//cout << "operator--() overload test" << endl;
	r6--;
	if (r6.getLength() == 1 && r6.getWidth() == 2)
		cout << "operator--() \t\tPASSED!" << endl;
	else
		cout << "\toperator--() FAILED**!" << endl;
	
		

	//cout << "operator--(int) overload test" << endl;
	--r7;
	if (r7.getLength() == 4 && r7.getWidth() == 5)
		cout << "operator--(int) \tPASSED!" << endl;
	else
		cout << "\toperator--(int) FAILED**!" << endl;
	

	//cout << "operator==const Rectangle& rhs overload test" << endl;
	if (r8 == r9)
		cout << "operator==(...) \tPASSED!" << endl;
	else
		cout << "\toperator==(...) FAILED**!" << endl;
	

	//cout << "operator!=const Rectangle& rhs overload test" << endl;
	if (r6 != r9)
		cout << "operator!=(...) \tPASSED!" << endl;
	else
		cout << "\toperator!=(...) Failed**!" << endl;
	
	
	//cout << "operator<=const Rectangle& rhs overload test" << endl;
	if (r4 <= r9)
		cout << "operator<=(...) \tPASSED!" << endl;
	else
		cout << "\toperator<=(...) FAILED**!" << endl;
	
	
	//cout << "operator<const Rectangle& rhs overload test" << endl;
	if (r4 < r9)
		cout << "operator<(...) \t\tPASSED!" << endl;
	else
		cout << "\toperator<(...) FAILED**!" << endl;
	

	if (r9 >= r4)
		cout << "operator>=(...) \tPASSED!" << endl;
	else
		cout << "\toperator>=(...) FAILED**" << endl;
	

	if (r9 > r4)
		cout << "operator>(...) \t\tPASSED!" << endl;
	else
		cout << "\toperator>(...) FAILED**!" << endl ;
	

	cout << "There are 9 Rectangles, are there ? -> " << Rectangle<double>::numberOfRectangles << endl << endl;

	cout << "Job Done!" << endl;
	system("pause");
}