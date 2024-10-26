#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "Search_tree.cpp"

// AVL树类定义
template <class Record>
class AVL_tree : public Search_tree<Record> {
public:
    // 插入和删除操作
    Error_code insert(const Record &new_data);
    Error_code remove(Record &old_data);

private:
    // 辅助函数原型
    Error_code avl_insert(Binary_node<Record> *&sub_root, const Record &new_data, bool &taller);
    void rotate_left(Binary_node<Record> *&sub_root);
    void rotate_right(Binary_node<Record> *&sub_root);
    void right_balance(Binary_node<Record> *&sub_root);
    void left_balance(Binary_node<Record> *&sub_root);

    // 用于删除的辅助函数
    Error_code avl_remove(Binary_node<Record> *&sub_root, Record &new_data, bool &shorter);
    bool right_balance2(Binary_node<Record> *&sub_root);
    bool left_balance2(Binary_node<Record> *&sub_root);
};

#endif // AVL_TREE_H

