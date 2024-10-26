#include <iostream>
#include <fstream>
#include <vector>
#include "Circle.h"

int main() {
    // 定义存储圆的vector
    std::vector<Circle> circles;

    // 打开包含圆信息的文件
    std::ifstream infile("/Users/wanghaisheng/Downloads/infomation.txt");

    // 无法打开文件的情况
    if (!infile) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    float radius, x, y;

    // 读取文件中的每一行
    while (infile >> radius >> x >> y) {
        // 创建Circle对象并添加到vector中
        circles.emplace_back(radius, x, y);
    }

    // 关闭文件
    infile.close();

    // 打印所有圆的信息
    for (const auto& circle : circles) {
        circle.print();
        std::cout << std::endl;

        // 测试运算符重载
        Circle circle_cpy = circle;
        circle_cpy.print();
        std::cout << std::endl << std::endl;
    }

    return 0;
}
