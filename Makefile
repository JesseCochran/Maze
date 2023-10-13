.default: all

all: MazeMain

clean:
	rm -f MazeMain *.o

MazeMain: Maze.o MazeMain.o GenMaze.o 
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^