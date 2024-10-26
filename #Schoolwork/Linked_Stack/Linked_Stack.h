//
// Created by 王海生 on 2024/3/14.
//

#ifndef LINKEDSTACK_MYLINKEDSTACK_H
#define LINKEDSTACK_MYLINKEDSTACK_H

#include "utility.h"

struct Node {
    Node_entry entry;
    Node * next;
    Node();
    Node(Node_entry item, Node * add_on = nullptr);
};

class MyLinkedStack {
public:
    MyLinkedStack();
    bool isEmpty() const;
    Error_code push(const Node_entry &item);
    Error_code pop();
    Error_code top(Node_entry &item) const;
    Node * GetTop() const;
    ~MyLinkedStack();
    MyLinkedStack(const MyLinkedStack &original);
    void operator=(const MyLinkedStack &original);

protected:
    Node * top_node;
};

#endif //LINKEDSTACK_MYLINKEDSTACK_H
