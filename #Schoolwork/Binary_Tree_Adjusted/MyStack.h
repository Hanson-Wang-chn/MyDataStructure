#ifndef MYSTACK_H
#define MYSTACK_H

#include "utility.h"

template<class Stack_entry>
class MyStack {
public:
    MyStack();
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry& item) const;
    Error_code push(const Stack_entry& item);
    int size() const;

private:
    int count;
    Stack_entry entry[maxstack];
};

// #include "MyStack.cpp"

#endif // MYSTACK_H
