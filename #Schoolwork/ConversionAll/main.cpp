#include "MyStack.h"
#include <stdio.h>

int main()
// Pre: The user provides a decimal number n and a base number r.
// Post:Convert decimal numbers to base-r numbers and output.
{
    MyStack stack;

    int n;
    cout << "Please enter the decimal number n to be converted: " << endl;
    cin >> n;   check_stream(n); // Loop until a valid input is entered.

    int r;
    cout << "Please enter the base number r to be converted: " << endl;
    cin >> r;   check_stream(r);

    while (n) {
        stack.push(n % r);
        n /= r;
    }

    while (!stack.isEmpty()) {
        int temp;
        stack.pop(temp);
        char ch;
        if (temp <= 9) {
//            cout << temp << " ";
            printf("%d ", temp);
        } else {
//            cout << 'A' + temp - 10 << " ";
            printf("%c ", 'A' + temp - 10);
        }
    }
    cout << endl;

    return 0;
}
