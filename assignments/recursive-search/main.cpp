#include <iostream>
#include <string>
#include <unistd.h>

//int board[5][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

// int num=1;
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

    if (row < 0 || col < 0 || row > 4|| col > 4 || board[row][col] != 0)
    {
        return;
    }

  
    board[row][col]=num;
    //usleep(800);
    print_board(board);
    std::cout<<"\n";
  
    
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
    int num=1;
    int **board;
    board = new int *[5];
    for(int i = 0; i <5; i++)
    board[i] = new int[5];
   

    //std::cout << "[2J;\n";
    bool solved = false;
    solve(board,0,0,solved, num);
  
    //print_board(board);
    std::cout << "Done!\n";
  return 0;
  
}
