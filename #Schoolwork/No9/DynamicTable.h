//
// Created by 王海生 on 2024/5/15.
//

#ifndef NO9_DYNAMICTABLE_H
#define NO9_DYNAMICTABLE_H

#include "utility.h"

struct Course {
    string id;
    string class_name;
    string instructor;
    string duration;
};

struct Node {
    Course data;
    Node * next;
    Node(Course item, Node * add_on = nullptr);
};

class DynamicTable {
private:
    Node * head;

public:
    DynamicTable();
    Error_code add(const Course a);
    Error_code remove(string name);
    Course * find(string i);
    void print();
};

#endif //NO9_DYNAMICTABLE_H