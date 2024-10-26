#include <iostream>
#include <fstream>
#include "List.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

using namespace std;

int main() {
    List people;  // 创建人员列表

    // 第一次读取文件
    people.ReadFiles();

    // 第二次读取文件
    people.ReadFiles();

    // 写入文件
    people.WriteFile();

    return 0;
}
