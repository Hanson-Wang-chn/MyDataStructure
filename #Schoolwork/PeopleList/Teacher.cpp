#include "Teacher.h"

// 构造函数的实现
Teacher::Teacher(string name, int age, string address, string tel, float salary)
    : Person(name, age, address, tel), salary(salary) {}

// 打印教师信息
void Teacher::print() const {
    Person::print();
    cout << " Salary: " << salary << endl;
}

// 获取对象类型
string Teacher::getType() const {
    return "Teacher";
}

// 获取薪水
float Teacher::getSalary() const {
    return salary;
}
