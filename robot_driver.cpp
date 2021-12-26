#include "point.h"
#include "robot.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Input coordinates of starting position, ending position, and maximum consecutive moves in one direction
int main(int argc, char* argv[]) {
	
	if (argc < 6) {
		cout << "You didn't enter the correct amount of integers into the command line!" << endl;
		exit(1);
	}

	int x1 = atoi(argv[1]);
	int y1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y2 = atoi(argv[4]);
	int distance = atoi(argv[5]);
	
	Robot rob(x1, y1, x2, y2, distance);
	cout << rob.CountPaths(rob.start(), rob.treasure(), "") << endl;

	/* Some of my basic tests
	Robot r1(1, 2, 3, 5, 2);
	Robot r2(5, 3, 3, 1, 2);
	Robot r3(5, 7, 7, 5, 2);
	Robot r4(4, 2, 2, 4, 2);
	cout << "Start: " << r1.start().x() << ", " << r1.start().y() << endl;
	cout << "Treasure: " << r1.treasure().x() << ", " << r1.treasure().y() << endl;
	string answer = "";
	cout << r1.CountPaths(r1.start(), r1.treasure(), answer) << endl;
	cout << r2.CountPaths(r2.start(), r2.treasure(), answer) << endl;
    cout << r3.CountPaths(r3.start(), r3.treasure(), answer) << endl;
	cout << r4.CountPaths(r4.start(), r4.treasure(), answer) << endl;*/
}