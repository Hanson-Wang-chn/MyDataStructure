#include "MyStack.h"

template<class Stack_entry>
MyStack<Stack_entry>::MyStack() : count(0) {}

template<class Stack_entry>
bool MyStack<Stack_entry>::empty() const {
    return count == 0;
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::pop() {
    if (count == 0) return underflow;
    count--;
    return success;
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry& item) const {
    if (count == 0) return underflow;
    item = entry[count - 1];
    return success;
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry& item) {
    if (count >= maxstack) return overflow;
    entry[count++] = item;
    return success;
}

template<class Stack_entry>
int MyStack<Stack_entry>::size() const {
    return count;
}
