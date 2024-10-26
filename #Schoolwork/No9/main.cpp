#include "DynamicTable.h"

bool read_csv_row(ifstream& file, Course& data) {
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string cell;
        if (getline(ss, cell, ','))
            data.id = cell;
        if (getline(ss, cell, ','))
            data.class_name = cell;
        if (getline(ss, cell, ','))
            data.duration = cell;
        if (getline(ss, cell, ','))
            data.instructor = cell;
        return true;
    }
    return false;
}

void addCourse(DynamicTable& table, const Course& course)
{
    table.add(course);
}

bool removeCourse(DynamicTable& table, const std::string& courseName)
{
    Error_code ret = table.remove(courseName);
    if (ret == success)
        return true; // 返回true表示删除成功
    return false; // 返回false表示删除失败
}

Course * getCourse(DynamicTable& table, string index)
{
    Course * course = table.find(index);
    return course;
}

int main() {
    DynamicTable whs_love_sj;

    ifstream file("/Users/wanghaisheng/Desktop/courses.csv");
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }

    string header;
    getline(file, header); // 读取并跳过第一行数据

    Course course;
    while (1) {
        if (read_csv_row(file, course) == true) {
            whs_love_sj.add(course);
        } else
            break;
    }

    whs_love_sj.print(); // 输出csv文件中的内容
    cout << endl << endl;

    Course course1;
    course1.id = "1001";
    course1.class_name = "LearningAlgorithm";
    course1.duration = "60.00";
    course1.instructor = "Mr Jin";
    addCourse(whs_love_sj, course1);
    whs_love_sj.print();
    cout << endl << endl;

    removeCourse(whs_love_sj, "Lemke Inc");
    whs_love_sj.print();
    cout << endl << endl;

    Course * course2 = getCourse(whs_love_sj, "3");
    cout << course2->id << "\t" << course2->class_name << "\t"
    << course2->duration << "\t" << course2->instructor << endl;

    return 0;
}