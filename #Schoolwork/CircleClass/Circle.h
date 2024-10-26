#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

// 定义Circle类
struct Circle {
public:
    // 默认构造函数
    Circle();

    // 带参数的构造函数
    Circle(float r, float x, float y);

    // 计算圆的面积
    float area() const;

    // 计算圆的周长
    float circumference() const;

    // 打印圆的信息
    void print() const;

    // 赋值运算符重载
    Circle& operator=(const Circle& other);

private:
    // 圆的半径
    float radius;

    // 圆心的X坐标
    float pointX;

    // 圆心的Y坐标
    float pointY;
};

#endif // CIRCLE_H
