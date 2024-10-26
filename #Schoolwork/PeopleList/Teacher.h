#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

// 教师类，继承自人类
class Teacher : public Person {
private:
    float salary;  // 薪水

public:
    // 构造函数
    Teacher(string name, int age, string address, string tel, float salary);

    // 打印教师信息
    void print() const override;

    // 获取对象类型
    string getType() const override;

    // 获取薪水
    float getSalary() const;
};

#endif // TEACHER_H
