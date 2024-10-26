#ifndef LIST_H
#define LIST_H

#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

using namespace std;

// 人员管理类
class List {
private:
    vector<Person*> people;  // 存储人员对象的向量

public:
    // 插入人员对象
    void insert_Person(Person* person);

    // 打印人员列表
    void print_List() const;

    // 读入文件
    void ReadFiles();

    // 写入文件
    void WriteFile();
};

#endif // LIST_H
