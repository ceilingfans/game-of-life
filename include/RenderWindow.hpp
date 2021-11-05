/*
 * awned 2021
 */

#pragma once
#ifndef GAMEOFLIFE_RENDERWINDOW_H
#define GAMEOFLIFE_RENDERWINDOW_H

#include <string>

#include <SDL.h>

class RenderWindow
{
public:
    RenderWindow(const char *p_title, const int &p_width, const int &p_height);
    void clear();
    void display();
    void cleanUp();
    void renderCell(const int &p_x, const int &p_y, const int &p_gd);
private:
    SDL_Window   *window;
    SDL_Renderer *renderer;
    int width,
        height;

};

#endif /* GAMEOFLIFE_RENDERWINDOW_H */