#pragma once
#ifndef POINT_H_
#define POINT_H_
#include <iostream>
using namespace std;
class Point {

public:

	// Constructors
	Point();
	Point(int x, int y);

	// Getters and Setters

	int x() const;
	int y() const;

	void setX(int x);
	void setY(int y);

	// Overloaded Operators
	friend ostream& operator<<(ostream& stream, const Point& p);

private:
	int x_;
	int y_;
};
#endif
