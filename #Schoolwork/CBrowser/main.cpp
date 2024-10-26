//
// Created by 王海生 on 2024/7/8.
//

#include "CBrowser.h"

using namespace std;

void PrintMenu() {
    cout << "请输入浏览器命令：V（访问新网站），F（前进），B（后退），X（退出）" << endl;
}

int main() {
    CBrowser<string> browser; // 创建浏览器对象
    char command;
    string url;

    PrintMenu();
    while (true) {
        // PrintMenu();
        cin >> command;
        switch (command) {
            case 'V':
            case 'v':
                cout << "请输入新的网址：";
            cin >> url;
            browser.NewSite(url);
            cout << "当前网址是：" << browser.GetCurrent()->entry << endl;
            break;
            case 'F':
            case 'f':
                if (browser.Forward()) {
                    cout << "当前网址是：" << browser.GetCurrent()->entry << endl;
                } else {
                    cout << "无法前进！" << endl;
                }
            break;
            case 'B':
            case 'b':
                if (browser.Back()) {
                    cout << "当前网址是：" << browser.GetCurrent()->entry << endl;
                } else {
                    cout << "无法后退！" << endl;
                }
            break;
            case 'X':
            case 'x':
                cout << "退出浏览器。" << endl;
            return 0;
            default:
                // 保证程序健壮性
                cout << "无效命令！" << endl;
        }
    }
}
