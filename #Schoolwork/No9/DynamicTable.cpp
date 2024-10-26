//
// Created by 王海生 on 2024/5/15.
//

#include "DynamicTable.h"

Node::Node(Course item, Node * add_on)
{
    data.id = item.id;
    data.duration = item.duration;
    data.instructor = item.instructor;
    data.class_name = item.class_name;
    next = add_on;
}

DynamicTable::DynamicTable()
{
    head = nullptr;
}

Error_code DynamicTable::add(const Course a)
{
    Node * new_node = new Node(a, head);
    if (new_node == nullptr)
        return overflow;
    head = new_node;
    return success;
}

Error_code DynamicTable::remove(string name)
{
    // 第一个元素是要找的元素
    if (head->data.class_name == name) {
        Node * temp = head->next;
        delete head;
        head = temp;
        return success;
    }

    // 第一个元素不是要找的元素
    Node * current = head;
    Node * prev = current;
    while(1) {
        current = current->next;
        if (current == nullptr) // 完全遍历链表，未查找到元素
            return failed;
        if (current->data.class_name == name) { // 找到元素并删除
            prev->next = current->next;
            delete current;
            return success;
        }
        prev = current;
    }
}

Course * DynamicTable::find(string i)
{
    Node * current = head;
    while (current->data.id != i) {
        current = current->next;
    }
    return &(current->data);
}

void DynamicTable::print()
{
    Node * current = head;
    while (1) {
        cout << current->data.id << "\t" << current->data.class_name << "\t"
        << current->data.duration << "\t" << current->data.instructor << endl;
        current = current->next;
        if (current == nullptr)
            break;
    }
}