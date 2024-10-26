#include "MyLinkedQueue.h"

int main() {
    cout << "Please input an integer followed by n chars." << endl;
    MyLinkedQueue Que1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char val;
        cin >> val;
        Que1.append(val);
    }
    MyLinkedQueue Que2(Que1); // 拷贝构造函数
    MyLinkedQueue Que3 = Que1;// 拷贝构造函数的另一种表达
    cout << endl;
    cout << "Print Que1:" << endl;
    for (int i = 0; i < n; i++) {
        char val;
        Que1.retrieve(val);
        Que1.serve();
        cout << val << " ";
    }
    cout << endl;
    cout << "Print Que2:" << endl;
    for (int i = 0; i < n; i++) {
        char val;
        Que2.retrieve(val);
        Que2.serve();
        cout << val << " ";
    }
    cout << endl;
    cout << "Print Que3:" << endl;
    for (int i = 0; i < n; i++) {
        char val;
        Que3.retrieve(val);
        Que3.serve();
        cout << val << " ";
    }
    cout << endl;

    cout << "Please input another integer n followed n chars." << endl;
    MyExtendedLinkedQueue extque1;
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
        char val;
        cin >> val;
        extque1.append(val);
    }
    cout << endl << "extque1_size=" << extque1.size() << endl << endl;
    cout << "Print extque1:" << endl;
    for (int j = 0; j < m; j++) {
        char val;
        extque1.retrieve(val);
        extque1.serve();
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
