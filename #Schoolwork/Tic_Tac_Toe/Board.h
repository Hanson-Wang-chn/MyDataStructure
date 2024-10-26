//
// Created by 王海生 on 2024/5/10.
//

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include"LinkedStack.h"
class Board {
public:
    Board( );
    bool done( ) const;
    void print( ) const;
    void instructions( ) const;
    bool better(int value, int old_value) const;
    bool ValidStep(Move try_it) const;
    void play(Move try_it);
    int worst_case( ) const;
    int evaluate( ) const;
    int legal_moves(Stack &moves) const;
    int the_winner( ) const;
private:
    int squares[3][3];
    int moves_done;
};

#endif //TIC_TAC_TOE_BOARD_H
