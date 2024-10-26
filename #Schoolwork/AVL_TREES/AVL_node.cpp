#include "AVL_node.h"

// 默认构造函数
template <class Record>
AVL_node<Record>::AVL_node() {
    this->left = nullptr;
    this->right = nullptr;
    balance = equal_height;
}

// 带数据的构造函数
template <class Record>
AVL_node<Record>::AVL_node(const Record &x) {
    this->data = x;
    this->left = nullptr;
    this->right = nullptr;
    balance = equal_height;
}

// 设置平衡因子
template <class Record>
void AVL_node<Record>::set_balance(Balance_factor b) {
    balance = b;
}

// 获取平衡因子
template <class Record>
Balance_factor AVL_node<Record>::get_balance() const {
    return balance;
}