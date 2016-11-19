#include <iostream>
#include <queue>
using namespace std;



int main() {
	queue<int> myQueue;
	int myInt;




	int queue[7];
	int qSize = 7;
	int in = 0, out = 0;
	int input = 0;

	for (int i = 0; i < qSize; ++i)
		queue[i] = NULL;



	while ((input >= 0) && (input <= 9)) {
		cout << "Enter a number: ";
		cin >> input;
		if (in + 1 > qSize) 
			in = -1;
		if (out + 1 > qSize)
			out = 0;
		if (queue[in] == NULL) {
			queue[in] = input;
			(in + 1 < qSize) ? in++ :  in = 0;
		}
		else if (queue[in] != NULL && in + 1 == out) {
			(out + 1 < qSize)? out++ : out = 0;
			queue[in] = input;
			(in + 1 < qSize) ? in++ : in = 0;
		}
		else if (queue[in] != NULL && in + 1 != out) {
			queue[in] = input;
			(in + 1 < qSize) ? in++ : in = 0;
		}

		cout << "In: " << in << " Out: " << out << endl;
		for (int i = 0; i < qSize; ++i)
			cout << queue[i] << " ";

		cout << endl;

	}


}