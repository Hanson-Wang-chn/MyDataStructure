#include "Linked_Stack.h"

int main() {
    MyLinkedStack numbers;
    int n;
    cout << "Please input an integer n followed by n decimal numbers." << endl;
    cin >> n;
    check_stream(n);

    double item;
    for (int i = 0; i < n; i++) {
        cin >> item;
        check_stream(item);
        numbers.push(item);
    }

    cout << endl << "Result: " << endl;
    while (!numbers.isEmpty()) {
        numbers.top(item);
        cout << item << " ";
        numbers.pop();
    }
    cout << endl;

    return 0;
}
