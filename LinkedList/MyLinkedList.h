//
// Created by 王海生 on 2024/4/4.
//

#ifndef LINKEDLIST_MYLINKEDLIST_H
#define LINKEDLIST_MYLINKEDLIST_H

#include "utility.h"

struct Node {
    DataType data;
    Node * next;
    Node();
    Node(DataType item, Node * add_on = nullptr);
};

class MyLinkedList {
protected:
    Node * head;
    Node * tail;

public:
    MyLinkedList();
    MyLinkedList(DataType * arr, int n);
    Error_code insert(int position, DataType value);
    Error_code search(int value, int &position) const;
    Error_code delete_value(int value);
    ~MyLinkedList();
};

class MyExtendedLinkedList : public MyLinkedList {
    bool isEmpty() const;
    int size() const;
    Error_code delete_position(int position);
    Error_code push_head(DataType value);
    Error_code append_tail(DataType value);
    Error_code top_or_retrieve_head(DataType &value) const;
    Error_code pop_or_serve_head();
    Error_code get_and_delete_head(DataType &value);
    Error_code get_tail(DataType &value) const;
    Error_code delete_tail();
    Error_code get_and_delete_tail(DataType &value);
};

#endif //LINKEDLIST_MYLINKEDLIST_H