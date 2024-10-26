#include "Person.h"

// 构造函数的实现
Person::Person(string name, int age, string address, string tel)
    : name(name), age(age), address(address), tel(tel) {}

// 打印个人信息
void Person::print() const {
    cout << getType() << ": Name: " << name << " Age: " << age << " Address: " << address << " Tel: " << tel << endl;
}

// 获取姓名
string Person::getName() const {
    return name;
}

// 获取年龄
int Person::getAge() const {
    return age;
}

// 获取地址
string Person::getAddress() const {
    return address;
}

// 获取电话
string Person::getTel() const {
    return tel;
}

// 获取对象类型
string Person::getType() const {
    return "Person";
}
