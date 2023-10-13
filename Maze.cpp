#include "Maze.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

// constructors
Maze::Maze()
{
    this->mazeVector = new std::vector<std::vector<char>>;
}
Maze::Maze(unsigned int length, unsigned int width, bool mode)
{
    this->length = length;
    this->width = width;
    this->mode = mode;
    // pre assigns length to save memory
    this->mazeVector = new std::vector<std::vector<char>>(this->length, std::vector<char>(this->width));
}

// destructor
Maze::~Maze()
{
    // delete mazeVector;
}

// getters and setters
std::vector<std::vector<char>> *Maze::GetMazeVector()
{
    return mazeVector;
}
unsigned int Maze::GetLength()
{
    return length;
}
unsigned int Maze::GetWidth()
{
    return width;
}
bool Maze::GetMode()
{
    return mode;
}
void Maze::DeleteMaze()
{
    delete mazeVector;
}
void Maze::SetMaze(std::vector<std::vector<char>> *mazeVector)
{
    this->mazeVector = mazeVector;
}

// functions for perfect maze
void Maze::GeneratePerfectMaze()
{

    CreateEmptyMaze(length, width);
    std::cout << "Maze generated successfully\n";
    // testing mode
    if (mode == 1)
    {
        startCol = 1;
        startRow = 1;
        // start pos
        mazeVector->at(startCol).at(startRow) = '.';
        // gate
        mazeVector->at(startCol).at(startRow - 1) = '.';
    }
    // normal mode
    else if (mode == 0)
    { // shows the mode for user feedback
        // std::cout << "normal mode\n";
        //  make a new random option
        std::srand(std::time(0));
        // pick random possible starting point
        RandomStart();
    }
    // keeps running through the function until complete
    RecursiveBacktracker(startRow, startCol, visitedCells);
}
void Maze::RecursiveBacktracker(int x, int y, std::vector<std::pair<int, int>> &visitedCells)
{
    // creates a vector to store the available directions in
    std::vector<int> movementOptions;

    // Check if moving up is possible
    if (y + 2 < static_cast<int>(length) && mazeVector->at(y + 2).at(x) == '_')
    {
        movementOptions.push_back(1);
    }
    // Check if moving right is possible
    if (x + 2 < static_cast<int>(width) && mazeVector->at(y).at(x + 2) == '_')
    {
        movementOptions.push_back(2);
    }
    // Check if moving down is possible
    if (y - 2 >= 0 && mazeVector->at(y - 2).at(x) == '_')
    {
        movementOptions.push_back(3);
    }
    // Check if moving left is possible
    if (x - 2 >= 0 && mazeVector->at(y).at(x - 2) == '_')
    {
        movementOptions.push_back(4);
    }

    if (!movementOptions.empty())
    {
        // picks a random direction to travel in from the available directions
        int randomIndex = std::rand() % movementOptions.size();
        // testing
        //  std::cout << randomIndex << " - size: " << movementOptions.size() << "\n";

        // Store the current movement in the vector of visited cells
        visitedCells.push_back(std::make_pair(x, y));
        // Fills in the grid space to show that it has been visited
        //  up
        if (movementOptions.at(randomIndex) == 1)
        {
            mazeVector->at(y + 1).at(x) = '.';
            mazeVector->at(y + 2).at(x) = '.';
            RecursiveBacktracker(x, y + 2, visitedCells);
        }
        // right
        else if (movementOptions.at(randomIndex) == 2)
        {
            mazeVector->at(y).at(x + 1) = '.';
            mazeVector->at(y).at(x + 2) = '.';
            RecursiveBacktracker(x + 2, y, visitedCells);
        }
        // down
        else if (movementOptions.at(randomIndex) == 3)
        {
            mazeVector->at(y - 1).at(x) = '.';
            mazeVector->at(y - 2).at(x) = '.';
            RecursiveBacktracker(x, y - 2, visitedCells);
        }
        // left
        else if (movementOptions.at(randomIndex) == 4)
        {
            mazeVector->at(y).at(x - 1) = '.';
            mazeVector->at(y).at(x - 2) = '.';
            RecursiveBacktracker(x - 2, y, visitedCells);
        }
    }
    else if (!visitedCells.empty())
    {
        // Backtrack if no more unvisited cells are available
        std::pair<int, int> lastMovement = visitedCells.back();
        visitedCells.pop_back();

        RecursiveBacktracker(lastMovement.first, lastMovement.second, visitedCells);
    }
}
// creates the maze grid
void Maze::CreateEmptyMaze(unsigned int length, unsigned int width)
{
    // clears the grid if there is already a maze in it
    mazeVector->clear();
    for (size_t i = 0; i < length; i++)
    {
        mazeVector->push_back(std::vector<char>());
        for (size_t j = 0; j < width; j++)
        {
            // checks if its the top or bottom border
            if (i == 0 || i == length - 1)
            {
                mazeVector->at(i).push_back('x');
            }
            // checks if its left or right border
            else if (j == 0 || j == width - 1)
            {
                mazeVector->at(i).push_back('x');
            }
            else if (i % 2 == 0)
            {
                mazeVector->at(i).push_back('x');
            }
            else if (j % 2 == 0)
            {
                mazeVector->at(i).push_back('x');
            }
            else
            {
                // inner value
                mazeVector->at(i).push_back('_');
            }
        }
    }
}
void Maze::RandomStart()
{
    bool validStart = false;

    // Ensure that the selected position is an underscore ('_')
    while (validStart == false)
    {
        // Get random row index
        startCol = rand() % mazeVector->size();
        // Get random column index
        startRow = rand() % mazeVector->at(0).size();
        // checks if its a valid starting point
        if (mazeVector->at(startCol).at(startRow) == '_')
        {
            if (startRow + 1 == static_cast<int>(length))
            {
                mazeVector->at(startCol).at(startRow) = '.';
                mazeVector->at(startCol).at(startRow + 1) = '.';
                validStart = true;
            }
            if (startRow - 1 == 0)
            {
                mazeVector->at(startCol).at(startRow) = '.';
                mazeVector->at(startCol).at(startRow - 1) = '.';
                validStart = true;
            }
            if (startCol + 1 == static_cast<int>(width))
            {
                mazeVector->at(startCol).at(startRow) = '.';
                mazeVector->at(startCol + 1).at(startRow) = '.';
                validStart = true;
            }
            if (startCol - 1 == 0)
            {
                mazeVector->at(startCol).at(startRow) = '.';
                mazeVector->at(startCol - 1).at(startRow) = '.';
                validStart = true;
            }
        }
    }
}
void Maze::PrintMaze()
{
    for (unsigned int i = 0; i < length; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            std::cout << mazeVector->at(i).at(j);
        }
        std::cout << '\n';
    }
    // print it to terminal
    std::cout << "**End Printing Maze**\n";
}
