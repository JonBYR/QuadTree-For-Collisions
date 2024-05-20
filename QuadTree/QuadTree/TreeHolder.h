#pragma once
#include "Tree.h"
#include "Point.h"
#include "TreeHolder.h"
class TreeHolder //UNUSED CLASS
{
public:
	TreeHolder(Tree nw, Tree ne, Tree sw, Tree se);
	void subdividedInsert(Point p);
private:
	Tree NE;
	Tree NW;
	Tree SE;
	Tree SW;
};

