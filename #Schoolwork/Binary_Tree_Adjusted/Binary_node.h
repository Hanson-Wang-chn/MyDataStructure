#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <class Entry>
struct Binary_node {
    Entry data; // 节点存储的数据
    Binary_node<Entry>* left; // 左子节点
    Binary_node<Entry>* right; // 右子节点

    Binary_node(); // 默认构造函数
    Binary_node(const Entry& x); // 使用数据初始化节点的构造函数
};

// template <class Entry>
// Binary_node<Entry>::Binary_node() : left(nullptr), right(nullptr) {}
//
// template <class Entry>
// Binary_node<Entry>::Binary_node(const Entry& x) : data(x), left(nullptr), right(nullptr) {}

#endif // BINARY_NODE_H
