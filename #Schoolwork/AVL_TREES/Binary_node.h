#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <iostream>
#include "MyStack.cpp"
using namespace std;

// 平衡因子枚举
enum Balance_factor { left_higher, equal_height, right_higher };

// 二叉树节点结构体
template <class Entry>
struct Binary_node {
    Entry data;                 // 节点数据
    Binary_node<Entry> *left;   // 左子节点指针
    Binary_node<Entry> *right;  // 右子节点指针

    // 构造函数
    Binary_node();
    Binary_node(const Entry &x);

    // 虚拟方法
    virtual void set_balance(Balance_factor b);
    virtual Balance_factor get_balance() const;
};

#endif // BINARY_NODE_H
