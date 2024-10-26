#include "Binary_tree.h"
#include "MyStack.cpp"

template <class Entry>
Binary_tree<Entry>::Binary_tree() : root(nullptr), count(0) {}

template <class Entry>
bool Binary_tree<Entry>::empty() const {
    return root == nullptr;
}

template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry&)) {
    recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)) {
    if (sub_root != nullptr) {
        (*visit)(sub_root->data);
        recursive_preorder(sub_root->left, visit);
        recursive_preorder(sub_root->right, visit);
    }
}

template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry&)) {
    recursive_inorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)) {
    if (sub_root != nullptr) {
        recursive_inorder(sub_root->left, visit);
        (*visit)(sub_root->data);
        recursive_inorder(sub_root->right, visit);
    }
}

template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry&)) {
    recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry>* sub_root, void (*visit)(Entry&)) {
    if (sub_root != nullptr) {
        recursive_postorder(sub_root->left, visit);
        recursive_postorder(sub_root->right, visit);
        (*visit)(sub_root->data);
    }
}

template <class Entry>
void Binary_tree<Entry>::levelorder(void (*visit)(Entry&)) {
    if (root == nullptr) return;

    MyQueue<Binary_node<Entry>*> queue;
    queue.append(root);

    while (!queue.empty()) {
        Binary_node<Entry>* node;
        queue.serve_and_retrieve(node);
        (*visit)(node->data);
        if (node->left != nullptr) queue.append(node->left);
        if (node->right != nullptr) queue.append(node->right);
    }
}

template <class Entry>
int Binary_tree<Entry>::size() const {
    return count;
}

template <class Entry>
int Binary_tree<Entry>::height() const {
    if (root == nullptr) return 0;

    MyQueue<Binary_node<Entry>*> queue;
    queue.append(root);
    int height = 0;

    while (true) {
        int nodeCount = queue.size();
        if (nodeCount == 0) return height;

        height++;

        while (nodeCount > 0) {
            Binary_node<Entry>* node;
            queue.serve_and_retrieve(node);
            if (node->left != nullptr) queue.append(node->left);
            if (node->right != nullptr) queue.append(node->right);
            nodeCount--;
        }
    }
}

template <class Entry>
void Binary_tree<Entry>::insert(Entry& x) {
    if (empty()) {
        root = new Binary_node<Entry>(x);
        count++;
        return;
    }

    MyStack<int> numbers;
    int item = 0;
    int tmpcount = size();
    while (tmpcount > 0) {
        int a = (tmpcount - 1) / 2;
        int b = (tmpcount - 2) / 2;
        if (tmpcount > 1 && a == b) {
            numbers.push(2); // 2 表示右子节点
        } else {
            numbers.push(1); // 1 表示左子节点
        }
        tmpcount = (tmpcount - 1) / 2;
    }

    Binary_node<Entry>* current = root;
    while (numbers.size() > 1) {
        numbers.top(item);
        if (item == 1) current = current->left;
        if (item == 2) current = current->right;
        numbers.pop();
    }
    numbers.top(item);
    if (item == 1) current->left = new Binary_node<Entry>(x);
    if (item == 2) current->right = new Binary_node<Entry>(x);
    count++;
}

template <class Entry>
bool Binary_tree<Entry>::search(const Entry& x) const {
    return recursive_search(root, x) != nullptr;
}

template <class Entry>
Binary_node<Entry>* Binary_tree<Entry>::recursive_search(Binary_node<Entry>* sub_root, const Entry& x) const {
    if (sub_root == nullptr) return nullptr;
    if (sub_root->data == x) return sub_root;
    Binary_node<Entry>* result = recursive_search(sub_root->left, x);
    if (result != nullptr) return result;
    return recursive_search(sub_root->right, x);
}

template <class Entry>
bool Binary_tree<Entry>::remove(const Entry& x) {
    bool found = false;
    root = recursive_remove(root, x, found);
    if (found) count--;
    return found;
}

template <class Entry>
Binary_node<Entry>* Binary_tree<Entry>::recursive_remove(Binary_node<Entry>* sub_root, const Entry& x, bool& found) {
    if (sub_root == nullptr) return nullptr;

    if (sub_root->data == x) {
        found = true;
        if (sub_root->left == nullptr) {
            Binary_node<Entry>* right = sub_root->right;
            delete sub_root;
            return right;
        }
        if (sub_root->right == nullptr) {
            Binary_node<Entry>* left = sub_root->left;
            delete sub_root;
            return left;
        }

        Binary_node<Entry>* minNode = find_min(sub_root->right);
        sub_root->data = minNode->data;
        sub_root->right = recursive_remove(sub_root->right, minNode->data, found);
    } else {
        sub_root->left = recursive_remove(sub_root->left, x, found);
        if (!found) sub_root->right = recursive_remove(sub_root->right, x, found);
    }
    return sub_root;
}

template <class Entry>
Binary_node<Entry>* Binary_tree<Entry>::find_min(Binary_node<Entry>* sub_root) const {
    while (sub_root->left != nullptr) {
        sub_root = sub_root->left;
    }
    return sub_root;
}
