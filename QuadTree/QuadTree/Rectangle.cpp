#include "Rectangle.h"
Rectangle::Rectangle() {

}
Rectangle::Rectangle(double x, double y, double w, double h) {
	this->x = x;
	this->y = y;
	width = w;
	height = h;
}
double Rectangle::getX() {
	return x;
}
double Rectangle::getY() {
	return y;
}
double Rectangle::getWidth() {
	return width;
}
double Rectangle::getHeight() {
	return height;
}
bool Rectangle::contains(Point p) { //x and y refers to the centre of the rectangle
	if (p.getX() < x - width) return false;
	if (p.getX() > x + width) return false;
	if (p.getY() < y - height) return false;
	if (p.getY() > y + height) return false;
	else return true;
}