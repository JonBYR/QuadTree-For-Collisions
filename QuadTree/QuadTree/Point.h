#pragma once
#include <ostream>
class Point
{
public:
	Point();
	Point(double x, double y);
	double getX();
	double getY();
	friend std::ostream& operator <<(std::ostream& os, const Point& p);
private:
	double x;
	double y;
};

