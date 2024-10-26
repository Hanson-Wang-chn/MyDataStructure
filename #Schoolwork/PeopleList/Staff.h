#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

// 员工类，继承自人类
class Staff : public Person {
private:
    int hourlyWage;  // 时薪

public:
    // 构造函数
    Staff(string name, int age, string address, string tel, int hourlyWage);

    // 打印员工信息
    void print() const override;

    // 获取对象类型
    string getType() const override;

    // 获取时薪
    int getHourlyWage() const;
};

#endif // STAFF_H
