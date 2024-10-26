#include "NewString.h"

// 默认构造函数
String::String() {
    length = 0;
    entries = new char[1];
    entries[0] = '\0';
}

// 析构函数
String::~String() {
    delete[] entries;
}

// 拷贝构造函数
String::String(const String &copy) {
    length = copy.length;
    entries = new char[length + 1];
    strcpy(entries, copy.entries);
}

// 从C字符串转换的构造函数
String::String(const char *copy) {
    length = strlen(copy);
    entries = new char[length + 1];
    strcpy(entries, copy);
}

// 赋值运算符重载
void String::operator=(const String &copy) {
    if (this != &copy) {
        delete[] entries;
        length = copy.length;
        entries = new char[length + 1];
        strcpy(entries, copy.entries);
    }
}

// 从C字符串赋值的重载
void String::operator=(const char *copy) {
    delete[] entries;
    length = strlen(copy);
    entries = new char[length + 1];
    strcpy(entries, copy);
}

// 转换为C风格字符串
const char *String::c_str() const {
    return entries;
}

// 获取字符串长度
int String::get_length() const {
    return length;
}

// 设置字符串长度
void String::set_length(int x) {
    length = x;
}

// 设置字符串内容
void String::set_entries(char *new_entries) {
    entries = new_entries;
}

// 获取字符串内容
char* String::get_entries() const {
    return entries;
}

// 比较运算符重载
bool operator==(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) == 0;
}

bool operator>(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) > 0;
}

bool operator<(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) < 0;
}

bool operator>=(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) >= 0;
}

bool operator<=(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) <= 0;
}

bool operator!=(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) != 0;
}

// 字符串连接函数
void strcat(String &add_to, const String &add_on) {
    char *new_entries = new char[add_to.get_length() + add_on.get_length() + 1];
    strcpy(new_entries, add_to.c_str());
    strcat(new_entries, add_on.c_str());
    delete[] add_to.get_entries();
    add_to.set_entries(new_entries);
    add_to.set_length(add_to.get_length() + add_on.get_length());
}

// 字符串相加操作符重载
String operator+(const String &first, const String &second) {
    String result;
    result.set_length(first.get_length() + second.get_length());
    result.set_entries(new char[result.get_length() + 1]);
    strcpy(result.get_entries(), first.c_str());
    strcat(result.get_entries(), second.c_str());
    return result;
}

// 查找子字符串函数
int strstr(const String &text, const String &target) {
    const char *pos = std::strstr(text.c_str(), target.c_str());
    return (pos) ? pos - text.c_str() : -1;
}

// 从输入流读取字符串内容
String String::read_in(istream &input) {
    // 临时存储字符列表
    string temp;
    char c;
    // 从输入流中读取字符，直到遇到换行符或EOF
    while (input.peek() != '\n' && input.peek() != EOF) {
        c = input.get();
        temp += c;
    }
    // 创建String对象并返回
    return String(temp.c_str());
}

// 输出字符串函数
void write(String &s) {
    cout << s << endl;
}

// 输出操作符重载
ostream &operator<<(ostream &output, const String &s) {
    output << s.c_str();
    return output;
}
