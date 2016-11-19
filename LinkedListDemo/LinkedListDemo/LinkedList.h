//
//#ifndef LINKED_LIST
//#define LINKED_LIST
//
//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//};
//
////class LinkedList {
//
//
//
//	// only for the 1st Node
//	void initNode(struct Node *head, int n) {
//		head->data = n;
//		head->next = NULL;
//	}
//
//	// apending
//	void addNode(struct Node *head, int n) {
//		//if (head->next != NULL) { // Initializes head
//		//	head->data = n;
//		//	head->next = NULL;
//		//}
//		Node *newNode = new Node;
//		newNode->data = n;
//		newNode->next = NULL;
//
//		Node *cur = head;
//		while (cur) {
//			if (cur->next == NULL) {
//				cur->next = newNode;
//				return;
//			}
//			cur = cur->next;
//		}
//	}
//
//	void insertFront(struct Node **head, int n) {
//		Node *newNode = new Node;
//		newNode->data = n;
//		newNode->next = *head;
//		*head = newNode;
//	}
//
//	struct Node *searchNode(struct Node *head, int n) {
//		Node *cur = head;
//		while (cur) {
//			if (cur->data == n) return cur;
//			cur = cur->next;
//		}
//		cout << "No Node " << n << " in list.\n";
//	}
//
//	bool deleteNode(struct Node **head, Node *ptrDel) {
//		Node *cur = *head;
//		if (ptrDel == *head) {
//			*head = cur->next;
//			delete ptrDel;
//			return true;
//		}
//
//		while (cur) {
//			if (cur->next == ptrDel) {
//				cur->next = ptrDel->next;
//				delete ptrDel;
//				return true;
//			}
//			cur = cur->next;
//		}
//		return false;
//	}
//
//	/* reverse the list */
//	
//	struct Node* reverse(struct Node** head)
//	{
//		Node *parent = *head;
//		Node *me = parent->next;
//		Node *child = me->next;
//
//		/* make parent as tail */
//		parent->next = NULL;
//		while (child) {
//			me->next = parent;
//			parent = me;
//			me = child;
//			child = child->next;
//		}
//		me->next = parent;
//		*head = me;
//		return *head;
//	}
//
//	/* Creating a copy of a linked list */
//	void copyLinkedList(struct Node *node, struct Node **pNew)
//	{
//		if (node != NULL) {
//			*pNew = new Node;
//			(*pNew)->data = node->data;
//			(*pNew)->next = NULL;
//			copyLinkedList(node->next, &((*pNew)->next));
//		}
//	}
//
//	/* Compare two linked list */
//	/* return value: same(1), different(0) */
//	bool compareLinkedList(struct Node *node1, struct Node *node2)
//	{
//		static bool flag;
//
//		/* both lists are NULL */
//		if (node1 == NULL && node2 == NULL) {
//			flag = true;
//		}
//		else {
//			if (node1 == NULL || node2 == NULL)
//				flag = false;
//			else if (node1->data != node2->data)
//				flag = false;
//			else
//				compareLinkedList(node1->next, node2->next);
//		}
//
//		return flag;
//	}
//
//	void deleteLinkedList(struct Node **node)
//	{
//		struct Node *tmpNode;
//		while (*node) {
//			tmpNode = *node;
//			*node = tmpNode->next;
//			delete tmpNode;
//		}
//	}
//
//	void display(struct Node *head) {
//		Node *list = head;
//		while (list) {
//			cout << list->data << " ";
//			list = list->next;
//		}
//		cout << endl;
//		cout << endl;
//	}
//
//
//
//
//
//
////};
//
//
//#endif // !LINKED_LIST*/


#include <iostream>

using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
class LinkedList {

public:

/*
* Data container A.K.A the Link
* It has 2 instance variables
* 1) data field
* 2) pointer to the next link
*/
	struct Link {
		T data;
		Link* pNext;

		Link(T value, Link* pointer) {
			data = value;
			pNext = pointer;
		}
	};

private:
	Link* head;
	Link* tail;

public:

