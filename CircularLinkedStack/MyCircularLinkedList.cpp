//
// Created by 王海生 on 2024/4/5.
//

#include "MyCircularLinkedList.h"

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

MyCircularLinkedList::MyCircularLinkedList()
// Pre: None
// Post: Creates an empty circular linked list with head pointing to nullptr
{
    Node * new_node = new Node();
    head = new_node;
    head->next = head;
}

Error_code MyCircularLinkedList::insert(int position, DataType value)
// Pre: position is a valid index (0 <= position <= size())
//      value is the data to be inserted
// Post: Inserts the value into the circular linked list at the specified position
//       Returns SUCCESS if successful, otherwise returns appropriate error code
{
    Node * current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    Node * new_node = new Node(value, current->next);
    if (new_node == nullptr)
        return overflow;
    current->next = new_node;
    return success;
}

Error_code MyCircularLinkedList::search(int value, int &position) const
// Pre: None
// Post: Searches for the given value in the circular linked list
//       If found, sets position to the index of the value (0-based), otherwise sets position to -1
//       Returns SUCCESS if value is found, otherwise returns appropriate error code
{
    Node * current = head->next;
    int cnt = 1;
    while (current != head && current->data != value) {
        current = current->next;
        cnt++;
    }
    if (current == head)
        return failed;
    position = cnt;
    return success;
}

Error_code MyCircularLinkedList::delete_value(int value)
// Pre: None
// Post: Deletes the first occurrence of the specified value from the circular linked list
//       Returns SUCCESS if value is deleted successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    Node * prev = head;
    while (current != head && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == head)
        return failed;
    prev->next = current->next;
    delete current;
    return success;
}

Error_code MyCircularLinkedList::delete_position(int position)
// Pre: position is a valid index (0 <= position < size())
// Post: Deletes the element at the specified position from the circular linked list
//       Returns SUCCESS if element is deleted successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    Node * prev = head;
    for (int i = 0; i < position - 1; i++) {
        prev = current;
        current = current->next;
    }
    if (current == head)
        return failed;
    prev->next = current->next;
    delete current;
    return success;
}

bool MyCircularLinkedList::isEmpty() const
// Pre: None
// Post: Returns true if the circular linked list is empty, false otherwise
{
    return head == head->next;
}

int MyCircularLinkedList::size() const
// Pre: None
// Post: Returns the size (number of elements) of the circular linked list
{
    Node * current = head;
    int cnt = 0;
    while (current->next != head) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

Error_code MyCircularLinkedList::push_head(DataType value)
// Pre: None
// Post: Inserts the specified value at the beginning of the circular linked list
//       Returns SUCCESS if value is inserted successfully, otherwise returns appropriate error code
{
    Node * new_node = new Node(value, head->next);
    if (new_node == nullptr)
        return overflow;
    head->next = new_node;
    return success;
}

Error_code MyCircularLinkedList::append_tail(DataType value)
// Pre: None
// Post: Appends the specified value at the end of the circular linked list
//       Returns SUCCESS if value is appended successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    Node * prev = head;
    while (current != head) {
        prev = current;
        current = current->next;
    }
    Node * new_node = new Node(value, head);
    if (new_node == nullptr)
        return overflow;
    prev->next = new_node;
    return success;
}

Error_code MyCircularLinkedList::get_head(DataType &value) const
// Pre: None
// Post: Retrieves the value stored at the head of the circular linked list
//       Stores the retrieved value in the 'value' parameter
//       Returns SUCCESS if value is retrieved successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    if (current == head)
        return failed;
    value = current->data;
    return success;
}

Error_code MyCircularLinkedList::delete_head()
// Pre: None
// Post: Deletes the element at the head of the circular linked list
//       Returns SUCCESS if head element is deleted successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    if (current == head)
        return underflow;
    head->next = current->next;
    delete current;
    return success;
}

Error_code MyCircularLinkedList::get_tail(DataType &value) const
// Pre: None
// Post: Retrieves the value stored at the tail of the circular linked list
//       Stores the retrieved value in the 'value' parameter
//       Returns SUCCESS if value is retrieved successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    Node * prev = head;
    if (current == head)
        return failed;
    while (current != head) {
        prev = current;
        current = current->next;
    }
    value = prev->data;
    return success;
}

Error_code MyCircularLinkedList::delete_tail()
// Pre: None
// Post: Deletes the element at the tail of the circular linked list
//       Returns SUCCESS if tail element is deleted successfully, otherwise returns appropriate error code
{
    Node * current = head->next;
    Node * prev = head;
    if (current == head)
        return underflow;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }
    prev->next = head;
    delete current;
    return success;
}