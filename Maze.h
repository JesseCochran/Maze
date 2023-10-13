#ifndef ASSIGN_MAZE_H
#define ASSIGN_MAZE_H

#include <vector>

class Maze
{
public:
    // constructors
    Maze();
    Maze(unsigned int length, unsigned int width, bool mode);

    // destructor
    ~Maze();

    // functions
    std::vector<std::vector<char>> *GetMazeVector();
    unsigned int GetLength();
    unsigned int GetWidth();
    bool GetMode();
    // CONTRACT: When generating a maze odd numbers must be used for length and width
    void GeneratePerfectMaze();
    void CreateEmptyMaze(unsigned int length, unsigned int width);
    void RecursiveBacktracker(int startCol, int startRow, std::vector<std::pair<int, int>> &visitedCells);
    void RandomStart();
    void PrintMaze();
    bool IsWithinBounds(int row, int col);
    bool CanBreakWallWithoutLoop(int x1, int y1, int x2, int y2);
    void SetMaze(std::vector<std::vector<char>> *mazeVector);
    void DeleteMaze();

private:
    // variables
    unsigned int length;
    unsigned int width;
    int startRow;
    int startCol;
    bool mode;
    std::vector<std::vector<char>> *mazeVector;
    std::vector<std::pair<int, int>> visitedCells;
};

#endif // ASSIGN_MAZE_H