//
// Created by 王海生 on 2024/7/8.
//

#include "Node.h"

// 缺省构造函数，初始化指针为nullptr
template <class Node_entry>
Node<Node_entry>::Node() : entry(Node_entry()), next(nullptr), back(nullptr) {}

// 带参数的构造函数，初始化节点的值和指针
template <class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *link_back, Node<Node_entry> *link_next)
    : entry(item), next(link_next), back(link_back) {}

// 显式实例化模板
template struct Node<std::string>;
