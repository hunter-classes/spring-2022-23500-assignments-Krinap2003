#include <iostream>
#include <string>
#include <unistd.h>


//Prints the chess board
void print_board(int** board)
{
    //std::cout << "[0;0H\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(board[i][j] < 10)
            {
                std::cout<<" "<<board[i][j]<<":";
            }
            else
            std::cout<<board[i][j]<<":";
        }
        std::cout<<"\n";
    }
}

//Check is the chess board is solved
bool isSolved(int** board)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int ** board, int row, int col, bool &solved, int num)
{
  
    // check the base cases
    if (isSolved(board))
    {
        solved = true;
        return;
    }

    //Return If a the it goes out of bound or if it lands on the box that
    //is alredy used.
    if (row < 0 || col < 0 || row > 4|| col > 4 || board[row][col] != 0)
    {
        return;
    }

  
    board[row][col]=num;
    //usleep(800);
    print_board(board);
    std::cout<<"\n";
  
    //Go to every possible direction  
    if (!solved) solve(board,row+1,col+2,solved, num+1);
    if (!solved) solve(board,row+2,col+1,solved, num+1);
    if (!solved) solve(board,row-1,col-2,solved, num+1);
    if (!solved) solve(board,row-2,col-1,solved, num+1);
    if (!solved) solve(board,row+1,col-2,solved, num+1);
    if (!solved) solve(board,row+2,col-1,solved, num+1);
    if (!solved) solve(board,row-1,col+2,solved, num+1);
    if (!solved) solve(board,row-2,col+1,solved, num+1);
  
    if (!solved) board[row][col]=0;
}


int main()
{
    //Create a 5*5 2D array to represent the chess board
    int num=1;
    int **board;
    board = new int *[5];
    for(int i = 0; i <5; i++)
    board[i] = new int[5];
   

    //std::cout << "[2J;\n";
    bool solved = false;
    solve(board,0,0,solved, num);
    //solve(board,4,4,solved, num);
  
    //print_board(board);
    std::cout << "Done!\n";
  return 0;
  
}
