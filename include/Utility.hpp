/*
 * awned 2021
 */

#pragma once
#ifndef GAMEOFLIFE_UTILITY_H
#define GAMEOFLIFE_UTILITY_H

#include <iostream>

#include "Colours.hpp"

void printError(const char* e, const char* m)
{
    std::cout << KRED << e << ": " << m << std::endl;
}

#endif /* GAMEOFLIFE_UTILITY_H */