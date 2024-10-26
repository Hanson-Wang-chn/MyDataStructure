//
// Created by 王海生 on 2024/3/7.
//

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include "utility.h"

class MyStack {
private:
    Data_type data[MAX_SIZE];
    int top;

public:
    MyStack();
    bool isEmpty() const;
    bool isFull() const;
    Error_code push(Data_type value);
    Error_code pop(Data_type &value);
    Error_code peek(Data_type &value) const;
    int size() const;
};

#endif //STACK_MYSTACK_H
