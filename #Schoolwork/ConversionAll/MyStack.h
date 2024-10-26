// MyStack.h - This header file contains the declaration of the MyStack class.
// Created by 王海生 on 2024/3/14.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#ifndef CONVERSIONALL_MYSTACK_H
#define CONVERSIONALL_MYSTACK_H

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

#endif //CONVERSIONALL_MYSTACK_H
