#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

// 学生类，继承自人类
class Student : public Person {
private:
    int level;  // 年级
    float gpa;  // GPA

public:
    // 构造函数
    Student(string name, int age, string address, string tel, int level, float gpa);

    // 打印学生信息
    void print() const override;

    // 获取对象类型
    string getType() const override;

    // 获取年级
    int getLevel() const;

    // 获取GPA
    float getGPA() const;
};

#endif // STUDENT_H
