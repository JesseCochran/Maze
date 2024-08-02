# Maze Generator

This project is a C++ application that generates a perfect maze based on user-defined dimensions. The maze generation algorithm ensures that the maze is solvable and has only one unique path between any two points.

## Features

Perfect Maze Generation: Uses a maze generation algorithm to produce a maze with a single unique solution.
Customizable Dimensions: Users can specify the length and width of the maze.
Testing Mode: Allows running the program in a testing mode for development purposes.

## Getting Started

To use this maze generator, you need to compile the C++ code and run the executable. Below are the steps to get started:

### Prerequisites

C++ compiler (e.g., g++, clang++)
C++ Standard Library

### Compilation

To compile the project, navigate to the directory containing the source code and use the following command:

```g++ -o maze_generator MazeMain.cpp GenMaze.cpp Maze.cpp```

### Running the Program

After compiling, you can run the maze generator executable. The program supports two modes:

**Normal Mode:** Default mode where the program generates and displays the maze.

**Testing Mode:** Activated by including the ```-testmode``` argument when running the executable. This mode provides additional output for debugging purposes.

## User Input

When the program runs, it will prompt you to enter the dimensions of the maze:

Length: The length of the maze.
Width: The width of the maze.
Both inputs should be positive integers. The program will validate the inputs and ensure they are greater than zero.

## Example

Here's an example of running the program:

```
./maze_generator
Enter the length and width of maze:
5
7
Structure:
[Generated maze structure displayed here]
The End!
```

**Code Overview**

**MazeMain.cpp:** Contains the entry point for the application and handles the mode selection.
**GenMaze.h and GenMaze.cpp:** Define and implement the GenMaze class, which is responsible for generating the maze.
**Maze.h and Maze.cpp:** Define and implement the Maze class, which represents the maze structure and handles maze generation and display.





