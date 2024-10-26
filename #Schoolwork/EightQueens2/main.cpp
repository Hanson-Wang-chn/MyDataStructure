#include"EightQueens2.h"
#include"time.h"

int g_cnt = 0; // 全局变量，存储找到的棋子组合的个数

int main()
/*
Pre:  The user enters a valid board size.
Post: All solutions to the n-queens puzzle for the selected
      board size are printed.
Uses: The class Queens and the recursive function solve_from.
*/
{
    int board_size;
    void solve_from(Queens &configuration);
    void print_information();
    print_information();
    cout << "What is the size of the board? " << flush;
    cin  >> board_size;
    double start=time(NULL);
    if (board_size < 0 || board_size > max_board)
        cout << "The number must be between 0 and " << max_board << endl;
    else {
        Queens configuration(board_size); //   Initialize empty configuration.
        solve_from(configuration);  //  Find all solutions extending configuration.
    }
    double end=time(NULL);
    cout<<"It takes time: "<<(end-start)<<"(s)"<<endl;
    cout << "The count of the answer is: " << g_cnt << endl;

    return 0;
}

void print_information()
{
    cout<<"This is the Queens game."<<endl;
}

void solve_from(Queens &configuration)
/*
Pre:  The Queens configuration represents a partially completed
      arrangement of nonattacking queens on a chessboard.
Post: All n-queens solutions that extend the given configuration are printed.
      The configuration is restored to its initial state.
Uses: The class Queens and the function solve_from, recursively.
*/
{
    if (configuration.is_solved()) {
//        configuration.print();
        g_cnt++;
    }
    else
        for (int col = 0; col < configuration.board_size; col++)
            if (configuration.unguarded(col)) {
                configuration.insert(col);
                solve_from(configuration);   //   Recursively continue to add queens.
                configuration.remove(col);
            }
}