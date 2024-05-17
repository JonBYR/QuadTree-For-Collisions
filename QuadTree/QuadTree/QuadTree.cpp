// QuadTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "Rectangle.h"
#include "Point.h"
int main()
{ //following this tutorial https://www.youtube.com/watch?v=OJxEcs0w_kE
    Rectangle rect(200, 200, 200, 200);
    Tree quadtree(std::move(rect), 4);
    std::cout << quadtree;
    for (int i = 0; i < 5; i++) {
        int randX = rand() % (int)200 + 1;
        int randY = rand() % (int)200 + 1;
        Point p(randX, randY);
        quadtree.insert(p);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
