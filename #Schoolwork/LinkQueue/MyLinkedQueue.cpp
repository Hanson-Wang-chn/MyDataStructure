//
// Created by 王海生 on 2024/3/16.
//

#include "MyLinkedQueue.h"

Node::Node()
// Pre: None
// Post:Creates a new Node object with entry set to a default value and next pointer set to null.
{
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on)
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
    front = rear = NULL;
}

Error_code MyLinkedQueue::append(const Queue_entry &item)
// Pre: None
// Post:Appends the provided item to the end of the queue.
{
    Node * new_rear = new Node(item);
    if (new_rear == NULL)
        return overflow;
    if (rear == NULL) {
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
    if (front == NULL)
        return underflow;
    Node * old_front = front;
    front = old_front->next;
    if (front == NULL)
        rear == NULL;
    delete old_front;
    return success;
}

bool MyLinkedQueue::isEmpty() const
// Pre: None
// Post:Returns true if the queue is empty, false otherwise.
{
    return front == NULL;
//    return rear == NULL;
}

Error_code MyLinkedQueue::retrieve(Queue_entry &item) const
// Pre: The queue is not empty.
// Post:Retrieves the front element of the queue without removing it.
{
    if (front == NULL)
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
    Node * new_copy;
    Node * original_node = original.front;
    if (original_node == NULL) {
        rear = front = NULL;
    } else {
        front = new_copy = new Node(original_node->entry);
        while (original_node->next != NULL) {
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
        }
        rear = new_copy;
    }
}

void MyLinkedQueue::operator=(const MyLinkedQueue &original) // Assignment Operator
// Pre: None
// Post:Assigns the contents of the original queue to the current queue.
{
    Node * new_copy;
    Node * original_node = original.front;
    if (original_node == NULL) {
        rear = front = NULL;
    } else {
        front = new_copy = new Node(original_node->entry);
        while (original_node->next != NULL) {
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
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
    Node * test_node = new Node();
    if (test_node == NULL)
        return true;
    delete test_node;
    return false;
}

int MyExtendedLinkedQueue::size() const
// Pre: None
// Post:Returns the number of elements in the queue.
{
    Node * window = front;
    int count = 0;
    while (window != NULL) {
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
    if (front == NULL)
        return underflow;
    item = front->entry;
    Node * old_front = front;
    front = old_front->next;
    if (front == NULL)
        rear = NULL;
    delete old_front;
    return success;
}