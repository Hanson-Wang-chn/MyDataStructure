//
// Created by 王海生 on 2024/4/27.
//

#ifndef EIGHTQUEENS2_EIGHTQUEENS2_H
#define EIGHTQUEENS2_EIGHTQUEENS2_H

#include "utility.h"

const int max_board = 30;

class Queens {
public:
    Queens(int size);
    bool is_solved() const;
    void print() const;
    bool unguarded(int col) const;
    void insert(int col);
    void remove(int col);
    int  board_size; //   dimension of board = maximum number of queens
private:
    int  count;      //   current number of queens = first unoccupied row
    bool col_free[max_board];
    bool upward_free[2 * max_board - 1];
    bool downward_free[2 * max_board - 1];
    int queen_in_row[max_board]; // column number of queen in each row
};

#endif //EIGHTQUEENS2_EIGHTQUEENS2_H
