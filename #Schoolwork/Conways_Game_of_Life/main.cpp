// 作者：王海生（学号：10235101559）
// 版本：2024年3月1日 1.0
// 参考资料：《Data Structures and Program Design in C++》
//			"https://blog.csdn.net/howard2005/article/details/79294248"

#include "utility.h"
int main() // 运行Conway's game of Life的程序

/*Pre: 用户提供活细胞的初始布局
  Post: 该程序打印一系列图片，展示细胞配置的变化过程
  Uses: 依赖于类“Life”，其中的方法“initialize(), print(), update()”，以及函数
        “instructions(); user_says_yes()”*/
        
{
	Life configuration;
	instructions();
	configuration.initialize();	
	configuration.print();
	cout << "Continue viewing new generations? " << endl;
	while (user_says_yes()) { // 根据用户命令继续改编细胞配置或退出程序
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations? " << endl;
	}
 
	return 0;
}
