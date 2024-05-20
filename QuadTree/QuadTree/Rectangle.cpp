#include "Rectangle.h"
Rectangle::Rectangle() {

}
void Rectangle::Init(double x, double y, double w, double h) {
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
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
	if (p.getX() <= x) return false; 
	if (p.getX() >= x + width) return false; //if point exceeds the width of the rectangle
	if (p.getY() <= y) return false;
	if (p.getY() >= y + height) return false; //if point exceeds the height of the rectangle
	else return true;
}
void Rectangle::renderRectangle(SDL_Renderer* rend) {
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	SDL_RenderDrawRect(rend, &rect);
	
}