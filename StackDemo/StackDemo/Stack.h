#ifndef STACK
#define STACK
#include <iostream>
using namespace std;

class Stack {

private:
	int index;
	int emptyStack;
	
	int capacity;
	char* container;
	
public:

	Stack::Stack(int capacity) {
		this->capacity = capacity;
		emptyStack = -1;
		index = emptyStack;
		container = new char[capacity];
	}

	Stack::~Stack() { delete[] container; }

	void Stack::push(char c) {
		container[++index] = c;
	}

	char Stack::pop() {
		return this->container[index--];
	}

	char Stack::peek() {
		return container[index];
	}

	bool Stack::full() {
		return index + 1 == capacity;
	}

	bool Stack::empty() {
		return index == emptyStack;
	}
};


#endif // !STACK

