#pragma once
#ifndef ROBOT_H_
#define ROBOT_H_
#include "point.h"
#include <iostream>
using namespace std;

class Robot {

public: 

	// Constructors
	Robot();
	Robot(int x1, int y1, int x2, int y2, int max_distance);

	// Getters and Setters

	Point start() const;
	Point treasure() const;
	int max_distance() const;
	Point current() const;

	void set_start(int x, int y);
	void set_treasure(int x, int y);
	void set_max_distance(int distance);
	void set_current(int x, int y);
	//void set_path(string path);

	// Direction Commands 
	string FinishPath(int Xr, int Yr, int Xt, int Yt, string path);
	int CountPaths(Point start, Point treasure, string path);
	int VerifyPath(string path, int distance);

private:
	Point start_;
	Point current_;
	Point treasure_;
	int max_distance_;
	//string path_;

};
#endif