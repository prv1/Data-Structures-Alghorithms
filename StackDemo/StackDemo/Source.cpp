#include <iostream>
#include "Stack.h"
using namespace std;


int main() {
	
	Stack stack = Stack(7);
	Stack stack2 = Stack(7);
	char text[] = "+*+";
	
	stack.push('A');
	stack.push('+');
	stack.push('B');
	stack.push('*');
	stack.push('C');
	stack.push('+');
	stack.push('D');
	

	cout << stack.peek() << endl;
	stack.pop();

	cout << stack.peek() << endl;
	stack.pop();
	cout << stack.peek() << endl;
	stack.pop();
	cout << stack.peek() << endl;
	stack.pop();
	cout << stack.peek() << endl;
	stack.pop();
	cout << stack.peek() << endl;
	stack.pop();
	//stack.pop();

	cout << stack.peek() << endl;
	stack.pop();
	//stack.pop();

	
	stack2.push('B');
	stack2.push('+');
	stack2.push('E');
	stack2.push('*');
	stack2.push('G');
	stack2.push('+');
	stack2.push('A');


	cout << stack2.peek() << endl;
	stack2.pop();

	cout << stack2.peek() << endl;
	stack2.pop();
	cout << stack2.peek() << endl;
	stack2.pop();
	cout << stack2.peek() << endl;
	stack2.pop();
	cout << stack2.peek() << endl;
	stack2.pop();
	cout << stack2.peek() << endl;
	stack2.pop();
	//stack.pop();

	cout << stack2.peek() << endl;
	stack2.pop();



	system("pause");
	return 0;

}