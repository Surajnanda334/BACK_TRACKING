#include <iostream>

using namespace std;

const int N=8;    //Size of the board(change if you want a board of different size)

//Function Prototypes
void initBoard(int board[N][N]);
void print(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool knightTour(int board[N][N],int row,int col);

int main()
{
  int board[N][N];
  initBoard(board);
  if(knightTour(board,0,0))
  {
    print(board);
  }
  else
    cout<<"Solution doesnot exist";
  return 0;
}

void initBoard(int board[N][N])   //Initializes matrix with all zeros
{
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      board[i][j]=0;
}

void print(int board[N][N])   //Prints the Board
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
      cout<<board[i][j]<<" ";
      cout<<"\n";
    }

}

bool isSafe(int board[N][N],int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}