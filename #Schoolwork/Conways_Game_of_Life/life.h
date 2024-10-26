#define MAX_ROW 20 // 定义二维数组行数
#define MAX_COL 60 // 定义二维数组列数
 
class Life {
public:
	void initialize();
	void print();
	void update();
private:
	int grid[MAX_ROW + 2][MAX_COL + 2]; // 设置栅栏
	int neighbor_count(int row, int col);
};
 
#define DONE // 用于标识本段定义已被加载
#include "life.cpp"
