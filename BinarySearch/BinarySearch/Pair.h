#ifndef _PAIR_H 
#define  _PAIR_H

#include <ostream>
#include <string>


template<typename T, typename U>
class Pair {

public:
	T key;
	U value;

    // Constructor
    Pair(T key, U value) : key(key), value(value){}

	friend ostream& operator<<(ostream& os, Pair<T, U>* const& list) {

		return os << list.key << " : " << list.value;
	}

};

#endif
