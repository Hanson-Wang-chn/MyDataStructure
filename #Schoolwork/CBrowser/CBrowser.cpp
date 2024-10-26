//
// Created by 王海生 on 2024/7/8.
//

#include "CBrowser.h"

// 缺省构造函数，初始化当前指针为nullptr
template <class Node_entry>
CBrowser<Node_entry>::CBrowser() : current(nullptr) {}

// 析构函数，释放所有节点内存
template <class Node_entry>
CBrowser<Node_entry>::~CBrowser() {
    while (current) {
        Node<Node_entry> *temp = current->back;
        delete current;
        current = temp;
    }
}

// 判断是否可以前进
template <class Node_entry>
bool CBrowser<Node_entry>::CanForward() {
    return current != nullptr && current->next != nullptr;
}

// 前进一个节点
template <class Node_entry>
bool CBrowser<Node_entry>::Forward() {
    if (CanForward()) {
        current = current->next;
        return true;
    }
    return false;
}

// 判断是否可以后退
template <class Node_entry>
bool CBrowser<Node_entry>::CanBack() {
    return current != nullptr && current->back != nullptr;
}

// 后退一个节点
template <class Node_entry>
bool CBrowser<Node_entry>::Back() {
    if (CanBack()) {
        current = current->back;
        return true;
    }
    return false;
}

// 插入新的网站到当前节点后面
template <class Node_entry>
void CBrowser<Node_entry>::NewSite(Node_entry site) {
    Node<Node_entry> *new_node = new Node<Node_entry>(site, current, nullptr);
    if (current) {
        if (current->next) {
            // 释放当前节点之后的所有节点
            Node<Node_entry> *temp = current->next;
            while (temp) {
                Node<Node_entry> *next = temp->next;
                delete temp;
                temp = next;
            }
        }
        current->next = new_node;
    }
    current = new_node;
}

// 获取当前节点
template <class Node_entry>
Node<Node_entry> *CBrowser<Node_entry>::GetCurrent() {
    return current;
}

// 显式实例化模板
template class CBrowser<std::string>;
