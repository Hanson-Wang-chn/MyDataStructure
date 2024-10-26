// MyStack.h - This header file contains the declaration of the MyStack class.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#ifndef POLISHCAL_MYSTACK_H
#define POLISHCAL_MYSTACK_H

#include "utility.h"

class MyStack {
/* Pre: None.
   Post: The MyStack class is created with available functions "isEmpty", "isFull", "push", "pop", "peek" and "size".*/

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

#endif //POLISHCAL_MYSTACK_H
