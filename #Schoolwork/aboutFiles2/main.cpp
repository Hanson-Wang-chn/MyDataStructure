#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

// 统计字母出现的次数
void countLetters(const string &filename) {
    ifstream file(filename);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    // 初始化一个map来统计字母出现次数，a-z
    map<char, int> cnt_letter;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        cnt_letter[ch] = 0;
    }

    // 统计总字符数
    int cnt_total = 0;
    char c;

    // 读取文件内容，统计字母出现次数和总字符数
    while (file.get(c)) {
        cnt_total++;
        if (isalpha(c)) { // 判断是否为字母
            c = tolower(c); // 转换为小写
            cnt_letter[c]++; // 统计字母
        }
    }

    file.close();

    // 检查文件是否为空
    if (cnt_total == 0) {
        cout << "文件为空或未包含任何字符。" << endl;
        return;
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        double percentage = (cnt_letter[ch] * 100.0) / cnt_total;
        cout << ch << " " << percentage << "%" << endl;
    }
}

int main() {
    string filepath = "/Users/wanghaisheng/Downloads/input.txt"; // 文件路径
    countLetters(filepath);

    return 0;
}