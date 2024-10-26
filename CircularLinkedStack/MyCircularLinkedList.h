//
// Created by 王海生 on 2024/4/5.
//

#ifndef CIRCULARLINKEDSTACK_MYCIRCULARLINKEDLIST_H
#define CIRCULARLINKEDSTACK_MYCIRCULARLINKEDLIST_H

#include "utility.h"

struct Node {
    DataType data;
    Node * next;
    Node();
    Node(DataType item, Node * add_on = nullptr);
};

class MyCircularLinkedList {
protected:
    Node * head;

public:
    MyCircularLinkedList();
    Error_code insert(int position, DataType value);
    Error_code search(int value, int &position) const;
    Error_code delete_value(int value);
    Error_code delete_position(int position);
    bool isEmpty() const;
    int size() const;
    Error_code push_head(DataType value);
    Error_code append_tail(DataType value);
    Error_code get_head(DataType &value) const;
    Error_code delete_head();
    Error_code get_tail(DataType &value) const;
    Error_code delete_tail();
};

#endif //CIRCULARLINKEDSTACK_MYCIRCULARLINKEDLIST_H