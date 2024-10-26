#include "avl_tree.h"
#include <algorithm> // 为了使用std::max

// 构造函数
AVLTree::AVLTree() : root(nullptr) {}

// 析构函数
AVLTree::~AVLTree() {
    destroy(root);
}

// 获取节点高度
int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

// 获取两个整数中的最大值
int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

// 获取节点的平衡因子
int AVLTree::getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// 右旋转
AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // 执行旋转
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // 返回新的根
    return x;
}

// 左旋转
AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // 执行旋转
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // 返回新的根
    return y;
}

// 递归插入键值
AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 不允许插入重复键值
        return node;

    // 更新高度
    node->height = 1 + max(height(node->left), height(node->right));

    // 获取平衡因子
    int balance = getBalance(node);

    // 平衡调整
    // 左左情况
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // 右右情况
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // 左右情况
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左情况
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 插入键值
void AVLTree::insert(int key) {
    root = insert(root, key);
}

// 获取最小值节点
AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// 递归删除键值
AVLNode* AVLTree::remove(AVLNode* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = remove(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 删除键值
void AVLTree::remove(int key) {
    root = remove(root, key);
}

// 递归搜索键值
bool AVLTree::search(AVLNode* node, int key) {
    if (!node) return false;

    if (key == node->key) return true;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// 搜索键值
bool AVLTree::search(int key) {
    return search(root, key);
}

// 递归销毁节点
void AVLTree::destroy(AVLNode* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
