#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "LinkedList.h"
#include "Pair.h"

using namespace std;

// prototypes
unsigned int hashIt(const string& key);
void dump(LinkedList<Pair<string, string>*>** hashTable, const int hashTableSize);

// ** is pointer to char array of pointers argc is number of args in function and argv is arg type
int main(int argc, char** argv) {

	string input;
	string word;
	char dictionary[255];
	int hashTableIndex;

	// create and initialize the hash table
	const int hashTableSize = 10;
	LinkedList<Pair<string, string>*>* hashTable[hashTableSize];
	
	for (int i = 0; i < hashTableSize; ++i)
		hashTable[i] = new LinkedList<Pair<string, string>*>;
	
	// sanity test
	cout << "After Creation and Initialization" << endl;
	dump(hashTable, hashTableSize);
	cout << endl << endl;

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " data-file" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	// open the file
	ifstream inputFileStream(argv[1]);

	if (!inputFileStream) {
		cerr << "Could not open the text file!" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	
	// read in the data and ad it to the hash table
	while (inputFileStream >> word) {
		inputFileStream.getline(dictionary, 255);
		hashTableIndex = (hashIt(word) % hashTableSize);
		hashTable[hashTableIndex]->addToHead(new Pair<string,string>(word, dictionary));
		
	}
	

	// sanity test
	cout << "After populating the list with 10 names" << endl;
	dump(hashTable, hashTableSize);
	
	cout << endl << endl;
	system("pause");

	// close the file
	inputFileStream.close();
	
}



/*
 * calculates a hash from a string
 * char1 * 6151 + char2 * 6151 ... +charN * 6151
 */
unsigned int hashIt(const string& key) {

	unsigned int index = 0;

	for (unsigned int i = 0; i < key.size(); ++i)
		index += key[i] * 6151;

	return index;
}



/**
* sanity test, displays the table as it phyically exits
*/
void dump(LinkedList<Pair<string, string>*>** hashTable, const int hashTableSize) {

	for (int i = 0; i < hashTableSize; ++i)
		if ( hashTable[i]->isEmpty() )
			cout << "hashTable[" << i << "] -> *** IS EMPTY ***" << endl;
		else {
			cout << "hashTable[" << i << "] -> ";
			hashTable[i]->dump();
			cout << endl;
		}
	

}