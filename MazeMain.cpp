#include <iostream>

#include <cstdlib>
#include "Maze.h"
#include "GenMaze.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

int main(int argc, char *argv[])
{
    // default mode
    bool mode = NORMAL_MODE;

    // checks if -testmode was included to run
    if (argc > 1)
    {
        std::string arg = argv[1];
        if (arg == "-testmode")
        {
            mode = TESTING_MODE;
        }
        // note to show us if its running
        std::cout << "TESTING MODE\n";
    }
    Maze maze;
    GenMaze genMaze;

    // Gets randomly generated maze
    genMaze.GetPerfectMaze(maze, mode);

    std::cout << std::endl;
    std::cout << "The End!" << std::endl;
    std::cout << std::endl;
    return EXIT_SUCCESS;
}