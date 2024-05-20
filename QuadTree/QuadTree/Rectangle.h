#pragma once
#include "Point.h"
#include <SDL.h>
class Rectangle
{
public:
	Rectangle();
	Rectangle(double x, double y, double w, double h);
	void Init(double x, double y, double w, double h);
	double getX();
	double getY();
	double getWidth();
	double getHeight();
	bool contains(Point p);
	void renderRectangle(SDL_Renderer* rend);
private:
	double x;
	double y;
	double width;
	double height;
	SDL_Rect rect;
};

