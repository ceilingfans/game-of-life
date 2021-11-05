/*
 * awned 2021
 */

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "GameLogic.hpp"
#include "Utility.hpp"

void init(bool p_grid[GRIDSIZE][GRIDSIZE], const char* p_filePath)
{
    for (int x = 0; x < GRIDSIZE; ++x)
    {
        for (int y = 0; y < GRIDSIZE; ++y)
        {
            p_grid[x][y] = false;
        }
    }

    std::ifstream readfile(p_filePath);
    if (readfile.is_open())
    {
        std::string line, x, y;

        while(std::getline(readfile, line))
        {
            std::stringstream ss(line);

            std::getline(ss, x, ' ');
            std::getline(ss, y, ' ');

            p_grid[std::stoi(x)][std::stoi(y)] = true;
        }
    }
    else
    {
        std::cout << "failed to read file" << std::endl;
        exit(-1);
    }
}

int getNeighbours(bool p_grid[GRIDSIZE][GRIDSIZE], const int &p_x, const int &p_y)
{
    int neighbours = 0;

    for (int x_sh = -1; x_sh < 2; ++x_sh)
    {
        for (int y_sh = -1; y_sh < 2; ++y_sh)
        {
            if (!(x_sh == 0 && y_sh == 0))
            {
                int x = p_x+x_sh,
                    y = p_y+y_sh;

                if (!(x < 0 || x > (GRIDSIZE-1) || y < 0 || y > (GRIDSIZE-1)))
                {
                    if (p_grid[x][y])
                    {
                        ++neighbours;
                    }
                }
            }
        }
    }

    return neighbours;
}

void copyGrid(bool p_grid0[GRIDSIZE][GRIDSIZE], bool p_grid1[GRIDSIZE][GRIDSIZE])
{

    // std::copy(&a[0][0], &a[0][0]+50*50,&b[0][0]);
    for (int x = 0; x < GRIDSIZE; ++x)
    {
        for (int y = 0; y < GRIDSIZE; ++y)
        {
            p_grid1[x][y] = p_grid0[x][y];
        }
    }
}

void update(bool p_grid[GRIDSIZE][GRIDSIZE])
{
    bool cpy_grid[GRIDSIZE][GRIDSIZE];
    copyGrid(p_grid, cpy_grid);

    for (int x = 0; x < GRIDSIZE; x++)
    {
        for (int y = 0; y < GRIDSIZE; y++)
        {
            int neighbours = getNeighbours(cpy_grid, x, y);
            if (neighbours < 2 || neighbours > 3)
            {
                p_grid[x][y] = false;
            }
            else if (neighbours == 3)
            {
                p_grid[x][y] = true;
            }
        }
    }
}