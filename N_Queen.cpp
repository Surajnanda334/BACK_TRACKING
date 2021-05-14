#include <iostream>

using namespace std;

const int N=5;    //Size of the board

//Function Prototypes
void initBoard(int board[N][N]);
void print(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool nQueen(int board[N][N],int col);

int main()
{
  int board[N][N];
  initBoard(board);
  if(nQueen(board,0))
  {
    cout<<"\nAll the Queens have been placed in the board such as no Queen atacks any other.\nNOTE:Here '1' represents A Queen on the board\n\n";
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

bool isSafe(int board[N][N], int row, int col)    //Checks if the current position is safe or not
{
  int i,j;
  for(i=0;i<col;i++)    //Checks the current row up to 'col'
    if(board[row][i])
      return false;
  for(i=row,j=col; i>=0 && j>=0; i--,j--)   //Checks for the left diagonal
    if(board[i][j])
      return false;
  for(i=row,j=col; i>=0 && j<N; i--,j++)    //Checks for the right diagonal
    if(board[i][j])
      return false;
  return true;
}

bool nQueen(int board[N][N],int col)    //Function to solve n-Queen problem
{
  if(col>=N)    //If all N Queens are placed then return true
    return true;
  for(int i=0;i<N;i++)
  {
    if(isSafe(board,i,col))   //If the current position is safe then place the queen
    {
      board[i][col]=1;
    
      if(nQueen(board,col+1))   //If there exist a solution for the next coloumn then return true
        return true;
      
      board[i][col]=0;    //If placing the queen doesnot solve the problem then remove the queen from current position
    }
  }
  return false;   //If there exists no solution return false
}
