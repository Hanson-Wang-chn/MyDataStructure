#include "AVL_node.cpp"

template <class Entry>
// 二叉树节点类
class Binary_tree {
public:
	Binary_tree( );
	bool empty( ) const;
	void preorder(void (*visit)(Entry &));
	void inorder(void (*visit)(Entry &));
	void postorder(void (*visit)(Entry &));
	int size( ) const;
	int height( ) const;
	void insert(Entry &);
protected:
	void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
	Binary_node<Entry> *root;
    int count;
};

//#ifndef BINARY_NODE_H
//#define BINARY_NODE_H
//
//#include "AVL_node.cpp"
//
//// 二叉树节点结构体
//template <class Entry>
//class Binary_node {
//public:
//    Entry data;                 // 节点数据
//    Binary_node<Entry> *left;   // 左子节点指针
//    Binary_node<Entry> *right;  // 右子节点指针
//
//    // 构造函数
//    Binary_node();
//    Binary_node(const Entry &x);
//
//    // 虚拟方法
//    virtual void set_balance(Balance_factor b);
//    virtual Balance_factor get_balance() const;
//};
//
//#endif // BINARY_NODE_H
