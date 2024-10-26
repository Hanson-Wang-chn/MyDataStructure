//
// Created by 王海生 on 2024/3/13.
//

#ifndef AIRPORT_MYQUEUE_H
#define AIRPORT_MYQUEUE_H

#include "Plane.h"

typedef Plane Data_type;

class MyQueue {
    // This class represents a queue data structure using arrays.
protected:
    Data_type data[MAX_SIZE];
    int count;
    int front; // 指向队头元素
    int rear; // 指向队尾元素

public:
    MyQueue();
    bool isEmpty() const;
    Error_code serve();
    Error_code append(const Data_type &item);
    Error_code retrieve(Data_type &item) const;
};

class MyExtendedQueue : public MyQueue {
public:
    // This class represents an extended queue, inheriting from MyQueue.
    int size() const;
    Error_code serve_and_retrieve(Data_type &item);
    bool isFull() const;
    void clear();
};

#endif //AIRPORT_MYQUEUE_H
