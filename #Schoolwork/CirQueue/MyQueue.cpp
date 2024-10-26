//
// Created by 王海生 on 2024/3/19.
//

#include "MyQueue.h"

MyQueue::MyQueue()
// Pre: None
// Post: Creates an empty queue.
{
    count = 0;
    front = 0;
    rear = MAX_SIZE - 1;
}

bool MyQueue::isEmpty() const
// Pre: None
// Post: Returns true if the queue is empty, false otherwise.
{
    return count == 0;
}

Error_code MyQueue::serve()
// Pre: The queue is not empty.
// Post: Removes and returns the front element of the queue. If the queue is empty, returns an error code indicating underflow.
{
    if (count <= 0)
        return underflow;
    count--;
    front = ((front + 1) == MAX_SIZE) ? 0 : (front + 1);
//    front = (front + 1) % MAX_SIZE;
    return success;
}

Error_code MyQueue::append(const Data_type &item)
// Pre: None
// Post: Appends the given item to the end of the queue. Returns an error code indicating overflow if the queue is full.
{
    if (count >= MAX_SIZE)
        return overflow;
    count++;
    rear = ((rear + 1) == MAX_SIZE) ? 0 : (rear + 1);
//    rear = (rear + 1) % MAX_SIZE;
    data[rear] = item;
    return success;
}

Error_code MyQueue::retrieve(Data_type &item) const
// Pre: None
// Post: Retrieves the front element of the queue and stores it in the parameter item. Returns an error code indicating underflow if the queue is empty.
{
    if (count <= 0)
        return underflow;
    item = data[front];
    return success;
}

int MyExtendedQueue::size() const
// Pre: None
// Post: Returns the number of elements in the queue.
{
    return count;
}

Error_code MyExtendedQueue::serve_and_retrieve(Data_type &item)
// Pre: None
// Post: Combines the serve and retrieve operations, removing and returning the front element of the queue while also storing it in the parameter item. Returns an error code indicating underflow if the queue is empty.
{
    if (count <= 0)
        return underflow;
    item = data[front];
    count--;
    front = ((front + 1) == MAX_SIZE) ? 0 : (front + 1);
//    front = (front + 1) % MAX_SIZE;
    return success;
}

bool MyExtendedQueue::isFull() const
// Pre: None
// Post: Returns true if the queue is full, false otherwise.
{
    return count == MAX_SIZE;
}

void MyExtendedQueue::clear()
// Pre: None
// Post: Removes all elements from the queue, leaving it empty.
{
    while (!isEmpty()) {
        serve();
    }
}