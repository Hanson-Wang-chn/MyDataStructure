#include "MyCircularLinkedList.h"

int main() {
    int n, m, start;
    cout << "This is a YSF(n,m) problem." << endl
        << "Please input the integer n(n>=1)." << flush;
    cin >> n;
    check_stream(n);
    cout << "Please input the integer m(m>=1)." << flush;
    cin >> m;
    check_stream(m);
    cout << endl;
    start = m;

    Node * last_node = new Node(n);
    Node * new_node = last_node;
    for (int i = n - 1; i >= 1; i--) { // 构建循环链表
        Node * temp = new Node(i, new_node);
        new_node = temp;
    }
    last_node->next = new_node;

    Node * start_position = new_node; // 确定开始位置
    for (int j = 0; j < start - 2; j++) {
        start_position = start_position->next;
    }

    Node * current = start_position; // 正在寻找的位置
    Node * old_node = nullptr; // 上一个找到的位置
    Node * old_prev = nullptr; // 上一个找到的位置的前一个位置，用于链表删除操作
    for (int k = 0; k < n - 1; k++) { // 遍历链表，直到剩下最后一个元素
        old_prev = current;
        old_node = old_prev->next;
        for (int p = 0; p < m; p++) {
            current = current->next;
        }
        int x = old_node->data;
        cout << "Get rid of:" << x << endl;
        old_prev->next = old_node->next;
        delete old_node;
    }

    int x = old_prev->data; // 最后一个元素
    delete old_prev;
    cout << "The left element is:" << x << endl
    << "Press any key to quit." << flush;
    cin.get();
    cin.get();

    return 0;
}
