#pragma once
#include "Point.h";

class Rectangle
{
public:
	Rectangle();
	Rectangle(double x, double y, double w, double h);
	double getX();
	double getY();
	double getWidth();
	double getHeight();
	bool contains(Point p);
private:
	double x;
	double y;
	double width;
	double height;
};

