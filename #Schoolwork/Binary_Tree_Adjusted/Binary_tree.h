#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// #include "Binary_node.h"
// #include "MyQueue.h"

#include "Binary_node.cpp"

template <class Entry>
class Binary_tree {
public:
    Binary_tree(); // 构造函数
    bool empty() const; // 判断树是否为空
    void preorder(void (*visit)(Entry&)); // 前序遍历
    void inorder(void (*visit)(Entry&)); // 中序遍历
    void postorder(void (*visit)(Entry&)); // 后序遍历
    void levelorder(void (*visit)(Entry&)); // 层序遍历
    int size() const; // 获取树的大小
    int height() const; // 获取树的高度
    void insert(Entry& x); // 插入节点
    bool search(const Entry& x) const; // 查找节点
    bool remove(const Entry& x); // 删除节点

protected:
    void recursive_preorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)); // 递归前序遍历
    void recursive_inorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)); // 递归中序遍历
    void recursive_postorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)); // 递归后序遍历
    Binary_node<Entry>* recursive_search(Binary_node<Entry>* sub_root, const Entry& x) const; // 递归查找节点
    Binary_node<Entry>* recursive_remove(Binary_node<Entry>* sub_root, const Entry& x, bool& found); // 递归删除节点
    Binary_node<Entry>* find_min(Binary_node<Entry>* sub_root) const; // 查找最小节点

    Binary_node<Entry>* root; // 树的根节点
    int count; // 树的节点数量
};

#include "Binary_tree.cpp"

#endif // BINARY_TREE_H
