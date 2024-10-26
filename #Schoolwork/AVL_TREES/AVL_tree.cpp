#include "AVL_tree.h"

// 插入新数据
template <class Record>
Error_code AVL_tree<Record>::insert(const Record &new_data) {
    bool taller; // 树的高度是否增加
    return avl_insert(this->root, new_data, taller);
}

// 插入新数据并保持AVL树的性质
template <class Record>
Error_code AVL_tree<Record>::avl_insert(Binary_node<Record>* &sub_root, const Record &new_data, bool &taller) {
    Error_code result = success;
    if (sub_root == nullptr) {
        sub_root = new AVL_node<Record>(new_data);
        taller = true;
    } else if (new_data == sub_root->data) {
        result = duplicate_error;
        taller = false;
    } else if (new_data < sub_root->data) {
        result = avl_insert(sub_root->left, new_data, taller);
        if (taller) {
            switch (sub_root->get_balance()) {
                case left_higher:
                    left_balance(sub_root);
                    taller = false;
                    break;
                case equal_height:
                    sub_root->set_balance(left_higher);
                    break;
                case right_higher:
                    sub_root->set_balance(equal_height);
                    taller = false;
                    break;
            }
        }
    } else {
        result = avl_insert(sub_root->right, new_data, taller);
        if (taller) {
            switch (sub_root->get_balance()) {
                case left_higher:
                    sub_root->set_balance(equal_height);
                    taller = false;
                    break;
                case equal_height:
                    sub_root->set_balance(right_higher);
                    break;
                case right_higher:
                    right_balance(sub_root);
                    taller = false;
                    break;
            }
        }
    }
    return result;
}

// 左旋操作
template <class Record>
void AVL_tree<Record>::rotate_left(Binary_node<Record> * &sub_root) {
    if (sub_root == nullptr || sub_root->right == nullptr) {
        cout << "警告: 左旋操作时检测到程序错误" << endl;
    } else {
        Binary_node<Record> *right_tree = sub_root->right;
        sub_root->right = right_tree->left;
        right_tree->left = sub_root;
        sub_root = right_tree;
    }
}

// 右旋操作
template <class Record>
void AVL_tree<Record>::rotate_right(Binary_node<Record> * &sub_root) {
    if (sub_root == nullptr || sub_root->left == nullptr) {
        cout << "警告: 右旋操作时检测到程序错误" << endl;
    } else {
        Binary_node<Record> *left_tree = sub_root->left;
        sub_root->left = left_tree->right;
        left_tree->right = sub_root;
        sub_root = left_tree;
    }
}

// 右平衡操作
template <class Record>
void AVL_tree<Record>::right_balance(Binary_node<Record> * &sub_root) {
    Binary_node<Record> * &right_tree = sub_root->right;
    switch (right_tree->get_balance()) {
        case right_higher:
            sub_root->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            rotate_left(sub_root);
            break;
        case equal_height:
            cout << "警告: 右平衡操作时检测到程序错误" << endl;
            break;
        case left_higher:
            Binary_node<Record> *sub_tree = right_tree->left;
            switch (sub_tree->get_balance()) {
                case equal_height:
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(equal_height);
                    break;
                case left_higher:
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(right_higher);
                    break;
                case right_higher:
                    sub_root->set_balance(left_higher);
                    right_tree->set_balance(equal_height);
                    break;
            }
            sub_tree->set_balance(equal_height);
            rotate_right(right_tree);
            rotate_left(sub_root);
            break;
    }
}

// 左平衡操作
template <class Record>
void AVL_tree<Record>::left_balance(Binary_node<Record> * &sub_root) {
    Binary_node<Record> * &left_tree = sub_root->left;
    switch (left_tree->get_balance()) {
        case left_higher:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            rotate_right(sub_root);
            break;
        case equal_height:
            cout << "警告: 左平衡操作时检测到程序错误" << endl;
            break;
        case right_higher:
            Binary_node<Record> *sub_tree = left_tree->right;
            switch (sub_tree->get_balance()) {
                case equal_height:
                    sub_root->set_balance(equal_height);
                    left_tree->set_balance(equal_height);
                    break;
                case right_higher:
                    sub_root->set_balance(equal_height);
                    left_tree->set_balance(left_higher);
                    break;
                case left_higher:
                    sub_root->set_balance(right_higher);
                    left_tree->set_balance(equal_height);
                    break;
            }
            sub_tree->set_balance(equal_height);
            rotate_left(left_tree);
            rotate_right(sub_root);
            break;
    }
}

