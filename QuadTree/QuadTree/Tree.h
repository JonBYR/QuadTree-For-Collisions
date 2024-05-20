#pragma once
#include "Rectangle.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <SDL.h>
class Tree
{
public:
	Tree();
	Tree(Rectangle r, int n, SDL_Renderer* re, Tree* p);
	friend std::ostream& operator <<(std::ostream& os, const Tree& t);
	void insert(Point p);
	void subdivide(Point p);
	~Tree();
private:
	Rectangle boundary;
	double x;
	double y;
	double width;
	double height;
	int capacity;
	int currentPoints;
	bool divided = false;
	SDL_Renderer* rend;
	Tree* northWest;
	Tree* northEast;
	Tree* southWest;
	Tree* southEast;
	Tree* parent;
	std::vector<Point> points;
};


