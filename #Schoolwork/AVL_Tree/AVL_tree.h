#include "Search_tree.cpp"

template <class Record>
class AVL_tree: public Search_tree<Record> {
public:
    Error_code insert(const Record &new_data);
    Error_code remove(Record &old_data);
private: // Add auxiliary function prototypes here.
    Error_code avl_insert(Binary_node<Record> * &sub_root, const Record &new_data, bool &taller);
    void rotate_left(Binary_node<Record> * &sub_root);
    void rotate_right(Binary_node<Record> * &sub_root);
    void right_balance(Binary_node<Record> * &sub_root);
    void left_balance(Binary_node<Record> * &sub_root);
    //add for remove
    Error_code avl_remove(Binary_node<Record> * &sub_root, Record &new_data, bool &shorter);
    bool right_balance2(Binary_node<Record> * &sub_root);
    bool left_balance2(Binary_node<Record> * &sub_root);
};
