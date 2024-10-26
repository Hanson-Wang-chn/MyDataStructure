//
// Created by 王海生 on 2024/3/14.
//

#include "MyLinkedStack.h"

Stack_Node::Stack_Node()
// Pre: None
// Post:Creates a Node object with default values for entry and next.
{
    next = nullptr;
}

Stack_Node::Stack_Node(Stack_Node_entry item, Stack_Node * add_on)
// Pre: None
// Post:Creates a Node object with the given item and optional add_on pointer.
{
    entry = item;
    next = add_on;
}

MyLinkedStack::MyLinkedStack()
// Pre: None
// Post:Creates an empty MyLinkedStack object with top_node set to NULL.
{
    top_node = nullptr;
}

bool MyLinkedStack::isEmpty() const
// Pre: None
// Post:Returns true if the stack is empty (top_node is NULL), false otherwise.
{
    return top_node == 0;
}

Error_code MyLinkedStack::push(const Stack_Node_entry &item)
// Pre: None
// Post:Inserts a new Node with the provided item at the top of the stack. Returns SUCCESS if successful, otherwise an appropriate error code.
{
    Stack_Node * new_top = new Stack_Node(item, top_node);
    if (new_top == nullptr)
        return overflow;
    top_node = new_top;
    return success;
}

Error_code MyLinkedStack::top(Stack_Node_entry &item) const
// Pre: The stack must not be empty.
// Post:Returns the entry of the top Node in the stack through the parameter item. Returns SUCCESS if successful, otherwise an appropriate error code.
{
    if (top_node == nullptr)
        return underflow;
    item = top_node->entry;
    return success;
}

Error_code MyLinkedStack::pop()
// Pre: The stack is not empty.
// Post:The element at the top of the stack is removed, and the stack's size is decreased by one.
{
    Stack_Node * old_top = top_node;
    if (top_node == nullptr)
        return underflow;
    top_node = old_top->next;
    delete old_top;
    return success;
}

Stack_Node * MyLinkedStack::GetTop() const
// Pre: None
// Post:Returns a pointer to the top Node of the stack. If the stack is empty, returns NULL.
{
    return top_node;
}

MyLinkedStack::~MyLinkedStack()
// Pre: None
// Post:Deallocates memory for all Nodes in the stack and sets top_node to NULL.
{
    while (!isEmpty())
        pop();
}

MyLinkedStack::MyLinkedStack(const MyLinkedStack &original)
// Pre: None
// Post:The MyLinkedStack is initialized as a copy of MyLinkedStack original.
{
    Stack_Node * new_copy = nullptr;
    Stack_Node * original_node = original.top_node;
    if (original_node == nullptr) {
        top_node = nullptr;
    } else {
        top_node = new_copy = new Stack_Node(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Stack_Node(original_node->entry);
            new_copy = new_copy->next;
        }
    }
}

void MyLinkedStack::operator=(const MyLinkedStack &original)
// Pre: None
// Post:The MyLinkedStack is reset as a copy of MyLinkedStack original.
{
    Stack_Node * new_top = nullptr, * new_copy = nullptr;
    Stack_Node * original_node = original.top_node;
    if (original_node == nullptr) {
        new_top = nullptr;
    } else {
        new_copy = new_top = new Stack_Node(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Stack_Node(original_node->entry);
            new_copy = new_copy->next;
        }
    }
    while (!isEmpty()) { // destroy the current stack
        pop();
    }
    top_node = new_top;
}