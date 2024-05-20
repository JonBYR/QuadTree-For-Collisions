#include "TreeHolder.h"
TreeHolder::TreeHolder(Tree nw, Tree ne, Tree sw, Tree se) {
	NW = nw;
	NE = ne;
	SW = sw;
	SE = se;
}
void TreeHolder::subdividedInsert(Point p) {
	NW.insert(p);
	NE.insert(p);
	SW.insert(p);
	SE.insert(p);
}