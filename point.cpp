#include "point.h"
#include <iostream>
using namespace std;

// Constructors
Point::Point() {
	setX(0);
	setY(0);
}

Point::Point(int x, int y) {
	setX(x);
	setY(y);
}

// Getters and Setters
int Point::x() const {
	return x_;
}

int Point::y() const {
	return y_;
}

void Point::setX(int x) {
	x_ = x;
}

void Point::setY(int y) {
	y_ = y;
}

// Overloaded Operators
ostream& operator<<(ostream& stream, const Point& p) {
	stream << p.x() << ", " << p.y();
	return stream;
}