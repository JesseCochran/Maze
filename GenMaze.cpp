
#include "GenMaze.h"

// GenMaze::GenMaze() {

// }

// GenMaze::~GenMaze() {

// }

int GenMaze::ValidatedIntInput(std::string errorMsg, bool greaterThanZero)
{
    // nathan - gets validated input of an int, for coords input and maze size probably
    //          some other things too

    // input a error msg, and whether the number should be greater than 0 or not.

    // variable to hold whether cin has produced an er
    bool cinError = true;
    int input;

    while (cinError)
    {
        // initialises loop with no error. Had to be true for the loop to start
        cinError = false;

        // gets player input
        std::cin >> input;

        // error detection stuff
        // second argument checks if the input and the greaterthan0 variable match
        // only passes when input is true
        if (std::cin.fail() || (input <= 0 && greaterThanZero))
        {
            // Clear the fail state
            std::cin.clear();
            // Clear the input buffer
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";

            // outputs the input msg, should include \n in it.
            std::cout << errorMsg;

            // if theres an error try again
            cinError = true;
        }
        // loops if theres an error, taking input again.
    }
    return input;
}

void GenMaze::GetPerfectMaze(Maze &maze, bool mode)
{
    std::cout << "Enter the length and width of maze: \n";
    // gets validated player input
    unsigned int length = ValidatedIntInput("Enter the length and width of maze as a positive integer: \n", true);
    unsigned int width = ValidatedIntInput("Enter the width of maze as a positive integer: \n", true);

    // make maze
    maze = Maze(length, width, mode);
    maze.GeneratePerfectMaze();
    std::cout << "Structure: \n";
    maze.PrintMaze();
}
