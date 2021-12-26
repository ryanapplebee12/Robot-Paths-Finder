#include "robot.h"
#include <iostream>
using namespace std;

// Constructors
Robot::Robot() {
	set_start(0,0);
	set_treasure(0,0);
	set_max_distance(2);
}

Robot::Robot(int x1, int y1, int x2, int y2, int max_distance) {
	set_start(x1, y1);
	set_current(x1, y1);
	set_treasure(x2, y2);
	set_max_distance(max_distance);
}

// Getters and Setters 

Point Robot::start() const {
	return start_;
}

Point Robot::treasure() const {
	return treasure_;
}

int Robot::max_distance() const {
	return max_distance_;
}

Point Robot::current() const {
	return current_;
}

void Robot::set_start(int x, int y) {
	start_ = Point(x, y);
}

void Robot::set_current(int x, int y) {
	current_ = Point(x, y);
}

void Robot::set_treasure(int x, int y) {
	treasure_ = Point(x, y);
}

void Robot::set_max_distance(int distance) {
	max_distance_ = distance;
}


//Recursive Function and Helpers

int Robot::CountPaths(Point start, Point treasure, string path) {
	// If either the x coord, or y coord is the same, there is only one path left to the treasure
	if ((start.x() == treasure.x()) || (start.y() == treasure.y())) {
		// Builds the string for the remaining path 
		path = FinishPath(start.x(), start.y(), treasure.x(), treasure.y(), path);
		// Verifies if the path adheres to the max distance rule
		int result = VerifyPath(path, this->max_distance());
		if (result == 1) {
			cout << path << endl;
			return 1;
		}
		else {
			return 0;
		}
	}
	int answer = 0;
	// If the treasure is east of the treasure, check if it's north or south
	if (start.x() < treasure.x()) {
		if (start.y() < treasure.y()) {
			// Updates the path by adding the letter of the direction the robot moves
			set_current(start.x() + 1, start.y());
			answer = CountPaths(current(), treasure, path + "E");
			set_current(start.x(), start.y() + 1);
			return answer + CountPaths(current(), treasure, path + "N");
		}
		else {
			set_current(start.x() + 1, start.y());
			answer = CountPaths(current(), treasure, path + "E");
			set_current(start.x(), start.y() - 1);
			return answer + CountPaths(current(), treasure, path + "S");
		}
	}

	if (start.y() < treasure.y()) {
		set_current(start.x() - 1, start.y());
		answer = CountPaths(current(), treasure, path + "W");
		set_current(start.x(), start.y() + 1);
		return answer + CountPaths(current(), treasure, path + "N");
	}
	else {
		set_current(start.x() - 1, start.y());
		answer = CountPaths(current(), treasure, path + "W"); 
		set_current(start.x(), start.y() - 1);
		return answer + CountPaths(current(), treasure, path + "S");
	}

}

// If the robot moves has either the x or y coordinate correct, this function is called
// This function will 
string Robot:: FinishPath(int Xr, int Yr, int Xt, int Yt, string path) {
	if (Xr==Xt) {
		while (Yr < Yt) {
			Yr++;
			path += "N";
		}
		while (Yr > Yt) {
			Yr--;
			path += "S";
		}
		return path;
	}

	while (Xr < Xt) {
		Xr++;
		path += "E";
	}
	
	while (Xr > Xt) {
		Xr--;
		path += "W";
	}
		return path;
}

// Makes sure the path doesn't go in the same direction more times than it's supposed to
// If the path doesn't fulfill the max_distance rule, this function will return 0, which tells the recursive function that the path is invalid
int Robot::VerifyPath(string path, int distance) {
	char current_letter = path[0];
	int letter_count = 0;
	char temp = path[0];
	for (int i = 0; i < path.length(); i++) {
		temp = path[i];

		if (current_letter == temp) {
			letter_count++;
		}
		else {
			letter_count = 1;
			current_letter = temp;
		}

		if (letter_count > distance) {
			return 0;
		}
	}
	return 1;
}



