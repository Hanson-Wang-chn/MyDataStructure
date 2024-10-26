//
// Created by 王海生 on 2024/4/4.
//

#include "MyLinkedList.h"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(DataType item, Node * add_on)
{
    data = item;
    next = add_on;
}

MyLinkedList::MyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

MyLinkedList::MyLinkedList(DataType * arr, int n)
{
    Node * last_node = new Node(arr[n - 1]);
    Node * current = last_node;
    if (n > 1) {
        for (int i = n - 2; i >= 0; i--) {
            current = new Node(arr[i], current);
        }
    }
    if (head == nullptr) {
        head = current;
        tail = last_node;
    } else {
        tail->next = current;
        tail = last_node;
    }
}

Error_code MyLinkedList::insert(int position, DataType value)
{
    Node * new_node = new Node(value);
    if (new_node == nullptr)
        return overflow;
    if (head == nullptr) {
        if (position != 0)
            return failed;
        head = tail = new_node;
    } else if (position == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        Node * current = head;
        int cnt = 1;
        while (current->next != nullptr && cnt < position) {
            current = current->next;
            cnt++;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (cnt < position) // position超出范围
            return failed;
    }
    return success;
}

Error_code MyLinkedList::search(int value, int &position) const
{
    Node * current = head;
    int cnt = 0;
    while (current != nullptr) {
        if (current->data == value) {
            position = cnt;
            return success;
        }
        current = current->next;
        cnt++;
    }
    return failed;
}

Error_code MyLinkedList::delete_value(int value)
{
    Node * current = head;
    Node * prev = nullptr;
    if (current != nullptr && current->data == value) {
        head = current->next;
        delete current;
        if (head->next == nullptr)
            tail = nullptr;
        return success;
    }
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == tail) {
        tail = prev;
        free(current);
        return success;
    } else if (current != nullptr) {
        prev->next = current->next;
        delete current;
        return success;
    }
    return failed;
}

MyLinkedList::~MyLinkedList()
{
    Node * current = head;
    Node * next_node = nullptr;
    while (current != nullptr) {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    tail = nullptr;
}

bool MyExtendedLinkedList::isEmpty() const
{
    return head == nullptr;
}

int MyExtendedLinkedList::size() const
{
    if (head == nullptr)
        return 0;
    Node * current = head;
    int cnt = 0;
    while (current != nullptr) {
        current = current->next;
        cnt++;
    }
    return cnt;
}

Error_code MyExtendedLinkedList::delete_position(int position)
{
    Node * current = head;
    Node * prev = nullptr;
    if (head == nullptr)
        return failed;
    if (head == tail) {
        if (position != 0)
            return failed;
        delete head;
        head = tail = nullptr;
        return success;
    }
    for (int i = 0; i < position; i++) {
        prev = current;
        current = current->next;
        if (current == nullptr)
            return failed;
    }
    prev->next = current->next;
    delete current;
    if (prev->next == nullptr)
        tail = prev;
    return success;
}

Error_code MyExtendedLinkedList::push_head(DataType value)
{
    Node * new_node = new Node(value, head);
    if (new_node == nullptr)
        return overflow;
    head = new_node;
    return success;
}

Error_code MyExtendedLinkedList::append_tail(DataType value)
{
    Node * new_node = new Node(value);
    if (new_node == nullptr)
        return overflow;
    tail->next = new_node;
    tail = new_node;
    return success;
}

Error_code MyExtendedLinkedList::top_or_retrieve_head(DataType &value) const
{
    value = head->data;
    return success;
}

Error_code MyExtendedLinkedList::pop_or_serve_head()
{
    if (head == nullptr)
        return underflow;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node * current = head;
        head = current->next;
        delete current;
    }
    return success;
}

Error_code MyExtendedLinkedList::get_and_delete_head(DataType &value)
{
    if (head == nullptr)
        return underflow;
    value = head->data;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node * current = head;
        head = current->next;
        delete current;
    }
    return success;
}

Error_code MyExtendedLinkedList::get_tail(DataType &value) const
{
    if (tail == nullptr)
        return underflow;
    value = tail->data;
    return success;
}

Error_code MyExtendedLinkedList::delete_tail()
{
    if (tail == nullptr)
        return underflow;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return success;
    }
    Node * current = head;
    Node * prev = nullptr;
    while (current != tail) {
        prev = current;
        current = current->next;
    }
    delete current;
    tail = prev;
    return success;
}

Error_code MyExtendedLinkedList::get_and_delete_tail(DataType &value)
{
    if (tail == nullptr)
        return underflow;
    value = tail->data;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return success;
    }
    Node * current = head;
    Node * prev = nullptr;
    while (current != tail) {
        prev = current;
        current = current->next;
    }
    delete current;
    tail = prev;
    return success;
}