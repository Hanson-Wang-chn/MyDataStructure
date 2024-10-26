#include "Student.h"

// 构造函数的实现
Student::Student(string name, int age, string address, string tel, int level, float gpa)
    : Person(name, age, address, tel), level(level), gpa(gpa) {}

// 打印学生信息
void Student::print() const {
    Person::print();
    cout << " Level: " << level << " GPA: " << gpa << endl;
}

// 获取对象类型
string Student::getType() const {
    return "Student";
}

// 获取年级
int Student::getLevel() const {
    return level;
}

// 获取GPA
float Student::getGPA() const {
    return gpa;
}
