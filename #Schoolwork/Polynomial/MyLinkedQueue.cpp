//
// Created by 王海生 on 2024/3/16.
//

#include "MyLinkedQueue.h"

Queue_Node::Queue_Node()
// Pre: None
// Post:Creates a new Node object with entry set to a default value and next pointer set to null.
{
    next = nullptr;
}

Queue_Node::Queue_Node(Queue_Node_entry item, Queue_Node *add_on)
// Pre: None
// Post:Creates a new Node object with entry set to the provided item and next pointer set to add_on.
{
    entry = item;
    next = add_on;
}

MyLinkedQueue::MyLinkedQueue()
// Pre: None
// Post:Initializes an empty queue with front and rear pointers set to null.
{
    front = rear = nullptr;
}

Error_code MyLinkedQueue::append(const Queue_entry &item)
// Pre: None
// Post:Appends the provided item to the end of the queue.
{
    Queue_Node * new_rear = new Queue_Node(item);
    if (new_rear == nullptr)
        return overflow;
    if (rear == nullptr) {
        front = rear = new_rear;
    } else {
        rear->next = new_rear;
        rear = new_rear;
    }
    return success;
}

Error_code MyLinkedQueue::serve()
// Pre: The queue is not empty.
// Post:Removes and returns the front element of the queue.
{
    if (front == nullptr)
        return underflow;
    Queue_Node * old_front = front;
    front = old_front->next;
    if (front == nullptr)
        rear == nullptr;
    delete old_front;
    return success;
}

bool MyLinkedQueue::isEmpty() const
// Pre: None
// Post:Returns true if the queue is empty, false otherwise.
{
    return front == nullptr;
//    return rear == NULL;
}

Error_code MyLinkedQueue::retrieve(Queue_entry &item) const
// Pre: The queue is not empty.
// Post:Retrieves the front element of the queue without removing it.
{
    if (front == nullptr)
        return underflow;
    item = front->entry;
    return success;
}

MyLinkedQueue::~MyLinkedQueue()
// Pre: None
// Post:Deallocates memory allocated for the queue.
{
    while (!isEmpty())
        serve();
}

MyLinkedQueue::MyLinkedQueue(const MyLinkedQueue &original) // Copy Constructor
// Pre: None
// Post:Creates a deep copy of the original queue.
{
    Queue_Node * new_copy;
    Queue_Node * original_node = original.front;
    if (original_node == nullptr) {
        rear = front = nullptr;
    } else {
        front = new_copy = new Queue_Node(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Queue_Node(original_node->entry);
            new_copy = new_copy->next;
        }
        rear = new_copy;
    }
}

void MyLinkedQueue::operator=(const MyLinkedQueue &original) // Assignment Operator
// Pre: None
// Post:Assigns the contents of the original queue to the current queue.
{
    Queue_Node * new_copy;
    Queue_Node * original_node = original.front;
    if (original_node == nullptr) {
        rear = front = nullptr;
    } else {
        front = new_copy = new Queue_Node(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Queue_Node(original_node->entry);
            new_copy = new_copy->next;
        }
        rear = new_copy;
    }
    while (!isEmpty()) {
        serve();
    }
}

bool MyExtendedLinkedQueue::isFull() const
// Pre: None
// Post:Returns false since this is a linked queue implementation.
{
    Queue_Node * test_node = new Queue_Node();
    if (test_node == nullptr)
        return true;
    delete test_node;
    return false;
}

int MyExtendedLinkedQueue::size() const
// Pre: None
// Post:Returns the number of elements in the queue.
{
    Queue_Node * window = front;
    int count = 0;
    while (window != nullptr) {
        window = window->next;
        count++;
    }
    return count;
}

void MyExtendedLinkedQueue::clear()
// Pre: None
// Post:Clears all elements from the queue.
{
    while (!isEmpty())
        serve();
}

Error_code MyExtendedLinkedQueue::serve_and_retrieve(Queue_entry &item)
// Pre: None
// Post:Serves and retrieves the front element of the queue.
{
    if (front == nullptr)
        return underflow;
    item = front->entry;
    Queue_Node * old_front = front;
    front = old_front->next;
    if (front == nullptr)
        rear = nullptr;
    delete old_front;
    return success;
}