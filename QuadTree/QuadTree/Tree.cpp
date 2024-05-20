#include "Tree.h"
Tree::Tree(Rectangle r, int n, SDL_Renderer* re) 
{
	boundary = r;
	capacity = n;
	x = r.getX();
	y = r.getY();
	width = r.getWidth();
	height = r.getHeight();
	rend = re;
}
std::ostream& operator <<(std::ostream& os, const Tree& t) {
	os << t.x << " " << t.y << " " << t.width << " " << t.height << std::endl;
	return os;
}
void Tree::subdivide(Point p) {
	Rectangle nw;
	Rectangle ne;
	Rectangle sw;
	Rectangle se;
	nw.Init(x - width / 2, y - height / 2, width / 2, height / 2);
	ne.Init(x + width / 2, y - height / 2, width / 2, height / 2);
	sw.Init(x - width / 2, y + height / 2, width / 2, height / 2);
	se.Init(x + width / 2, y + height / 2, width / 2, height / 2);
	nw.renderRectangle(rend);
	ne.renderRectangle(rend);
	sw.renderRectangle(rend);
	se.renderRectangle(rend);
	Tree northWest(nw, capacity, rend);
	Tree northEast(ne, capacity, rend);
	Tree southWest(sw, capacity, rend);
	Tree southEast(se, capacity, rend);
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

