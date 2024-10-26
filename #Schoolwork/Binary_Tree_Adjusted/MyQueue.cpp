#include<iostream>
#include"MyQueue.h"

template<class Queue_entry>
MyQueue<Queue_entry>::MyQueue() : count(0), front(0), rear(0) {}

template<class Queue_entry>
bool MyQueue<Queue_entry>::empty() const {
    return count == 0;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::append(const Queue_entry& item) {
    if (count >= maxqueue) return overflow;
    entry[rear++] = item;
    count++;
    return success;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve() {
    if (count <= 0) return underflow;
    front++;
    count--;
    return success;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::retrieve(Queue_entry& item) const {
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

template<class Queue_entry>
int MyQueue<Queue_entry>::size() const {
    return count;
}

template<class Queue_entry>
bool MyQueue<Queue_entry>::full() const {
    return count == maxqueue;
}

template<class Queue_entry>
void MyQueue<Queue_entry>::clear() {
    count = 0;
    front = 0;
    rear = 0;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve_and_retrieve(Queue_entry& item) {
    if (count <= 0) return underflow;
    item = entry[front++];
    count--;
    return success;
}
