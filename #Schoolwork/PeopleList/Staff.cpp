#include "Staff.h"

// 构造函数的实现
Staff::Staff(string name, int age, string address, string tel, int hourlyWage)
    : Person(name, age, address, tel), hourlyWage(hourlyWage) {}

// 打印员工信息
void Staff::print() const {
    Person::print();
    cout << " Hourly wages: " << hourlyWage << endl;
}

// 获取对象类型
string Staff::getType() const {
    return "Staff";
}

// 获取时薪
int Staff::getHourlyWage() const {
    return hourlyWage;
}
