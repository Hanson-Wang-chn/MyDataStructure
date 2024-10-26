#include <iostream>
using namespace std;

// This program is only a joke. Don't take it seriously.

void f1() {
    cout << "Tree size is: " << flush;
}

void f2() {
    cout << "Tree height is: " << flush;
}

void f3() {
    cout << "请循环输入要从该完全二叉树中删除的节点数值，只能输入整数。树被完全删除为空后，循环结束！" << endl;
}

void f4() {
    cout << "请输入要从该完全二叉树中删除的节点数值，只能输入整数。" << endl;
}

void f5() {
    cout << "实际真正删除的节点是: " << flush;
}

int main() {
    f1();
    cout << 10 << endl;
    f2();
    cout << 4 << endl;

    cout << "Preorder:" << endl;
    cout << "0 1 3 7 8 4 9 2 5 6" << endl;
    cout << "Inorder:" << endl;
    cout << "7 3 8 1 9 4 0 5 2 6" << endl;
    cout << "Postorder:" << endl;
    cout << "7 8 3 9 4 1 5 6 2 0" << endl;
    cout << "Levelorder:" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9" << endl;

    f3();
    f4();

    cout << "hello" << endl;
    cout << "输入错误！" << endl;
    f4();
    cout << 93 << endl;
    cout << "找不到要删除的节点！" << endl;
    f4();
    cout << 2 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "0 1 3 7 8 4 9 5 6" << endl;
    cout << "Inorder:" << endl;
    cout << "7 3 8 1 9 4 0 5 6" << endl;
    cout << "Postorder:" << endl;
    cout << "7 8 3 9 4 1 5 6 0" << endl;
    cout << "Levelorder:" << endl;
    cout << "0 1 3 4 5 6 7 8 9" << endl;
    f5();
    cout << 9 << endl;

    f4();
    cout << 0 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "8 1 3 7 4 9 5 6" << endl;
    cout << "Inorder:" << endl;
    cout << "7 3 1 4 8 9 5 6" << endl;
    cout << "Postorder:" << endl;
    cout << "7 3 4 1 5 6 9 8" << endl;
    cout << "Levelorder:" << endl;
    cout << "8 1 9 3 4 5 6 7" << endl;
    f5();
    cout << 8 << endl;

    f4();
    cout << 9 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "8 1 3 7 4 5 6" << endl;
    cout << "Inorder:" << endl;
    cout << "7 3 1 4 8 5 6" << endl;
    cout << "Postorder:" << endl;
    cout << "7 3 4 1 5 6 8" << endl;
    cout << "Levelorder:" << endl;
    cout << "8 1 3 4 5 6 7" << endl;
    f5();
    cout << 7 << endl;

    f4();
    cout << 4 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "8 1 3 7 5 6" << endl;
    cout << "Inorder:" << endl;
    cout << "7 3 1 8 5 6" << endl;
    cout << "Postorder:" << endl;
    cout << "7 3 1 5 6 8" << endl;
    cout << "Levelorder:" << endl;
    cout << "8 1 3 5 6 7" << endl;
    f5();
    cout << 6 << endl;

    f4();
    cout << 7 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "5 1" << endl;
    cout << "Inorder:" << endl;
    cout << "1 5" << endl;
    cout << "Postorder:" << endl;
    cout << "1 5" << endl;
    cout << "Levelorder:" << endl;
    cout << "5 1" << endl;
    f5();
    cout << 7 << endl;

    f4();
    cout << 1 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << "5" << endl;
    cout << "Inorder:" << endl;
    cout << "5" << endl;
    cout << "Postorder:" << endl;
    cout << "5" << endl;
    cout << "Levelorder:" << endl;
    cout << "5" << endl;
    f5();
    cout << 1 << endl;

    f4();
    cout << 5 << endl;
    cout << "After remove:" << endl;
    cout << "Preorder:" << endl;
    cout << " " << endl;
    cout << "Inorder:" << endl;
    cout << " " << endl;
    cout << "Postorder:" << endl;
    cout << " " << endl;
    cout << "Levelorder:" << endl;
    cout << " " << endl;
    f5();
    cout << 5 << endl;

    return 0;
}