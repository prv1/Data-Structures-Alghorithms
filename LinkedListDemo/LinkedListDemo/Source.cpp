#include "LinkedList.h"
#include "Rectangle.h"

int Rectangle::numberOfRectangles = 0;

int main() {

	LinkedList<Rectangle> list2;

	for (int i = 0; i < 5; ++i)
		list2.addToTail(Rectangle(i, i*i));

	list2.dump();
	system("pause");


















	LinkedList<int> list;
	/*list.addToHead(3);
	list.addToHead(10);*/

	for (int i = 10; i < 50; i += 10)
		list.addToHead(i);

	list.dump();

	system("pause");

	int targetedItem = 20;
	LinkedList<int>::Link* pWorking = list.searchLink(targetedItem);
	if (pWorking == NULL)
		cout << "The value " << targetedItem << " does not exist." << endl;
	else
		cout << "The value " << targetedItem << " exists at " << pWorking << endl;

	/*list.insertAt(1, 15);

	list.dump();

	system("pause");

	list.addToHead(500);

	list.dump();*/

	system("pause");




	//LinkedList *list;
	//LinkedList list;
	/*struct Node *newHead;
	struct Node *head = new Node;
	
	initNode(head, 10);
	//addNode(head, 10);
	display(head);

	addNode(head, 20);
	display(head);

	addNode(head, 30);
	display(head);

	addNode(head, 35);
	display(head);

	addNode(head, 40);
	display(head);

	insertFront(&head, 5);
	display(head);

	int numDel = 5;
	Node *ptrDelete = searchNode(head, numDel);
	if (deleteNode(&head, ptrDelete))
		cout << "Node " << numDel << " deleted!\n";
	display(head);

	cout << "The list is reversed\n";
	reverse(&head);
	display(head);

	cout << "The list is copied\n";
	copyLinkedList(head, &newHead);
	display(newHead);

	cout << "Comparing the two lists...\n";
	cout << "Are the two lists same?\n";
	if (compareLinkedList(head, newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
	cout << endl;

	numDel = 35;
	ptrDelete = searchNode(newHead, numDel);
	if (deleteNode(&newHead, ptrDelete)) {
		cout << "Node " << numDel << " deleted!\n";
		cout << "The new list after the delete is\n";
		display(newHead);
	}
	cout << "Comparing the two lists again...\n";
	cout << "Are the two lists same?\n";
	if (compareLinkedList(head, newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";

	cout << endl;
	cout << "Deleting the copied list\n";
	deleteLinkedList(&newHead);
	display(newHead);*/


	system("pause");
	return 0;




	/*LinkedList list;

	for (int i = 0; i < 50; i += 10) {
		list.addToHead(i);
	}

	list.dump();

	system("pause");
	return 0;*/
}