	/*
	* Creates a LinkedList. Initializes both head and tail
	* pointers to NULL. This signifies that the list is
	* empty
	*/
	LinkedList() {
		head = tail = NULL;
	}

	/*
	* If the list is empty, create a new Link and assign
	* its address to both head and tail, otherwise tail from
	* the previous container is set to point to the address of
	* the new container and the tail of the new container is set
	* to point to the same address since it is a Null
	*
	* param value is the user specified value to be passed to Link
	*/
	bool addToTail(T value) {
		if (isEmpty())
			tail = head = new Link(value, NULL); // pass a null for convenience, to know we are at the end of the link
		else
			tail = tail->pNext = new Link(value, NULL);
		return true;
	}

	/*
	* If the list is empty, create a new link and assign
	* its address to both head and tail, otherwise head is
	* set to point to the address of the new container and
	* the tail of the new container is set to point to the
	* address of the next container
	*
	* param value is the user specified value to be passed to link
	*/
	bool addToHead(T value) {
		if (isEmpty())
			tail = head = new Link(value, NULL);
		else
			head = new Link(value, head);
		return true;
	}

	/*
	* If the designated position is 1, add the node to head
	* If the pointer is pointing to a NULL, add the node to the tail
	* Otherwise, whatever the designated position, add the node there
	*
	* param position is the user designated position of where the node
	*		should be added
	* param value is the user specified value to be passed to link
	*/
	bool insertAt(int position, T value) {
		Link* pWorking = head;

		if (position <= 1) {
			addToHead(value);
			return true;
		}
		else if (pWorking == NULL) {
			addToTail(value);
			return true;
		}
		else {
			// move the working pointer to the link just ahead of the desired position
			for (int i = 1; i < (position - 1); ++i)
				pWorking = pWorking->pNext;

			pWorking->pNext = new Link(value, pWorking->pNext);

			return true;
		}
	}

	//	struct Node *searchNode(struct Node *head, int n) {
	//		Node *cur = head;
	//		while (cur) {
	//			if (cur->data == n) return cur;
	//			cur = cur->next;
	//		}
	//		cout << "No Node " << n << " in list.\n";
	//	}
	//
	//	bool deleteNode(struct Node **head, Node *ptrDel) {
	//		Node *cur = *head;
	//		if (ptrDel == *head) {
	//			*head = cur->next;
	//			delete ptrDel;
	//			return true;
	//		}
	//
	//		while (cur) {
	//			if (cur->next == ptrDel) {
	//				cur->next = ptrDel->next;
	//				delete ptrDel;
	//				return true;
	//			}
	//			cur = cur->next;
	//		}
	//		return false;
	//	}

	bool deleteHead() {

		if (isEmpty())
			retun false;

		Link* pWorking = head;
		head = pWorking->pNext;
		delete pWorking;

		if (head == NULL)
			tail = NULL;

		return true;
	}

	bool deleteTail() {

		if (isEmpty())
			return false;

		Link* pWorking = head;

		while pWorking->pNext != tail
			pWorking = pWorking->pNext;

		pWorking->pNext = NULL;
		delete tail;
		tail = pWorking;


		return true;
	}

	struct Link *searchLink(T location) {
		Link *pWorking = head;
		while (pWorking != NULL) {
			if (pWorking->data == location) return pWorking;
			pWorking = pWorking->pNext;

		}
		cout << "No Node " << location << " in list.\n";
	}




	void dump() {
		Link* pWorking = head;

		while (pWorking != NULL) {
			cout << pWorking << "->" << pWorking->data << " " << endl;
			pWorking = pWorking->pNext;
		}
		cout << endl;

	}


	/*
	* Determines whether the LinkedList is empty or not
	*
	* return true if it is empty else false
	*/
	bool isEmpty() { return head == NULL && tail == NULL ? true : false; }


};

#endif

//#endif // !LINKED_LIST*/
