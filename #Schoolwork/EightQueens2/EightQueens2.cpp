//
// Created by 王海生 on 2024/4/27.
//

#include"EightQueens2.h"

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
            if(j==queen_in_row[i]) cout<<" "<<"1"<<" "<<flush;
            else cout<<" "<<"0"<<" "<<flush;
        }
        cout<<"  "<<endl;
    }
    cout<<endl<<endl;
}

void Queens::remove(int col)
{
    count--;
    col_free[col] = true;
    upward_free[count + col] = true;
    downward_free[count - col + board_size - 1] = true;
}

void Queens::insert(int col)
/*
Pre:  The square in the first unoccupied row (row count) and column col
      is not guarded by any queen.
Post: A queen has been inserted into the square at row count and column
      col; count has been incremented by 1.
*/
{
    queen_in_row[count] = col;
    col_free[col] = false;
    upward_free[count + col] = false;
    downward_free[count - col + board_size - 1] = false;
    count++;
}


Queens::Queens(int size)
/*
Post: The Queens object is set up as an empty
      configuration on a chessboard with size squares in each row and column.
*/
{
    board_size = size;
    count = 0;
    for (int i = 0; i < board_size; i++)col_free[i] = true;
    for (int j = 0; j < (2 * board_size - 1); j++)upward_free[j] = true;
    for (int k = 0; k < (2 * board_size - 1); k++)downward_free[k] = true;
}


bool Queens::unguarded(int col) const
/*
Post: Returns true or false according as the square in the first
      unoccupied row (row count) and column col is not guarded by any queen.
*/
{
    return col_free[col]
           && upward_free[count+col]
           && downward_free[count-col+board_size-1];
}