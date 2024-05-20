#pragma once
#include <ostream>
#include <SDL.h>
class Point
{
public:
	Point();
	Point(double x, double y);
	double getX();
	double getY();
	friend std::ostream& operator <<(std::ostream& os, const Point& p);
	void drawPoint(SDL_Renderer* rend);
private:
	double x;
	double y;
};

