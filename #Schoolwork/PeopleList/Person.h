#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

// 人类的基类
class Person {
protected:
    string name;  // 姓名
    int age;      // 年龄
    string address;  // 地址
    string tel;   // 电话号码

public:
    // 构造函数
    Person(string name, int age, string address, string tel);

    // 打印个人信息
    virtual void print() const;

    // 获取姓名
    string getName() const;

    // 获取年龄
    int getAge() const;

    // 获取地址
    string getAddress() const;

    // 获取电话
    string getTel() const;

    // 获取对象类型
    virtual string getType() const;
};

#endif // PERSON_H
