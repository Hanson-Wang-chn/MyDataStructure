//
// Created by 王海生 on 2024/3/14.
//

#ifndef LINKEDSTACK_MYLINKEDSTACK_H
#define LINKEDSTACK_MYLINKEDSTACK_H

#include "utility.h"

struct Stack_Node {
    Stack_Node_entry entry;
    Stack_Node * next;
    Stack_Node();
    Stack_Node(Stack_Node_entry item, Stack_Node * add_on = nullptr);
};

class MyLinkedStack {
public:
    MyLinkedStack();
    bool isEmpty() const;
    Error_code push(const Stack_Node_entry &item);
    Error_code pop();
    Error_code top(Stack_Node_entry &item) const;
    Stack_Node * GetTop() const;
    ~MyLinkedStack();
    MyLinkedStack(const MyLinkedStack &original);
    void operator=(const MyLinkedStack &original);

protected:
    Stack_Node * top_node;
};

#endif //LINKEDSTACK_MYLINKEDSTACK_H
