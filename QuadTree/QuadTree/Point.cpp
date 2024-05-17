#include "Point.h"
Point::Point() {

}
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
double Point::getX() {
	return x;
}
double Point::getY() {
	return y;
}
std::ostream& operator <<(std::ostream& os, const Point& p) {
	os << "Point X: " << p.x << "Point Y: " << p.y << std::endl;
	return os;
}