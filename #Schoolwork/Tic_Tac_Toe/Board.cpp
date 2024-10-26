//
// Created by 王海生 on 2024/5/10.
//

#include"Board.h"
#include<iostream>
using namespace std;

Board::Board()
{
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            squares[i][j]=0;
        }
    }
    moves_done=0;
}

void Board::instructions()const
{
    cout<<"Hello"<<endl;
}

bool Board::done() const
{
    return moves_done==9||the_winner()>0;
}

int Board::the_winner()const
{
    int i;
    for(i=0;i<3;i++)
        if(squares[i][0]&&squares[i][0]==squares[i][1]&&squares[i][0]==squares[i][2])
            return squares[i][0];
    for(i=0;i<3;i++)
        if(squares[0][i]&&squares[0][i]==squares[1][i]&&squares[0][i]==squares[2][i])
            return squares[0][i];
    if(squares[0][0]&&squares[0][0]==squares[1][1]&&squares[0][0]==squares[2][2])
        return squares[0][0];
    if(squares[0][2]&&squares[0][2]==squares[1][1]&&squares[0][2]==squares[2][0])
        return squares[0][2];
    return 0;
}

void Board::print()const
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<" "<<squares[i][j];
        cout<<" "<<endl;
    }
    cout<<endl;
}

void Board::play(Move try_it)
{
    squares[try_it.row][try_it.col]=moves_done%2+1;
    moves_done++;
}

int Board::legal_moves(Stack &moves)const
{
    int count = 0;
    while(!moves.empty()) moves.pop();
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(squares[i][j]==0){
                Move can_play(i,j);
                moves.push(can_play);
                count++;
            }
    return count;
}

bool Board::ValidStep(Move try_it) const
{
    if(squares[try_it.row][try_it.col]==0)
        return true;
    else
        return false;
}

int Board::evaluate() const//���ϲ����۵�����
{
    int winner = the_winner();
    if(winner==1) return 10-moves_done;//�����ֶ��ԣ�return��ֵ��Ҫ����˵���ߵĲ����٣����á�
    else if(winner==2) return moves_done-10;//�Եڶ�����Ҷ��ԣ�����ֵԽСԽ�á�
    else return 0;
}

bool Board::better(int value,int old_value) const
{
    if(moves_done%2) return value<old_value;//�Եڶ������
    else return value>old_value;//�Ե�һ�����
}

int Board::worst_case() const
{
    if(moves_done%2) return 10;
    else return -10;
}