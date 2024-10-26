#include "Circle.h"

const double pi = 3.14159265359;

// 默认构造函数
Circle::Circle() : radius(0.0), pointX(0.0), pointY(0.0) {}

// 带参数的构造函数
Circle::Circle(float r, float x, float y) : radius(r), pointX(x), pointY(y) {}

// 计算圆的面积
float Circle::area() const {
    return pi * radius * radius; // 使用π*r^2公式计算面积
}

// 计算圆的周长
float Circle::circumference() const {
    return 2 * pi * radius; // 使用2πr公式计算周长
}

// 打印圆的信息
void Circle::print() const {
    std::cout << "radius: " << radius
              << " xPoint: " << pointX
              << " yPoint: " << pointY << std::endl;
    std::cout << "area is: " << area() << std::endl;
    std::cout << "circumference is: " << circumference() << std::endl;
}

// 赋值运算符重载实现
Circle& Circle::operator=(const Circle& other) {
    // 检查自赋值
    if (this == &other) {
        return *this;
    }

    // 复制数据成员
    radius = other.radius;
    pointX = other.pointX;
    pointY = other.pointY;

    return *this;
}