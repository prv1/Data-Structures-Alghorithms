// imports header files
#include <fstream>;
#include <iostream>;
using namespace std;



int main() {
	int x;
	// declare string variables
	ifstream readFile; // writes to file
	ofstream writeFile; // reads from file

	// associate the stream variable with physical file
	readFile.open("inputData.txt");
	writeFile.open("outputData.txt");


	// read a value from file
	if (readFile.is_open()){
		while (readFile.good()) {
			readFile >> x;
			writeFile << x << " ";
			cout << x << endl;
		}
	}
	else {

	}
	

	
	//writeFile.write("test");

	// display value
	//cout << x << endl;

	// close the file and release the resource and flush the buffer
	readFile.close();
	writeFile.close();
	system("pause");
	return 0;


}

