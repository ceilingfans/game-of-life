#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include "RenderWindow.hpp"
#include "GameLogic.hpp"
#include "Utility.hpp"

void mainLoop();

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "failed to init sdl: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    mainLoop();
    SDL_Quit();

    return EXIT_SUCCESS;
}

void mainLoop()
{
    RenderWindow window("Game of Life", 800, 800);
    SDL_Event event;
    SDL_bool gameRunning = SDL_TRUE;

    bool grid[GRIDSIZE][GRIDSIZE];
    init(grid, "resources/in.txt");

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = SDL_FALSE;
            }
        }

        window.clear();
        SDL_SetRenderDrawColor(window.getRenderer(), 255, 255, 255, 255);
        for (int x = 0; x < GRIDSIZE; ++x)
        {
            for (int y = 0; y < GRIDSIZE; ++y)
            {
                if (grid[x][y])
                {
                    window.renderCell(x, y);
                }
            }
        }
        SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 255);
        window.display();

        update(grid);
        SDL_Delay(100);
    }
    window.cleanUp();
}