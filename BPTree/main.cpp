#include <iostream>
#include <vector>
using namespace std;

// B+树节点的阶数
#define DEGREE 3

class BPTreeNode {
public:
    vector<int> keys; // 关键字数组
    vector<BPTreeNode*> children; // 子节点指针数组
    BPTreeNode* next; // 指向下一个叶子节点
    bool leaf; // 是否是叶子节点

    BPTreeNode(bool leaf);

    void insertNonFull(int k);

    void splitChild(int i, BPTreeNode* y);

    void traverse();

    BPTreeNode* search(int k);
};

class BPTree {
public:
    BPTreeNode* root;

    BPTree() { root = nullptr; }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    BPTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

BPTreeNode::BPTreeNode(bool leaf) {
    this->leaf = leaf;
    next = nullptr;
}

void BPTreeNode::traverse() {
    if (leaf) {
        for (int key : keys)
            cout << key << " ";
        cout << " -> ";
    } else {
        for (size_t i = 0; i < keys.size(); i++) {
            if (i < children.size())
                children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!children.empty())
            children.back()->traverse();
    }
}

BPTreeNode* BPTreeNode::search(int k) {
    if (leaf) {
        for (int key : keys)
            if (key == k)
                return this;
        return nullptr;
    }

    size_t i = 0;
    while (i < keys.size() && k > keys[i])
        i++;
    return children[i]->search(k);
}

void BPTree::insert(int k) {
    if (root == nullptr) {
        root = new BPTreeNode(true);
        root->keys.push_back(k);
    } else {
        if (root->keys.size() == 2 * DEGREE - 1) {
            BPTreeNode* s = new BPTreeNode(false);
            s->children.push_back(root);
            s->splitChild(0, root);

            size_t i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else
            root->insertNonFull(k);
    }
}

void BPTreeNode::insertNonFull(int k) {
    if (leaf) {
        keys.insert(lower_bound(keys.begin(), keys.end(), k), k);
    } else {
        size_t i = 0;
        while (i < keys.size() && k > keys[i])
            i++;
        if (children[i]->keys.size() == 2 * DEGREE - 1) {
            splitChild(i, children[i]);
            if (keys[i] < k)
                i++;
        }
        children[i]->insertNonFull(k);
    }
}

void BPTreeNode::splitChild(int i, BPTreeNode* y) {
    BPTreeNode* z = new BPTreeNode(y->leaf);
    z->keys.assign(y->keys.begin() + DEGREE, y->keys.end());
    y->keys.resize(DEGREE - 1);

    if (!y->leaf) {
        z->children.assign(y->children.begin() + DEGREE, y->children.end());
        y->children.resize(DEGREE);
    }

    if (y->leaf) {
        z->next = y->next;
        y->next = z;
    }

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[DEGREE - 1]);
    y->keys.pop_back();
}

// 测试B+树
int main() {
    BPTree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "遍历B+树:\n";
    t.traverse();
    cout << endl;

    int k = 12;
    (t.search(k) != nullptr) ? cout << "\n找到 " << k : cout << "\n找不到 " << k;

    k = 15;
    (t.search(k) != nullptr) ? cout << "\n找到 " << k : cout << "\n找不到 " << k;

    return 0;
}
