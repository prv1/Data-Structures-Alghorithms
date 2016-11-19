#include <iostream>
#include "Stack.h"
using namespace std;

int OperandPrecedence(char operand) {
	switch (operand) {
	case '+':
	case '-':
		return 2;
		break;
	case '*':
	case '/':
		return 3;
		break;
	default:
		return 0;

	}
	return 0;
}

int main() {

	//Stack stack = Stack(5);
	
	
	char text[] = "A+B*C+D/E";
	int size = sizeof(text);
	
	
	Stack charContainer = Stack(size);
	Stack postFix = Stack(size);
	Stack stack = Stack(size);
	bool isDone = false;
	bool isOperand = false;
	int operandPrecedence = 0;
	int stackPrecedence = 0;
	int currentPrecedence = 0;


	for (int i = 0; i < size; ++i) {
		//charArray[i] = text[i];
		charContainer.push(text[i]);
		//cout << charContainer.peek();
	}
	//cout << endl;


	//for (int i = 0; i < sizeof(text); ++i) {
	//	*(charContainer[i]) = NULL;
	//	*(charOutput[i]) = NULL;
	//}

	
	while (!isDone) {

		operandPrecedence = OperandPrecedence(charContainer.peek());
		isOperand = (operandPrecedence == 2 || operandPrecedence == 3) ? true : false;

		if (isOperand) {


			if (operandPrecedence > stackPrecedence) {
				cout << "Add to stack " << stack.peek() << endl;
				stack.push(charContainer.peek());
				stackPrecedence = operandPrecedence;
				cout << "Index " << stack.returnIndex() << endl;

			}
			else if (operandPrecedence <= stackPrecedence) {
				cout << "Add to postfix " << stack.peek() << endl;
				postFix.push(stack.peek()); // peek stack and add to output 
				stackPrecedence = operandPrecedence;
				cout << "Index before pop " << stack.returnIndex() << endl;
				stack.pop();
				cout << "Index after pop " << stack.returnIndex() << endl;
			}
			else {
				cout << "Catch all should not fire" << endl;
			}
		}
		else if(!isOperand) {
			(!charContainer.empty()) ? postFix.push(charContainer.peek()) : "";
			operandPrecedence = 0;
		}
		
		charContainer.pop();
		if (charContainer.empty()) {
			isDone = true;
			for (int i = 0; i < size; ++i) {
				cout << postFix.peek();
				postFix.pop();
			}
		}
		//charLocation++;
		
	}

	//for (int i = 0; i < sizeof(text); ++i) {
	//	cout << charOutput[i];
	//}


	system("pause");
	return 0;

}



