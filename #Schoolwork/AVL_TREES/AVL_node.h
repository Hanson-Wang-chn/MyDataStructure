#ifndef AVL_NODE_H
#define AVL_NODE_H

#include "Binary_node.cpp"

// 平衡因子枚举
//enum Balance_factor { left_higher, equal_height, right_higher };

// AVL树节点结构体
template <class Record>
struct AVL_node : public Binary_node<Record> {
    Balance_factor balance; // 节点的平衡因子

    // 构造函数
    AVL_node();
    AVL_node(const Record &x);

    // 设置平衡因子
    void set_balance(Balance_factor b);

    // 获取平衡因子
    Balance_factor get_balance() const;
};

#endif // AVL_NODE_H
