#include "NewString.h"
#include <iostream>

using namespace std;

int main() {
    // 从C字符串转换
    String s1 = "s1 string";
    cout << s1.c_str() << endl; // 转换为C风格字符串
    cout << s1 << endl; // 使用 << 操作符
    cout << strlen(s1.c_str()) << endl;

    // 拷贝构造函数
    String s2("s2 string");
    cout << s2.c_str() << endl;
    cout << s2 << endl;
    cout << strlen(s2.c_str()) << endl;

    // 字符串相加
    cout << s1 + s2 << endl;

    // 比较运算符
    if (s1 >= s2)
        cout << "s1 >= s2" << endl;
    else
        cout << "s1 < s2" << endl;

    // 赋值运算符
    s2 = s1;
    if (s1 == s2)
        cout << "s1 = s2" << endl;
    else
        cout << "s1 != s2" << endl;

    // 从C字符串转换
    String s3 = "s3 string";
    // 字符串连接
    strcat(s3, s1);
    write(s3);

    // 查找子字符串
    String text = "This is text.";
    String target = "text";
    cout << strstr(text, target) << endl;

    // 从输入流读取字符串
    cout << "请输入一个字符串：" << endl;
    String input_string = String::read_in(cin);
    cout << "你输入的字符串是：" << endl << input_string << endl;

    cin.get();
    return 0;
}
