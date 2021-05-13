/* Rat in a Maze problem using backtracking */
#include <iostream>

using namespace std;

const int N=4;

bool solveMazeUtil(int maze[N][N], int x,int y, int sol[N][N]);

void printMatrix(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<< sol[i][j]<<"  ";
		cout<<"\n";
	}
}

// A function to check if the next point to move is safe
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}

bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout<<"Solution doesn't exist";
		return false;
	}

	printMatrix(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x,int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (x == N - 1 && y == N - 1	&& maze[x][y] == 1) 
  {
		sol[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) 
  {
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return false;
	
		// mark x, y as part of solution path
		sol[x][y] = 1;

		/* Move forward in x direction */
		if (solveMazeUtil(	maze, x + 1, y, sol)	== true)
			return true;

		/* If moving in x direction	doesn't give solution thenMove down in y direction */
		if (solveMazeUtil(maze, x, y + 1, sol)	== true)
			return true;
	
		/* If moving in y direction	doesn't give solution then Move back in x direction */
		if (solveMazeUtil(maze, x - 1, y, sol)== true)
			return true;

		/* If moving backwards in x direction	doesn't give solution then Move upwards in y direction */
		if (solveMazeUtil(maze, x, y - 1, sol)== true)
			return true;

		/* If none of the above movements	work then BACKTRACK: unmark	x, y as part of solution path */
		sol[x][y] = 0;
		return false;
	}

	return false;
}

int main()
{
	int maze[N][N] = {{ 1, 0, 0, 0 },
                    { 1, 0, 1, 1 },
                    { 1, 1, 1, 0 },
                    { 0, 1, 1, 1 } };
	cout<<"\nThe given maze\n";
	printMatrix(maze);
	cout<<"NOTE:'1' Represents the places where the rat can move and '0' represents where it cannot \n";
	cout<<"\nSolution of the maze\n";
	solveMaze(maze);
	return 0;
}