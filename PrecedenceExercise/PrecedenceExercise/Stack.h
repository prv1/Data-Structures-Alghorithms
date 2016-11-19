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
		index = 0;
		container = new char[capacity];
		for (int i = 0; i < capacity; ++i)
			container[i] = NULL;
	}

	Stack::~Stack() { delete[] container; }

	void Stack::push(char c) {
		this->container[++index] = c;
	}

	void Stack::pop() {
		this->container[index--] = NULL;
		//this->index--;
	}

	char Stack::peek() {
		//return this->container[index];
		return container[index];
	}

	bool Stack::full() {
		return index + 1 == capacity;
	}

	bool Stack::empty() {
		return (index < 0);
	}

	int returnIndex() {
		return index;
	}

};


#endif // !STACK
