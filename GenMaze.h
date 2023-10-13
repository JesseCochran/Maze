#include <iostream>

#include "Maze.h"

class GenMaze
{
private:
    int ValidatedIntInput(std::string errorMsg, bool greaterThanZero);

public:
    void GetPerfectMaze(Maze &maze, bool mode);
};
