#include <iostream>
#include "MyStack.h"

int main()
/* Pre: The user supplies an integer n and n decimal members. The variable n must be less than 100.
   Post: The numbers are printed in reverse order.
   Uses: The MyStack class described in "MyStack.h" and "MyStack.cpp"*/

{
    using namespace std;

    MyStack stack;

    cout << "Type in an integer n followed by n decimal numbers." << endl;
    cout << "The numbers will be printed in reverse order." << endl;

    int n;
    cin >> n;

    Data_type temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        stack.push(temp);
    }
    cout << endl << endl;

    Data_type value;
    while (!stack.isEmpty()) {
        stack.pop(value);
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
