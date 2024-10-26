#ifndef NEWSTRING_H
#define NEWSTRING_H

#include <cstring>
#include <iostream>

using namespace std;

class String {
public:
    // 默认构造函数
    String();
    // 析构函数
    ~String();
    // 拷贝构造函数
    String(const String &copy);
    // 从C字符串转换的构造函数
    String(const char *copy);
    // 赋值运算符重载
    void operator=(const String &copy);
    // 从C字符串赋值的重载
    void operator=(const char *copy);
    // 转换为C风格字符串
    const char *c_str() const;

    // 获取字符串长度
    int get_length() const;

    // 设置字符串长度
    void set_length(int x);

    // 设置字符串内容
    void set_entries(char *new_entries);

    // 获取字符串内容
    char* get_entries() const;

    // 从输入流读取字符串内容
    static String read_in(istream &input);

protected:
    char *entries; // 字符串内容
    int length; // 字符串长度
};

// 比较运算符重载
bool operator==(const String &first, const String &second);
bool operator>(const String &first, const String &second);
bool operator<(const String &first, const String &second);
bool operator>=(const String &first, const String &second);
bool operator<=(const String &first, const String &second);
bool operator!=(const String &first, const String &second);

// 字符串连接函数
void strcat(String &add_to, const String &add_on);
// 字符串相加操作符重载
String operator+(const String &first, const String &second);

// 查找子字符串函数
int strstr(const String &text, const String &target);
// 输出字符串函数
void write(String &s);
// 输出操作符重载
ostream &operator<<(ostream &output, const String &s);

#endif // NEWSTRING_H
