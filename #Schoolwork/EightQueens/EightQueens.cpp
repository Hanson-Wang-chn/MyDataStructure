//
// Created by 王海生 on 2024/4/27.
//

#include"EightQueens.h"

bool Queens::is_solved() const
{
    return(count==board_size);
}


void Queens::print() const
{
    int i,j;
    for(i=0;i<board_size;i++)
    {
        for(j=0;j<board_size;j++)
        {
            cout<<" "<<queen_square[i][j]<<" "<<flush;
        }
        cout<<"  "<<endl;
    }
    cout<<endl<<endl;
}

void Queens::remove(int col)
{
    queen_square[--count][col]= false;
}

void Queens::insert(int col)
/*
Pre:  The square in the first unoccupied row (row count) and column col
      is not guarded by any queen.
Post: A queen has been inserted into the square at row count and column
      col; count has been incremented by 1.
*/
{
    queen_square[count++][col] = true;
}


Queens::Queens(int size)
/*
Post: The Queens object is set up as an empty
      configuration on a chessboard with size squares in each row and column.
*/
{
    board_size = size;
    count = 0;
    for (int row = 0; row < board_size; row++)
        for (int col = 0; col < board_size; col++)
            queen_square[row][col] = false;
}


bool Queens::unguarded(int col) const
/*
Post: Returns true or false according as the square in the first
      unoccupied row (row count) and column col is not guarded by any queen.
*/
{
    int i;
    bool ok = true; //   turns false if we find a queen in column or diagonal

    for (i = 0; ok && i < count; i++)
        ok = !queen_square[i][col];              //   Check upper part of column
    for (i = 1; ok && count - i >= 0 && col - i >= 0; i++)
        ok = !queen_square[count - i][col - i];  //  Check upper-left diagonal
    for (i = 1; ok && count - i >= 0 && col + i < board_size; i++)
        ok = !queen_square[count - i][col + i];  //  Check upper-right diagonal

    return ok;
}