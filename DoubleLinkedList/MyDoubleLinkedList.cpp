//
// Created by 王海生 on 2024/6/5.
//

#include "MyDoubleLinkedList.h"

template<class Node_entry>
Node<Node_entry>::Node()
{
    next = nullptr;
    back = nullptr;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *list_back, Node<Node_entry> *link_next)
{
    entry = item;
    next = link_next;
    back = list_back;
}

template<class List_entry>
void List<List_entry>::set_position(int position) const
{
    if (current_position <= position) {
        for (; current_position != position; current_position++) {
            current = current->next;
        }
    } else {
        for (; current_position != position; current_position--) {
            current = current->back;
        }
    }
}

template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
    Node<List_entry> *new_node, *following, *preceding;
    if (position < 0 || position > count)
        return Range_error;
    if (position == 0) {
        if (count == 0) {
            following = nullptr;
        } else {
            set_position(0);
            following = current;
        }
        preceding = nullptr;
    } else {
        set_position(position - 1);
        preceding = current;
        following = preceding->next;
    }
    new_node = new Node<List_entry>(x, preceding, following);
    if (new_node == nullptr)
        return overflow;
    if (preceding != nullptr)
        preceding->next = new_node;
    if (following != nullptr)
        following->back = new_node;
    current = new_node;
    current_position = position;
    count++;
    return success;
}