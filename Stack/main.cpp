#include <iostream>
#include "MyStack.h"

int main() {
    using namespace std;

    MyStack stack;

    cout << "isEmpty: " << stack.isEmpty() << endl;
    cout << "size: " << stack.size() << endl;

    cout << "push: ";
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        Error_code temp = stack.push(i * 10);
        cout << temp << " ";
    }
    cout << endl;

    cout << "isEmpty: " << stack.isEmpty() << endl;
    cout << "isFull: " << stack.isFull() << endl;
    cout << "size: " << stack.size() << endl;

    stack.push((MAX_SIZE - 1) * 10);

    cout << "isFull: " << stack.isFull() << endl;
    cout << "size: " << stack.size() << endl;

    Error_code temp = stack.push(MAX_SIZE * 10);
    cout << "push: " << temp << endl;

    Data_type value1, value2, value3, value4;

    stack.peek(value1);
    cout << "top: " << value1 << endl;
    cout << "isFull: " << stack.isFull() << endl;
    cout << "size: " << stack.size() << endl;
    stack.peek(value2);
    cout << "top: " << value2 << endl;

    stack.pop(value3);
    cout << "pop: " << value3 << endl;
    cout << "isFull: " << stack.isFull() << endl;
    cout << "size: " << stack.size() << endl;
    stack.pop(value4);
    cout << "pop: " << value4 << endl;
    cout << "size: " << stack.size() << endl;

    return 0;
}
