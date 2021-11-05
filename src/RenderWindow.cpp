/*
 * awned 2021
 */

#include <string>
#include <cstdlib>
#include <iostream>

#include "Utility.hpp"
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *p_title, const int &p_width, const int &p_height) : window(nullptr), renderer(nullptr)
{
    width = p_width;
    height = p_height;

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "failed to create window: " << SDL_GetError() << std::endl;
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

void RenderWindow::renderCell(const int &p_x, const int &p_y)
{
    int cellLength = width/GRIDSIZE;

    SDL_Rect r = { p_x*cellLength, p_y*cellLength, cellLength, cellLength };
    SDL_RenderFillRect(renderer, &r);
}