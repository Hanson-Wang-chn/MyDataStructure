//
// Created by 王海生 on 2024/7/8.
//

#ifndef NODE_H
#define NODE_H

#include "utility.h"

template <class Node_entry>
struct Node {
    // data members
    Node_entry entry;
    Node<Node_entry> *next;
    Node<Node_entry> *back;
    // constructors
    Node();
    Node(Node_entry item, Node<Node_entry> *link_back = 0, Node<Node_entry> *link_next = 0);
};

#endif //NODE_H
