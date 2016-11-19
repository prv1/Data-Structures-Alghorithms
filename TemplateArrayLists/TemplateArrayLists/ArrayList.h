#include <iostream>
#include <stdexcept>
#include <stdlib.h>



#ifndef ARRAY_LIST
#define ARRAY_LIST

template<class T>
class ArrayList {

private:
	T* container;
	int capacity;


public:
	/*
	Constructor making and arrayList of 'desiredCapacity' number of slots

	param desiredCapacity is the number of slots for the dynamically created container
	*/

	ArrayList(int desiredCapacity){
		container = new T[desiredCapacity];
		capacity = desiredCapacity;

		for (int i = 0; i < desiredCapacity; ++i)
			this->container = NULL;
	}

	/* 
	* Deep Copy constructor
	*
	* param arrayList is a reference to the original ArrayList object
	*/
	ArrayList(ArrayList<T>& arrayList) {
		this->capacity = arrayList.getCapacity();
		this->container = new T[arrayList.getCapacity()];

		for (int i = 0; i < arrayList.getCapacity(); ++i)
			this->container[i] = arrayList[i];

	}

	/* Destructor, removes this object and its associtive dynamically 
	* created container from memory
	*/
	~ArrayList() { delete[] container; }

	/* 
		The ref allows the [] to appear on either side of the assignment statement
	*/
	T& operator[](int i) {
		if (i < capacity) {
			return container[i];
		}

		std::cout << "Index out of bounds!" << std::endl;
		return container[0];
	}
	/* 
		
	*/
	int getCapacity() const { return this->capacity; }


};

#endif // !ARRAY_LIST

