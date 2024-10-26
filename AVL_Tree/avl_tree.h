#ifndef AVL_TREE_H
#define AVL_TREE_H

// 定义节点结构
struct AVLNode {
    int key; // 节点的键值
    AVLNode *left; // 左子节点指针
    AVLNode *right; // 右子节点指针
    int height; // 节点的高度

    // 构造函数
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// AVL树类定义
class AVLTree {
public:
    AVLTree(); // 构造函数
    ~AVLTree(); // 析构函数

    void insert(int key); // 插入键值
    void remove(int key); // 删除键值
    bool search(int key); // 搜索键值

private:
    AVLNode* root; // 树的根节点指针

    // 辅助函数
    int height(AVLNode* node); // 获取节点高度
    int max(int a, int b); // 获取两个整数中的最大值
    int getBalance(AVLNode* node); // 获取节点的平衡因子
    AVLNode* rightRotate(AVLNode* y); // 右旋转
    AVLNode* leftRotate(AVLNode* x); // 左旋转
    AVLNode* insert(AVLNode* node, int key); // 递归插入键值
    AVLNode* remove(AVLNode* node, int key); // 递归删除键值
    AVLNode* minValueNode(AVLNode* node); // 获取最小值节点
    void destroy(AVLNode* node); // 递归销毁节点
    bool search(AVLNode* node, int key); // 递归搜索键值
};

#endif // AVL_TREE_H