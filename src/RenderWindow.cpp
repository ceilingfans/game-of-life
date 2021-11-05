/*
 * awned 2021
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "RenderWindow.hpp"
#include "Utility.hpp"

RenderWindow::RenderWindow(const char *p_title, const int &p_width, const int &p_height) : window(nullptr), renderer(nullptr)
{
    width = p_width;
    height = p_height;

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        printError("SDL ERROR", SDL_GetError());
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}
void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::renderCell(const int &p_x, const int &p_y, const int &p_gd)
{
    int cellLength = width/p_gd;

    SDL_Rect r = { cellLength*p_x, cellLength*p_y, cellLength, cellLength };
    SDL_RenderFillRect(renderer, &r);
}

