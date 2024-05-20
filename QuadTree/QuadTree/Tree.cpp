#include "Tree.h"
Tree::Tree() 
{

}
Tree::Tree(Rectangle r, int n, SDL_Renderer* re, Tree* p) 
{
	boundary = r;
	capacity = n;
	x = r.getX();
	y = r.getY();
	width = r.getWidth();
	height = r.getHeight();
	rend = re;
	points.clear();
	parent = p;
	currentPoints = n;
	if (p != nullptr) {
		for (int i = 0; i < p->points.size(); i++) { //should any points already exist in the quadrant, then ensure that the number of remaining points is lessened to fit the desired capacity
			Point point = p->points[i];
			if (boundary.contains(point)) currentPoints--;
		}
	}
}
std::ostream& operator <<(std::ostream& os, const Tree& t) { //overloading ostream operator
	os << t.x << " " << t.y << " " << t.width << " " << t.height << std::endl;
	return os;
}
void Tree::subdivide(Point p) {
	Rectangle nw;
	Rectangle ne;
	Rectangle sw;
	Rectangle se;
	nw.Init(x, y, width / 2, height / 2); //SDL_Rect starts at point x,y in top left corner 
	ne.Init(x + width / 2, y, width / 2, height / 2);
	sw.Init(x, y + height / 2, width / 2, height / 2); //when moving down y in SDL it is + height, as y = 0 is top left corner
	se.Init(x + width / 2, y + height / 2, width / 2, height / 2);
	nw.renderRectangle(rend);
	ne.renderRectangle(rend);
	sw.renderRectangle(rend);
	se.renderRectangle(rend);
	northWest = new Tree(nw, capacity, rend, this);
	northEast = new Tree(ne, capacity, rend, this);
	southWest = new Tree(sw, capacity, rend, this);
	southEast = new Tree(se, capacity, rend, this); //create new tree dynamically 
	divided = true;
}
void Tree::insert(Point p) {
	if (boundary.contains(p) == false) return; //if the point is not within the set constraints it does not fit into this tree
	if (points.size() < currentPoints) { //if the tree does not contain as many points as it can allow, place point in this subtree
		std::cout << p;
		points.push_back(p);
	}
	else {
		if (!divided) { //if this tree has not been divided yet, then subdivide
			subdivide(p); //if capacity is reached, break tree into subtrees
		}
		northWest->insert(p); //check if point can be inserted into the new quadrants after subdividing them
		northEast->insert(p);
		southWest->insert(p);
		southEast->insert(p);
	}
}
Tree::~Tree() { //delete dynamic objects
	delete northWest;
	delete northEast;
	delete southWest;
	delete southEast;
}
