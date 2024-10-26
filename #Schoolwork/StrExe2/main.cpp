#include <iostream>
#include <string>
using namespace std;

int main() {
    const string s1 = "I and li4 and zhang3 and wang2 went to the land yesterday.\
    hello ,world";
    const string s2 = "and";

    auto pos = s1.find(s2);  // 初始化第一个 "and" 的位置
    int cnt = 0; // 计数器
    while (pos != string::npos) {  // 当找到 "and" 时
        cout << ++cnt << ". \"and\" is at position: " << pos << endl; // 使用反斜杠输出双引号
        pos = s1.find(s2, pos + 1);  // 查找下一个 "and" 的位置
    }
    return 0;
}