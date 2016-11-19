#include <stdlib.h>
#include <iostream>

using namespace std;

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

template <class T>
class LinkedList {

public:

	/* Data container. It has 2 fields:
	 *		1) data to be stored in the LinkedList container
	 *		2) pointer to the next link if it exists else NULL
	 */
	struct Link {
		T data;
		Link* pNext;

		Link(T value, Link* pointer)  {
			data = value;
			pNext = pointer;
		}
	};

private:

	Link* head;
	Link* tail;

public:

	/*
	 * constructor, Crates a LinkedList container and 
	 * initializes the head and tail pointers to NULL
	 * signifying an empty list
	 */
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	bool addToTail(T value) {
	// is list empty
		if (isEmpty()) {
			//	1) create a new link
			//  2) assign the head and tail pointer to that Links address
			head = new Link(value, NULL);
			tail = head;
		}
		else
			tail = tail->pNext = new Link(value, NULL);
		//  1) crate a new link
		//  2) assign the last links pointer to that new links address
		//  3) assign the tail to the new links address also
		// create a new link
		// set 

		return true;
	}
	/**
	 * Determins if the LinkedList is empty or not
	 *
	 * returns true if it is empty else false
	 */
	bool isEmpty() { return (head == NULL && tail == NULL) ? true : false; }

	bool addToHead(T value) {

		if(isEmpty()) {
			head = tail = new Link( value, NULL);
			
		}
		else {
			head = new Link(value, head);
		}
		return true;
	}

	bool insertAt(int position, T value) {

		// are you inserting befor the 1st position?
		if (position <= 1) {
			addToHead(value);
			return true;
		}

		Link* pWorking = head;

		// move the working pointer to the link just ahead of the desired position
		for (int i = 1; i < (position - 1); ++i) {
			pWorking = pWorking->pNext;

			// have you run out of links befopre arriving at the desired position?
			if (pWorking == NULL) {
				addToTail(value);
				return true;
			}
		}

		// ok, add it to the desired position
		pWorking->pNext = new Link(value, pWorking->pNext);
		return true;
	}

	bool deleteHead() {

		if (isEmpty())
			return false;

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

		while (pWorking->pNext != tail)
			pWorking = pWorking->pNext;

		pWorking->pNext = NULL;
		delete tail;
		tail = pWorking;
		
		return true;
	}

	void dump() {

		// create a tempory pointer to iterate through the list
		Link* pWorking = head;

		while (pWorking != NULL) {
			cout << *pWorking->data;
			
			// advance the pointer to the next link
			pWorking = pWorking->pNext;
		}
	}

	Link* search(T value) {
		
		Link* pWorking = head;

		while (pWorking != NULL) {
			if (pWorking->data == value)
				return pWorking;

			pWorking = pWorking->pNext;
		}
		return NULL;
	}




	/*
	 * Extends the insertion stream operator to inclued LinkedLists
	 * Note: each data value is seperated by commas
	 *
	 * param os is the intended output stream
	 * param list is the LinkedList we intend to display
	 *
	 * returns a reference to the stream enabling chaining of items to 
	 *         insert into the output stream
	 */
	friend ostream& operator<<(ostream& os,  LinkedList const& list) {

		LinkedList::Link* pWorking = list.head;
		
		// test for an empty list
		if(pWorking != NULL)
			os << (*pWorking).data;

		while (pWorking != NULL) {
			os << ", " << (*pWorking).data;
			(*pWorking) = (*pWorking).pNext;
		}

		return os;
	}



};

#endif