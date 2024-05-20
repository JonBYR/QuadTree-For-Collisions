// QuadTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "Rectangle.h"
#include "Point.h"
#include <SDL.h>
int main(int argc, char* args[])
{ //following this tutorial https://www.youtube.com/watch?v=OJxEcs0w_kE
    if (SDL_Init(SDL_INIT_EVERYTHING >= 0)) return 1; //to initialise SDL
    int width = 800;
    int height = 600;
    SDL_Window* window = SDL_CreateWindow("QuadTree Demonstration", 0, 0, width, height, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Rectangle rect;
    rect.Init(00, 00, width, height);
    Tree quadtree(std::move(rect), 4, rend); //should split at 4, similiar issues to tutorial however
    std::cout << quadtree;
    rect.renderRectangle(rend);
    for (int i = 0; i < 500; i++) {
        int randX = rand() % width + 1;
        int randY = rand() % height + 1; //generate points
        Point p(randX, randY);
        p.drawPoint(rend);
        quadtree.insert(p);
    }
    SDL_RenderPresent(rend);
    SDL_Delay(10000);
    return 0;
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
