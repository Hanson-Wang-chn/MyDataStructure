#include "MyStack.h"

int main()
/* Pre: None.
   Post: The program has notified the user of any bracket mismatch in the standard input file.*/

{
    instructions();

    MyStack openings;
    char symbol;

    bool is_matched = true;
    while (is_matched && ((symbol = cin.get()) != '\n')) {
        while (cin.fail()) { // Keep warning until a valid input is provided.
            cout << "Must be a valid input!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> symbol;
        }
        if (symbol == '{' || symbol == '[' || symbol == '(') {
            openings.push(symbol);
        } else if (symbol == '}' || symbol == ']' || symbol == ')') {
            if (openings.isEmpty()) {
                cout << "2.Unmatched closing bracket " << symbol << "detected." << endl;
                is_matched = false;
            } else {
                char match;
                openings.pop(match);
                is_matched = (symbol == ')' && match == '(') || (symbol == ']' && match == '[') || (symbol == '}' && match == '{');
                if (!is_matched) {
                    cout << "Bad match " << match << symbol << endl;
                }
            }
        }
    }
    if (!openings.isEmpty()) {
        cout << "1.Unmatched opening bracket(s) detected." << endl;
    } else if (is_matched) {
        cout << "0. Ok, matched!" << endl;
    }

    return 0;
}
