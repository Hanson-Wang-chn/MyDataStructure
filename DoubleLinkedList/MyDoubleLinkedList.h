//
// Created by 王海生 on 2024/6/5.
//

#ifndef DOUBLELINKEDLIST_MYDOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_MYDOUBLELINKEDLIST_H

#include "utility.h"

template <class Node_entry>
struct Node {
    Node_entry entry;
    Node<Node_entry> * next;
    Node<Node_entry> * back;
    Node();
    Node(Node_entry item, Node<Node_entry> * list_back = nullptr,
         Node<Node_entry> * link_next = nullptr);
};

template<class List_entry>
class List {
public:
    Error_code insert(int position, const List_entry &x);

protected:
    int count;
    mutable int current_position;
    mutable Node<List_entry> * current;
    void set_position(int position) const;
};

#endif //DOUBLELINKEDLIST_MYDOUBLELINKEDLIST_H
