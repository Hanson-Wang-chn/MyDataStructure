#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int letters = 0, spaces = 0, digits = 0, others = 0; // 分别统计字母、空格、数字和其他字符的个数

    cout << "Enter one line: " << endl;
    getline(cin, input); // 获取输入的一整行字符并存储到input中

    // 遍历输入字符串中的每个字符
    for(char c : input) {
        if (isalpha(c)) { // 判断字符是否是字母
            letters++; // 如果是字母，字母计数加1
        } else if (isspace(c)) { // 判断字符是否是空格
            spaces++; // 如果是空格，空格计数加1
        } else if (isdigit(c)) { // 判断字符是否是数字
            digits++; // 如果是数字，数字计数加1
        } else { // 如果既不是字母、空格，也不是数字
            others++; // 则认为是其他字符，其他字符计数加1
        }
    }

    // 输出统计结果
    cout << "letter:" << letters << ", space:" << spaces << ", digit:" << digits << ", other:" << others << endl;

    return 0;
}
