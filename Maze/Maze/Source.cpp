#include <iostream>
#include <fstream>
#include <string>
#include "Point2D.h"

using namespace std;
enum Direction { RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3 };
// Prototypes

template<typename T, size_t mazeX, size_t mazeY>
void printMaze(T (&maze)[mazeX][mazeY]) {
	system("cls");
	for (int i = 0; i < mazeX; ++i) {
		for (int j = 0; j < mazeY; ++j) {
			cout << maze[i][j];
		}
		cout << endl;
	}
	

}

template<typename T, size_t mazeX, size_t mazeY>
Point2D& checkDirection(Direction &currentDirection, T(&maze)[mazeX][mazeY], Point2D& playerLocation) {
	bool isAble = false;
	Direction originalDirection = currentDirection;
	int checkedCounter = 0;
	const int check_x[] = { 1, 0, -1, 0 }, check_y[] = { 0, 1, 0, -1 };
	int direction = 0;
	while (!isAble) {
		switch (currentDirection) {
		case RIGHT:
			direction = 0;
			isAble = traverseMaze(maze, playerLocation, check_x[currentDirection], check_y[currentDirection]);
			cout << "isAble: " << isAble << endl;
			if (!isAble && checkedCounter == 0) {
				checkedCounter++;
				currentDirection = DOWN; // look opposite direction 
			}
			else if (!isAble && checkedCounter == 1) {
				checkedCounter++;
				currentDirection = LEFT;
			}
			else if (!isAble && checkedCounter >= 2) {
				currentDirection = UP;
				originalDirection = DOWN;

				checkedCounter = 0;
			}
			if (isAble) {
				checkedCounter = 0;
				originalDirection = currentDirection;

			}

			cout << "Counter: " << checkedCounter << endl;
			break;
		case DOWN:
			direction = 1;
			isAble = traverseMaze(maze, playerLocation, check_x[direction], check_y[direction]);
			if (!isAble && checkedCounter == 0) {
				checkedCounter++;
				currentDirection = LEFT;
			}
			else if (!isAble && checkedCounter == 1) {
				checkedCounter++;
				currentDirection = UP;
			}
			else if (!isAble && checkedCounter >= 2) {
				currentDirection = RIGHT;
				originalDirection = LEFT;

				checkedCounter = 0;
			}
			if (isAble) {
				checkedCounter = 0;
				originalDirection = currentDirection;
			}

			break;
		case LEFT:
			direction = 2;
			if (!isAble && checkedCounter == 0) {
				checkedCounter++;
				currentDirection = UP;
			}
			else if (!isAble && checkedCounter == 1) {
				checkedCounter++;
				currentDirection = RIGHT;
			}
			else if (!isAble && checkedCounter >= 2) {
				currentDirection = DOWN;
				originalDirection = UP;

				checkedCounter = 0;
			}
			if (isAble) {
				checkedCounter = 0;
				originalDirection = currentDirection;
			}
			//currentDirection = UP;
			//cout << "LEFT" << endl;
			break;
		case UP:
			direction = 3;
			if (!isAble && checkedCounter == 0) {
				checkedCounter++;
				currentDirection = RIGHT;
			}
			else if (!isAble && checkedCounter == 1) {
				checkedCounter++;
				currentDirection = DOWN;
			}
			else if (!isAble && checkedCounter >= 2) {
				currentDirection = LEFT;
				originalDirection = RIGHT;

				checkedCounter = 0;
			}
			if (isAble) {
				checkedCounter = 0;
				originalDirection = currentDirection;
			}


			break;
		default:
			cout << "";
		}
		cout << "isAble: " << isAble << endl;
		cout << "checkedCounter: " << checkedCounter << endl;
		cout << "Current Direction: " << currentDirection << endl;
		cout << "Original Direction: " << originalDirection << endl;
		system("pause");
	}

	checkedCounter = 0;
	originalDirection = currentDirection;
	return playerLocation;
}

//void traverseMaze()
template<typename T, size_t mazeX, size_t mazeY>
bool traverseMaze(T (&maze)[mazeX][mazeY], Point2D& playerLocation, int newX, int newY) {
	//bool isEnd = false;
	cout << "Checking..." << endl;
	
	if ((maze[playerLocation.getX() + newX][playerLocation.getY() + newY] != 'X' || maze[playerLocation.getX() + newX][playerLocation.getY() + newY] != 'x') && maze[playerLocation.getX() + newX][playerLocation.getY() + newY] == '.') {
		maze[playerLocation.getX()][playerLocation.getY()] = '+';
		newX = playerLocation.getX() + newX;
		newY = playerLocation.getY() + newY;
		maze[newX][newY] = '@';
		playerLocation.setX(newX);
		playerLocation.setY(newY);
		printMaze(maze); // prints entire maze
		cout << " true 2" << endl;
		return true;
	}
	else if (maze[playerLocation.getX() + newX][playerLocation.getY() + newY] == 'X' || maze[playerLocation.getX() + newX][playerLocation.getY() + newY] == 'x') {
		cout << "Wall is here" << endl;
		return false;
	}
	else if (maze[playerLocation.getX() + newX][playerLocation.getY() + newY] == '+') {
		maze[playerLocation.getX()][playerLocation.getY()] = 'x';
		newX = playerLocation.getX() + newX;
		newY = playerLocation.getY() + newY;
		maze[newX][newY] = '@';
		playerLocation.setX(newX);
		playerLocation.setY(newY);
		printMaze(maze); // prints entire maze
		cout << "true 3" << endl;
		return true;
	}else if (maze[playerLocation.getX() + newX][playerLocation.getY() + newY] == 'E') {
		newX = playerLocation.getX() + newX;
		newY = playerLocation.getY() + newY;
		maze[newX][newY] = '@';
		playerLocation.setX(newX);
		playerLocation.setY(newY);
		printMaze(maze); // prints entire maze
		cout << "true 1" << endl;
		return true;
	}
	maze[playerLocation.getX()][playerLocation.getY()] = '@';
	printMaze(maze); // prints entire maze
	system("pause");
	cout << "false" << endl;
	return false;
}



int main(int argc, char** argv) {
	
	Point2D start(0, 0);
	Point2D current(0, 0);
	Point2D end;
	Direction currentDirection;// = RIGHT;
	

	const int mazeX = 7, mazeY = 7;
	string line;
	char maze[mazeX][mazeY];
	
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

	for (int i = 0; i < mazeX; ++i) {
		inputFileStream >> line;
		for (int j = 0; j < mazeY; ++j) {
			maze[i][j] = line.at(j);
			if (line.at(j) == 'S')
				start(i, j);
			if (line.at(j) == 'E')
				end(i, j);
			if (start.getY() == j)
				current = start;

		}
	}


	line = "";

	printMaze(maze);

	cout << endl << start << " " << end << " " << current << endl;
	currentDirection = RIGHT;
	if (currentDirection != RIGHT || currentDirection != LEFT || currentDirection != UP || currentDirection != DOWN)
		currentDirection = RIGHT;

	while (current != end) {

		//while(current != end) {
			//cout << "Counting: " << i << endl;
			current = checkDirection(currentDirection, maze, current);
			
			cout << current << endl; // display current location of player

		//}

		

		//current = end;
	}

	cout << endl << start << " " << end << " " << current << endl;
	cout << "You WIN!!!!!";
	inputFileStream.close();
	system("pause");
	return 0;
}


