//
// Created by 王海生 on 2024/3/16.
//

#ifndef LINKEDQUEUE_MYLINKEDQUEUE_H
#define LINKEDQUEUE_MYLINKEDQUEUE_H

#include "utility.h"

struct Node {
    Node_entry entry;
    Node * next;
    Node();
    Node(Node_entry item, Node * add_on = NULL);
};

class MyLinkedQueue {
public:
    MyLinkedQueue();
    bool isEmpty() const;
    Error_code append(const Queue_entry &item);
    Error_code serve();
    Error_code retrieve(Queue_entry &item) const;
    ~MyLinkedQueue();
    MyLinkedQueue(const MyLinkedQueue &original);
    void operator=(const MyLinkedQueue &original);

protected:
    Node * front, * rear;
};

class MyExtendedLinkedQueue : public MyLinkedQueue {
public:
    bool isFull() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};

#endif //LINKEDQUEUE_MYLINKEDQUEUE_H