// 删除节点
template <class Record>
Error_code AVL_tree<Record>::remove(Record &new_data) {
    bool shorter = true; // 树的高度是否减少
    return avl_remove(this->root, new_data, shorter);
}

// 删除节点并保持AVL树的性质
template <class Record>
Error_code AVL_tree<Record>::avl_remove(Binary_node<Record> * &sub_root, Record &new_data, bool &shorter) {
    Error_code result = success;
    Record sub_record;
    if (sub_root == nullptr) {
        shorter = false;
        return not_present;
    } else if (new_data == sub_root->data) {
        Binary_node<Record> *to_delete = sub_root;
        if (sub_root->right == nullptr) {
            sub_root = sub_root->left;
            shorter = true;
            delete to_delete;
            return success;
        } else if (sub_root->left == nullptr) {
            sub_root = sub_root->right;
            shorter = true;
            delete to_delete;
            return success;
        } else {
            to_delete = sub_root->left;
            Binary_node<Record> *parent = sub_root;
            while (to_delete->right != nullptr) {
                parent = to_delete;
                to_delete = to_delete->right;
            }
            new_data = to_delete->data;
            sub_record = new_data;
        }
    }
    if (new_data < sub_root->data) {
        result = avl_remove(sub_root->left, new_data, shorter);
        if (sub_record.the_key() != 0) sub_root->data = sub_record;
        if (shorter) {
            switch (sub_root->get_balance()) {
                case left_higher:
                    sub_root->set_balance(equal_height);
                    break;
                case equal_height:
                    sub_root->set_balance(right_higher);
                    shorter = false;
                    break;
                case right_higher:
                    shorter = right_balance2(sub_root);
                    break;
            }
        }
    }
    if (new_data > sub_root->data) {
        result = avl_remove(sub_root->right, new_data, shorter);
        if (sub_record.the_key() != 0) sub_root->data = sub_record;
        if (shorter) {
            switch (sub_root->get_balance()) {
                case left_higher:
                    shorter = left_balance2(sub_root);
                    break;
                case equal_height:
                    sub_root->set_balance(left_higher);
                    shorter = false;
                    break;
                case right_higher:
                    sub_root->set_balance(equal_height);
                    break;
            }
        }
    }
    return result;
}

// 右平衡操作（删除时）
template <class Record>
bool AVL_tree<Record>::right_balance2(Binary_node<Record> * &sub_root) {
    bool shorter;
    Binary_node<Record> * &right_tree = sub_root->right;
    switch (right_tree->get_balance()) {
        case right_higher:
            sub_root->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            rotate_left(sub_root);
            shorter = true;
            break;
        case equal_height:
            right_tree->set_balance(left_higher);
            rotate_left(sub_root);
            shorter = false;
            break;
        case left_higher:
            Binary_node<Record> *sub_tree = right_tree->left;
            switch (sub_tree->get_balance()) {
                case equal_height:
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(equal_height);
                    break;
                case left_higher:
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(right_higher);
                    break;
                case right_higher:
                    sub_root->set_balance(left_higher);
                    right_tree->set_balance(equal_height);
                    break;
            }
            sub_tree->set_balance(equal_height);
            rotate_right(right_tree);
            rotate_left(sub_root);
            shorter = true;
            break;
    }
    return shorter;
}

// 左平衡操作（删除时）
template <class Record>
bool AVL_tree<Record>::left_balance2(Binary_node<Record> * &sub_root) {
    bool shorter;
    Binary_node<Record> * &left_tree = sub_root->left;
    switch (left_tree->get_balance()) {
        case left_higher:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            rotate_right(sub_root);
            shorter = true;
            break;
        case equal_height:
            left_tree->set_balance(right_higher);
            rotate_right(sub_root);
            shorter = false;
            break;
        case right_higher:
            Binary_node<Record> *sub_tree = left_tree->right;
            switch (sub_tree->get_balance()) {
                case equal_height:
                    sub_root->set_balance(equal_height);
                    left_tree->set_balance(equal_height);
                    break;
                case right_higher:
                    sub_root->set_balance(equal_height);
                    left_tree->set_balance(left_higher);
                    break;
                case left_higher:
                    sub_root->set_balance(right_higher);
                    left_tree->set_balance(equal_height);
                    break;
            }
            sub_tree->set_balance(equal_height);
            rotate_left(left_tree);
            rotate_right(sub_root);
            shorter = true;
            break;
    }
    return shorter;
}