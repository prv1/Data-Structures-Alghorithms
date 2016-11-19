#include <iostream>
#include "ArrayList.h"
#include "Point2D.h"

using namespace std;
template<class T>
void printArray(ArrayList<T>& al) {
	for (int i = 0; i < al.getCapacity(); ++i)
		cout << "ArrayList[" << i << "] = " << al[i] << endl;
}

void printArray(ArrayList<Point2D*>& al) {
	for (int i = 0; i < al.getCapacity(); ++i)
		if(al[i] != NULL)
			cout << "ArrayList[" << i << "] = " << *(al[i]) << endl;
}

void deletePoint2D(ArrayList<Point2D*>& al) {
	for (int i = 0; i < al.getCapacity(); ++i)
		if (al[i] != NULL)
			delete al[i];
}

int main() {

	ArrayList <int> arrayList(10);

	for (int i = 0; i < 10; ++i)
		arrayList[i] = i;

	printArray(arrayList);

	ArrayList<float> al(10);
	for (int i = 0; i < 10; ++i)
		al[i] *= i * 5.0f;

	printArray(al);

	ArrayList <Point2D*> point2D(8);

	for (int i = 0; i < point2D.getCapacity(); ++i) {
		point2D[i] = new Point2D(i * 2, i + 2);
	}
	
	printArray(point2D);

	deletePoint2D(point2D);


	system("pause");
	return 0;
}