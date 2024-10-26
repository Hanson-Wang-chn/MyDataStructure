#include <iostream>
#include <iomanip> // 引入iomanip库以使用setw方法
using namespace std;

int main() {
    int width, height; // 宽、高
    char inner_letter; // 内部填充的字符

    // 输入宽度和高度
    cout << "please input the width and height:" << endl;
    cin >> width >> height;

    // 输入内部的字符
    cout << "please input the inner letter:" << endl;
    cin >> inner_letter;

    // 输出图形
    cout << setfill('*') << setw(width) << '*' << endl; // 第1行，长度为width的‘*’
    for (int i = 0; i < height - 2; i++)
        // 第2~(height-1)行，中间是长度为(width-2)的inner_letter，两边是'*'
        cout << '*' << setfill(inner_letter) << setw(width - 1) << '*' << endl;
    cout << setfill('*') << setw(width) << '*' << endl; // 第height行，长度为width的‘*’

    return 0;
}
