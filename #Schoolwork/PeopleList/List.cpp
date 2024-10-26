#include "List.h"

void check_stream() {
    if (std::cin.fail()) {
        std::cin.clear();  // 清除错误状态
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略当前输入行
        std::cout << "发现输入流挂起，这一整行忽略，流重新复位" << std::endl;
    }
}

// 插入人员对象
void List::insert_Person(Person* person) {
    people.push_back(person);
    // 按照姓名排序
    sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getName() < b->getName();
    });
}

// 打印人员列表
void List::print_List() const {
    for (const auto& person : people) {
        person->print();
    }
}

// 读取文件
void List::ReadFiles() {
    string filename;
    cout << "请输入读取的文件名: " << endl;
    while (cin >> filename) {
        ifstream infile(filename);

        // // 如果无法打开文件，要求重新输入文件名
        // if (!infile.is_open()) {
        //     cout << "无法打开文件 " << filename << ", 请重新输入: " << endl;
        //     continue;
        // }

        // 如果无法打开文件，直接停止读取
        if (!infile.is_open()) {
            cout << "无法打开文件" << endl;
            break;
        }

        string line;
        while (getline(infile, line)) {
            istringstream iss(line);
            char type;
            string name, address, tel;
            int age, level, hourlyWage;
            float gpa, salary;

            if (!(iss >> type >> name >> address >> tel >> age)) { // 输入流挂起时自动复位
                cout << "发现输入流挂起，这一整行忽略，流重新复位" << endl;
                infile.clear();
                infile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else if (!(type == 'P' || type == 'S' || type == 'T' || type == 'E' ||
                type == 'p' || type == 's' || type == 't' || type == 'e')) { // 类型不合规时忽略整行
                cout << "发现不可识别的类型" << type << "，这一整行忽略" << endl;
                infile.clear();
                infile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (type) {
                case 'P':
                    insert_Person(new Person(name, age, address, tel));
                    break;
                case 'S':
                    if (iss >> level >> gpa)
                        insert_Person(new Student(name, age, address, tel, level, gpa));
                    else
                        cout << "学生输入错误，跳过此行: " << line << endl;
                    break;
                case 'T':
                    if (iss >> salary)
                        insert_Person(new Teacher(name, age, address, tel, salary));
                    else
                        cout << "教师输入错误，跳过此行: " << line << endl;
                    break;
                case 'E':
                    if (iss >> hourlyWage)
                        insert_Person(new Staff(name, age, address, tel, hourlyWage));
                    else
                        cout << "员工输入错误，跳过此行: " << line << endl;
                    break;
            }
        }

        infile.close();
        break; // 成功读取后退出循环
    }
}

// 写入到文件
void List::WriteFile() {
    string filename;
    cout << "请输入要输出的文件名: " << endl;
    cin >> filename;
    ofstream outfile;
    // 使用 app 模式，如果文件存在，则追加写入；否则创建新文件并写入
    outfile.open(filename, ios::out | ios::app);
    if (!outfile.is_open()) {
        cout << "无法打开文件 " << filename << endl;
        return;
    }

    // 按照姓名排序
    sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getName() < b->getName();
    });

    for (const auto& person : people) {
        outfile << person->getType() << ": ";
        outfile << "Name: " << person->getName() << " Age: " << person->getAge() << " Address: " << person->getAddress() << " Tel: " << person->getTel() << " ";

        if (Student* stu = dynamic_cast<Student*>(person)) {
            outfile << "Level: " << stu->getLevel() << " GPA: " << stu->getGPA() << endl;
        } else if (Teacher* tea = dynamic_cast<Teacher*>(person)) {
            outfile << "Salary: " << tea->getSalary() << endl;
        } else if (Staff* sta = dynamic_cast<Staff*>(person)) {
            outfile << "Hourly wages: " << sta->getHourlyWage() << endl;
        } else {
            outfile << endl;
        }
    }

    outfile.close();
}
