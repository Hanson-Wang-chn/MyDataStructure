#include"Board.h"
#include<iostream>

using namespace std;

int look_ahead(const Board &game,int depth,Move & recommended)
{
    if(game.done()||depth==0)
        return game.evaluate();
    else{
        Stack moves;
        game.legal_moves(moves);
        int value,best_value=game.worst_case();
        while(!moves.empty()){
            Move try_it,reply;
            moves.top(try_it);
            Board newgame=game;
            newgame.play(try_it);
            value = look_ahead(newgame,depth-1,reply);
            if(game.better(value,best_value)){
                best_value = value;
                recommended = try_it;
            }
            moves.pop();
        }
        return best_value;
    }
}

int main()
{
    Board game;
    Move recommended;
    int x,y;
    int i=9;
    game.instructions();
    while(!game.done()){
        look_ahead(game, i, recommended);
        game.play(recommended);
        cout<<"Computer:"<<endl;
        game.print();
        if(game.done())break;
        cout<<"Your turn:"<<endl;
        cout<<"X:";
        cin>>x;
        cout<<"Y:";
        cin>>y;
        Move me(x,y);
        game.play(me);
        game.print();
        i--;
    }
    if(game.the_winner()==1) cout<<"Game over with computer win."<<endl;
    else if (game.the_winner()==2) cout<<"Game over with you win."<<endl;//impossible
    else cout<<"Game over with a draw."<<endl;//only when you go (1,1) at first step.

}