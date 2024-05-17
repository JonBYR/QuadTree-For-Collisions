#pragma once
#include "Rectangle.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <cstdlib>
class Tree
{
public:
	Tree(Rectangle r, int n);
	friend std::ostream& operator <<(std::ostream& os, const Tree& t);
	void insert(Point p);
	void subdivide(Point p);
private:
	Rectangle boundary;
	double x;
	double y;
	double width;
	double height;
	int capacity;
	std::vector<Point> points;
	bool divided = false;
};


