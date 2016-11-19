#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <string>
using namespace std;
/*
* Model a Student and return user defined values
*
* author phillip r viau on 06/03/2016
*/
class Student {
private:
	/*
	* param string name
	* param char pointer grades
	* param float gpa
	*/
	string name;
	char* grades;
	float gpa;

public:
	/*
	* Connstructor for the Student object
	*
	* param string name is the user specified value
	* 
	*/
	Student(string name) {
		setName(name);
		this->grades = new char[4];
	}

	Student(const Student& student) {
		this->setName(student.getName());
		this->setGpa(student.getGpa());
		this->grades = new char[4];
		for (int i = 0; i < sizeof(grades); ++i)
			this->grades[i] = NULL;
	}
	/*
	Removes the Student from memory allowing that memory to be reused
	*/
	~Student() { delete[] grades; }
	/*
	* mutator for the string name
	*
	* param string name is the user supplied value for
	*       the string name
	*/
	void setName(string name) {
		this->name = name;
	}
	/*
	* accessor for the string name
	*
	* returns the string name
	*/
	string getName() const {
		return this->name;
	}
	/*
	* mutator for the float gpa
	*
	* param string name is the user supplied value for
	*       the float gpa
	*/
	void setGpa(float gpa) {
		this->gpa = gpa;
	}
	/*
	* accessor for the float gpa
	*
	* returns the float gpa
	*/
	float getGpa() const {
		return this->gpa;
	}
	/*
	* Returns the variable located in the array from the overloaded int i variable
	* param int i is the user supplied value for the location of the array
	*
	*/
	char& operator[](int i) {
		
		return grades[i];
	}
	/*
	* Compares the invoker object from the rhs values and returns bool to invoker
	*/

	bool operator<(const Student& rhs) {
		return this->getGpa() < rhs.getGpa() ? true : false;
	}
	/*
	* Defines how to insert a Student object into a stream
	* The word friend gives us the ability to have dissimilar types on the left and right of the binary operator
	* has access to all the data fields in the class regarless of access modifiers
	* marks this method as a free function
	*
	* param os stream where we will insert into
	* param is constant reference to the Student Object we intend to insert
	*
	* return os so that we can chain this stream to multiple objects
	*/
	friend ostream& operator<<(ostream& os, const Student& r) {
		//os << "Name: " << r.getName() << endl;// << "GPA: " << r.getGpa() << endl << "Grades: ";
		os << "Name: " << r.getName() << endl;
		os << "GPA: " << r.getGpa() << endl;
		os << "Grades: ";
		for (int i = 0; i < sizeof(grades); ++i)
			os << r.grades[i] << " ";
				
		os << endl;
		return os;
	}

};


#endif // !STUDENT

