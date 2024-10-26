template <class Record>
Error_code AVL_tree<Record> :: insert(const Record &new_data)
/* Post: If the key of new data is already in the AVL tree , a code of duplicate_error is returned. Otherwise, a code of success is returned and the Record new data is inserted into the tree in such a way that the properties of an AVL tree are preserved.
Uses: avl_insert . */
{
    bool taller; // Has the tree grown in height?
    return avl_insert(root, new_data, taller);
    //向root中插入一个新节点new_data.
    //taller表示插入是否使得以root为根的树高度增加。
}

template <class Record>
Error_code AVL_tree<Record> :: avl_insert(Binary_node<Record> * &sub_root,  const Record &new_data, bool &taller) {
    Error_code result = success;
    if (sub_root == NULL) {
        sub_root = new AVL_node<Record>(new_data);
        taller = true;
    } else if (new_data == sub_root->data) {
        result = duplicate_error;
        taller = false;
    } else if (new_data < sub_root->data) { // Insert in left subtree.
        result = avl_insert(sub_root->left, new_data, taller);
        if (taller == true)
            switch (sub_root->get_balance( )) { // Change balance factors.
                case left_higher:
                    left_balance(sub_root);
                    taller = false; // Rebalancing always shortens the tree.
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
    else { // Insert in right subtree.
        result = avl_insert(sub_root->right, new_data, taller);
        if (taller == true)
            switch (sub_root->get_balance( )) {
                case left_higher:
                    sub_root->set_balance(equal_height);
                    taller = false;
                    break;
                case equal_height:
                    sub_root->set_balance(right_higher);
                    break;
                case right_higher:
                    right_balance(sub_root);
                    taller = false; // Rebalancing always shortens the tree.
                    break;
            }
    }
    return result;
}

template <class Record>
void AVL_tree<Record> :: rotate_left(Binary_node<Record> * &sub_root)
/* Pre: sub_root points to a subtree of the AVL tree . This subtree has a nonempty right subtree.
Post: sub_root is reset to point to its former right child, and the former sub_root node is the left child of the new sub_root node. */
{
    if (sub_root == NULL || sub_root->right == NULL) // impossible cases
        cout << "WARNING: program error detected in rotate left" << endl;
    else {
        Binary_node<Record> *right_tree = sub_root->right;
        sub_root->right = right_tree->left;
        right_tree->left = sub_root;
        sub_root = right_tree;
    }
}

template <class Record>
void AVL_tree<Record> :: rotate_right(Binary_node<Record> * &sub_root)
/* Pre: sub_root points to a subtree of the AVL tree . This subtree has a nonempty
left subtree.
Post: sub_root is reset to point to its former left child, and the former sub_root
node is the right child of the new sub_root node. */
{
    if (sub_root == NULL || sub_root->left == NULL) // impossible cases
        cout << "WARNING: program error detected in rotate right" << endl;
    else {
        Binary_node<Record> *left_tree = sub_root->left;
        sub_root->left = left_tree->right;
        left_tree->right = sub_root;
        sub_root = left_tree;
    }
}

template <class Record>
void AVL_tree<Record> :: right_balance(Binary_node<Record> * &sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
    Binary_node<Record> * &right_tree = sub_root->right;
    switch (right_tree->get_balance( )) {
        case right_higher: // single rotation left
            sub_root->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            rotate_left(sub_root);
            break;
        case equal_height: // impossible case because taller == true
            cout << "WARNING: program error in right balance" << endl;
        case left_higher: // double rotation left
            Binary_node<Record> *sub_tree = right_tree->left;
            switch (sub_tree->get_balance( )) {
                case equal_height:
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(equal_height);
                    break;
                case left_higher: //T2 is h, T3 is h-1
                    sub_root->set_balance(equal_height);
                    right_tree->set_balance(right_higher);
                    break;
                case right_higher: //T2 is h-1, T3 is h
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

template <class Record>
void AVL_tree<Record> :: left_balance(Binary_node<Record> * &sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the left.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
    Binary_node<Record> * &left_tree = sub_root->left;
    switch (left_tree->get_balance( )) {
        case left_higher: // single rotation left
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            rotate_right(sub_root);
            break;
        case equal_height: // impossible case
            cout << "WARNING: program error in right balance" << endl;
        case right_higher: // double rotation left
            Binary_node<Record> *sub_tree = left_tree->right;
            switch (sub_tree->get_balance( )) {
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