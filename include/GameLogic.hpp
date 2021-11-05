/*
 * awned 2021
 */

#ifndef GAMEOFLIFE_LOGIC_H
#define GAMEOFLIFE_LOGIC_H

#include "Utility.hpp"

void init(bool p_grid[GRIDSIZE][GRIDSIZE], const char *p_filePath);
int getNeighbours(bool p_grid[GRIDSIZE][GRIDSIZE], const int &p_x, const int &p_y);
void copyGrid(bool p_grid0[GRIDSIZE][GRIDSIZE], bool p_grid1[GRIDSIZE][GRIDSIZE]);
void update(bool p_grid[GRIDSIZE][GRIDSIZE]);

#endif /* GAMEOFLIFE_LOGIC_H */