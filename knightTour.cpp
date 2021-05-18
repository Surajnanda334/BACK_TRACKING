#include <iostream>
#include<iomanip>   // to use seyw() we have to use iomanip

using namespace std;

const int N=8;    //Size of the board(change if you want a board of different size)

//Function Prototypes
void initBoard(int board[N][N]);
void print(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool knightTour(int board[N][N], int MoveX[N], int MoveY[N], int x, int y ,int move);

int main()
{
  int MoveX[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };    //Array to store knight's move in X-dirrection
  int MoveY[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };    //Array to store knight's move in Y-dirrection (MoveX[0],MoveT[0] reffers to the first position of knight's move)
  int board[N][N];
  initBoard(board);
  board[0][0]=1;    // Place the knight at board[0][0]
 
  if(knightTour(board,MoveX,MoveY,0,0,2))
  {
    print(board);
  }
  else
    cout<<"Solution doesnot exist";
  return 0;
}

void initBoard(int board[N][N])   //Initializes matrix with all '-1'
{
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      board[i][j]=0;
}

void print(int board[N][N])   //Function to Print the Board
{
  for (int x = 0; x < N; x++) 
  {
		for (int y = 0; y < N; y++)
			cout << " " << setw(3) << board[x][y] << " ";   //setw(3) is used to allign all elements of board
		cout << "\n\n";
	}

}

bool isSafe(int board[N][N],int x, int y)
{
	if(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0)  // If the position is in bounds and is equal to 0 (where knight has not visited)
    return true;
  return false;
}


bool knightTour(int board[N][N], int MoveX[N], int MoveY[N], int x, int y ,int move)    
{
  int nextX, nextY;
  if(move>N*N)
    return true;
  for(int i=0;i<N;i++)
  {
    nextX=x+MoveX[i];   //update the next position of knight's movement
    nextY=y+MoveY[i];
    if(isSafe(board, nextX, nextY))
    {
      board[nextX][nextY]=move;   // If the next position is safe then place knight at board[nextX][nextY] and mark board[nextX][nextY] visited

      if(knightTour(board, MoveX, MoveY, nextX, nextY , move+1))    // Recursive call to check if placing knight at board[nextX][nextY] solves the problem
        return true;
      else  
        board[nextX][nextY]=0;  // Backtrack and mark board[nextX][nextY] unvisited
    }
  }
  return false;
}