#include <iostream>
#include "AVL_tree.cpp"
#include "Record.h"

using namespace std;

// 打印函数模板
template <class Entry>
void print(Entry &x) {
    cout << x;
}

int main() {
    AVL_tree<Record> mytree;
    cout << "请输入要插入AVL树的节点数值，只能输入整数。当输入-1时结束输入。" << endl;

    int a;
    // 循环输入节点值并插入AVL树
    while (true) {
        cin >> a;
        if (a == -1)
            break;
        else
            mytree.insert(Record(a));
    }

    // 输出树的不同遍历结果
    cout << "AVL树生产完成，下面分别输出其前序，中序，后序。" << endl;
    cout << "Preorder:" << endl;
    mytree.preorder(print);
    cout << endl;

    cout << "Inorder:" << endl;
    mytree.inorder(print);
    cout << endl;

    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl << endl;

    cout << "请输入要从该AVL树中删除的节点数值，只能输入整数。" << endl;
    int b;
    cin >> b;

    cout << "AVL树进行删除给定节点后，其前序，中序，后序。" << endl;
    Record tmp(b);
    mytree.remove(tmp);

    cout << "Preorder:" << endl;
    mytree.preorder(print);
    cout << endl;

    cout << "Inorder:" << endl;
    mytree.inorder(print);
    cout << endl;

    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl << endl;

    cout << "实际上借位删除的是:" << flush;
    cout << tmp.the_key();
    cin.get();

    return 0;
}
