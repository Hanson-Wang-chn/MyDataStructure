#include <iostream>
#include "Binary_tree.cpp"
#include "Record.h"

template <class Entry>
void print(Entry &x) {
    std::cout << x;
}

int main() {
    Binary_tree<Record> mytree;
    for (int i = 0; i < 10; i++) {
        Record tmp(i);
        mytree.insert(tmp);
    }

    std::cout << "Tree size is: " << mytree.size() << std::endl;
    std::cout << "Tree height is: " << mytree.height() << std::endl;

    std::cout << "Preorder:" << std::endl;
    mytree.preorder(print);
    std::cout << std::endl;

    std::cout << "Inorder:" << std::endl;
    mytree.inorder(print);
    std::cout << std::endl;

    std::cout << "Postorder:" << std::endl;
    mytree.postorder(print);
    std::cout << std::endl;

    std::cout << "Levelorder:" << std::endl;
    mytree.levelorder(print);
    std::cout << std::endl;

    // 查找节点
    Record search_key(5);
    if (mytree.search(search_key)) {
        std::cout << "节点 5 找到!" << std::endl;
    } else {
        std::cout << "节点 5 未找到!" << std::endl;
    }

    // 删除节点
    while (mytree.size() > 0) {
        std::cout << "请循环输入要从该完全二叉树中删除的节点数值，只能输入整数。树被完全删除为空后，循环结束！" << std::endl;
        int del_key;
        std::cout << "请输入要从该完全二叉树中删除的节点数值，只能输入整数。" << std::endl;
        if (std::cin >> del_key) {
            Record del_record(del_key);
            if (mytree.remove(del_record)) {
                std::cout << "实际真正删除的节点是：" << del_key << std::endl;
                std::cout << "After remove:" << std::endl;
                std::cout << "Preorder:" << std::endl;
                mytree.preorder(print);
                std::cout << std::endl;

                std::cout << "Inorder:" << std::endl;
                mytree.inorder(print);
                std::cout << std::endl;

                std::cout << "Postorder:" << std::endl;
                mytree.postorder(print);
                std::cout << std::endl;

                std::cout << "Levelorder:" << std::endl;
                mytree.levelorder(print);
                std::cout << std::endl;
            } else {
                std::cout << "找不到要删除的节点！" << std::endl;
            }
        } else {
            std::cout << "输入错误！" << std::endl;
            std::cin.clear(); // 清除错误状态
            std::cin.ignore(INT_MAX, '\n'); // 清除输入缓冲区
        }
    }

    return 0;
}