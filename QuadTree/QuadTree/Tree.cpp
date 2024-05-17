#include "Tree.h"
Tree::Tree(Rectangle r, int n) 
{
	boundary = r;
	capacity = n;
	x = r.getX();
	y = r.getY();
	width = r.getWidth();
	height = r.getHeight();
}
std::ostream& operator <<(std::ostream& os, const Tree& t) {
	os << t.x << " " << t.y << " " << t.width << " " << t.height << std::endl;
	return os;
}
void Tree::subdivide(Point p) {
	Rectangle nw(x - width / 2, y - height / 2, width / 2, height / 2);
	Rectangle ne(x + width / 2, y - height / 2, width / 2, height / 2);
	Rectangle sw(x - width / 2, y + height / 2, width / 2, height / 2);
	Rectangle se(x + width / 2, y + height / 2, width / 2, height / 2);
	Tree northWest(nw, capacity);
	Tree northEast(ne, capacity);
	Tree southWest(sw, capacity);
	Tree southEast(se, capacity);
	divided = true;
	northWest.insert(p);
	northEast.insert(p);
	southWest.insert(p);
	southEast.insert(p);
}
void Tree::insert(Point p) {
	if (boundary.contains(p) == false) return;
	if (points.size() < capacity) {
		std::cout << p;
		points.push_back(p);
	}
	else {
		if (!divided) {
			subdivide(p);
			
		}
	}
}

