#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

// 定义学生结构体
struct Student {
    char gender;
    int age;
};

// 读取学生信息
vector<Student> readStudents(const string& filename) {
    ifstream file(filename);
    vector<Student> students;
    if (!file) {
        cerr << "无法打开文件！" << endl; // 文件不存在、文件权限不足等情况
        return students;
    }

    char gender;
    int age;
    while (file >> gender >> age) {
        students.push_back({gender, age});
    }

    return students;
}

// 计算平均年龄
double cal_aver_age(const vector<int>& ages) {
    if (ages.empty()) { // 没有学生的情况
        return 0.0;
    }
    double sum = accumulate(ages.begin(), ages.end(), 0); // 求和
    return sum / ages.size(); // 返回平均值
}

int main() {
    string filename = "/Users/wanghaisheng/Downloads/student.txt"; // 文件路径（Mac）
    vector<Student> students = readStudents(filename);

    if (students.empty()) { // 没有学生的情况
        cerr << "没有学生数据！" << endl;
        return 1;
    }

    vector<int> boys_ages;
    vector<int> girls_ages;
    vector<int> all_ages;

    for (const auto& student : students) { // 遍历每一个学生
        all_ages.push_back(student.age);
        if (student.gender == 'B') {
            boys_ages.push_back(student.age);
        } else if (student.gender == 'G') {
            girls_ages.push_back(student.age);
        }
    }

    double boys_aver = cal_aver_age(boys_ages);
    double girls_aver = cal_aver_age(girls_ages);
    double all_aver = cal_aver_age(all_ages);

    cout << fixed << setprecision(1);  // 保留一位小数
    // 在输出男生平均年龄、女生平均年龄之前分别判断是否为空，以应对单一性别的情况
    if (!boys_ages.empty()) {
        cout << "Average age of boys: " << boys_aver << endl;
    } else {
        cout << "No boys in the list." << endl;
    }

    if (!girls_ages.empty()) {
        cout << "Average age of girls: " << girls_aver << endl;
    } else {
        cout << "No girls in the list." << endl;
    }

    cout << "Average age of all students: " << all_aver << endl;

    return 0;
}