#include <iostream>

using namespace std;

// 树节点结构体
struct TreeNode {
    int val; // 节点值
    TreeNode* left; // 左子树指针
    TreeNode* right; // 右子树指针
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 二叉查找树类
class BST {
public:
    BST() : root(nullptr) {}

    // 插入节点
    void insert(int val) {
        root = insert(root, val);
    }

    // 查找节点
    TreeNode* search(int val) {
        return search(root, val);
    }

    // 删除节点
    void remove(int val) {
        root = remove(root, val);
    }

    // 中序遍历
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // 前序遍历
    void preorder() {
        preorder(root);
        cout << endl;
    }

    // 后序遍历
    void postorder() {
        postorder(root);
        cout << endl;
    }

private:
    TreeNode* root;

    // 插入节点的辅助函数
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val); // 创建新节点
        }
        if (val < node->val) {
            node->left = insert(node->left, val); // 递归插入左子树
        } else {
            node->right = insert(node->right, val); // 递归插入右子树
        }
        return node;
    }

    // 查找节点的辅助函数
    TreeNode* search(TreeNode* node, int val) {
        if (node == nullptr || node->val == val) {
            return node; // 找到节点或到达叶节点
        }
        if (val < node->val) {
            return search(node->left, val); // 递归搜索左子树
        } else {
            return search(node->right, val); // 递归搜索右子树
        }
    }

    // 删除节点的辅助函数
    TreeNode* remove(TreeNode* node, int val) {
        if (node == nullptr) {
            return node; // 没有找到要删除的节点
        }
        if (val < node->val) {
            node->left = remove(node->left, val); // 递归删除左子树中的节点
        } else if (val > node->val) {
            node->right = remove(node->right, val); // 递归删除右子树中的节点
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right; // 只有右子树或无子树
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left; // 只有左子树
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right); // 找到右子树中的最小节点
            node->val = temp->val; // 用右子树中的最小值替换当前节点的值
            node->right = remove(node->right, temp->val); // 删除右子树中的最小值节点
        }
        return node;
    }

    // 找到最小值节点的辅助函数
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left; // 一直向左走找到最小值
        }
        return current;
    }

    // 中序遍历的辅助函数
    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left); // 递归遍历左子树
        cout << node->val << " "; // 输出当前节点值
        inorder(node->right); // 递归遍历右子树
    }

    // 前序遍历的辅助函数
    void preorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->val << " "; // 输出当前节点值
        preorder(node->left); // 递归遍历左子树
        preorder(node->right); // 递归遍历右子树
    }

    // 后序遍历的辅助函数
    void postorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left); // 递归遍历左子树
        postorder(node->right); // 递归遍历右子树
        cout << node->val << " "; // 输出当前节点值
    }
};

// 主函数
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Delete 20\n";
    bst.remove(20);
    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Delete 30\n";
    bst.remove(30);
    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Delete 50\n";
    bst.remove(50);
    cout << "Inorder traversal: ";
    bst.inorder();

    return 0;
}