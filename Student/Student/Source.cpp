#include "Student.h"

using namespace std;

void main() {

	Student s1("Shamus Maldune");
	s1.setGpa(3.0f);
	s1[0] = 'A';
	s1[1] = 'B';
	s1[2] = 'A';
	s1[3] = 'C';
	cout << s1 << endl << endl;

	Student s2("Nummy Camel");
	s2.setGpa(3.0f);
	s2[0] = 'B';
	s2[1] = 'C';
	s2[2] = 'B';
	s2[3] = 'B';
	cout << s2 << endl << endl;

	Student s3(s1);
	s3.setName("Green Teeth");
	s3.setGpa(1.9F);
	s3[0] = 'a';
	s3[1] = 'b';
	s3[2] = 'c';
	s3[3] = 'd';
	cout << s3 << endl << endl;


	if (s1 < s2)
		cout << s2.getName() << " has the higher GPA" << endl;
	else
		cout << s1.getName() << " has the higher GPA" << endl;
		

	cout << "Job Done!" << endl << endl;
	system("pause");
}



/*
This is what your output should liik like

Name: Shamus Maldune
GPA: 3
Grades: A, B, A, C,

Name: Nummy Camel
GPA: 3
Grades: B, C, B, B,

Name: Green Teeth
GPA: 1.9
Grades: a, b, c, d,

Shamus Maldune has the higher GPA
Job Done!

Press any key to continue . . .


*/