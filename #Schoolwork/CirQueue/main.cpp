#include "MyQueue.h"

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in original order.
*/
{
    int n;
    double item;
    MyExtendedQueue numbers;

    cout << " Type in an integer n followed by n decimal numbers." << endl
         << " The numbers will be printed in original order." << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> item;
        numbers.append(item);
    }

    cout << endl << endl;

    while (!numbers.isEmpty()) {
        numbers.serve_and_retrieve(item);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
