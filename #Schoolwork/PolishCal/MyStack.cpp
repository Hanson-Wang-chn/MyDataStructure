// MyStack.cpp - This file contains the implementation of the MyStack class.
// Created by 王海生 on 2024/3/8.
// Copyright (c) 2024, East China Normal University. All rights reserved.

#include "MyStack.h"

MyStack::MyStack()
/* Pre: None.
   Post: An empty stack is initialized.*/
{
    top = -1;
}

bool MyStack::isEmpty() const
/* Pre: None.
   Post:  Returns true if the stack is empty, false otherwise.*/
{
    return (top == -1);
}

bool MyStack::isFull() const
/* Pre: None.
   Post: Returns true if the stack is full and cannot accommodate more elements, false otherwise.*/
{
    return (top == MAX_SIZE - 1);
}

Error_code MyStack::push(Data_type value)
/* Pre: The stack has available space for a new element.
   Post: The element is added to the top of the stack.*/
{
    if (isFull())
        return overflow;
    data[++top] = value;
    return success;
}

Error_code MyStack::pop(Data_type &value)
/* Pre: The stack is not empty.
   Post: The element at the top of the stack is removed, and the stack's size is decreased by one.*/
{
    if (isEmpty())
        return underflow;
    value = data[top--];
    return success;
}

Error_code MyStack::peek(Data_type &value) const
/* Pre: The stack is not empty.
   Post: The top element of the stack is returned, but the stack remains unchanged.*/
{
    if (isEmpty())
        return underflow;
    value = data[top];
    return success;
}

int MyStack::size() const
/* Pre:
   Post: */
{
    return (top + 1);
}