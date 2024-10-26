#ifdef DONE
void Life::initialize() 

/*Pre: 无
  Post: 将用户设定的初始配置载入程序
  Uses: 无*/

{
	int row, col;
	
	for (row = 0; row <= MAX_ROW + 1; row++) { // 全部初始化为0
		for (col = 0; col <= MAX_COL + 1; col++) {
			grid[row][col] = 0;
		}
	}
	
	cout << "List the coordinates for living cells." << endl;
	cout << "Terminate the list with the special pair -1 -1" << endl;
	cin >> row >> col;
	
	while (row != -1 || col != -1) { // 判断行和列是否溢出
		if (row >=1 && row <= MAX_ROW)
			if (col >=1 && col <= MAX_COL)
				grid[row][col] = 1;
		    else
		    	cout << "Column " << col << " is out of range." << endl;
		else
			cout << "Row " << row << " is out of range." << endl;
		cin >> row >> col;			
	}
}
 
void Life::print() 

/*Pre: 游戏配置设置完毕
  Post: 打印配置*/

{
	int row, col;
	cout << "\nThe current Life configuration is:" << endl;
	
	for (row = 1; row <= MAX_ROW; row++) {
		for (col = 1; col <= MAX_COL; col++) {
			if (grid[row][col] == 1) {
				cout << '*';
			}else {
				cout << '-';
			}
		} 
		cout << endl;
	}
	
	cout << endl;		
}
 
void Life::update() 

/*Pre: 游戏配置设置完毕
  Post: 完成下一代配置的生成*/

{
	int row, col;
	int new_grid[MAX_ROW + 2][MAX_COL + 2];
	
	for (row = 1; row <= MAX_ROW; row++) {
		for (col = 1; col <= MAX_COL; col++) {
			switch(neighbor_count(row, col)) { // 核心规则：三活二不变其余死
				case 3:
					new_grid[row][col] = 1; // 周围3个活细胞，成活
					break;
				case 2:
					new_grid[row][col] = grid[row][col]; // 周围2个活细胞，生死状态不变
					break;
				default:
					new_grid[row][col] = 0; // 其余情况，细胞死亡					
			}
		}
	}
			
	for (row = 1; row <= MAX_ROW; row++) {
		for (col = 1; col <= MAX_COL; col++) {
			grid[row][col] = new_grid[row][col];
		}
	}
}
 
int Life::neighbor_count(int row, int col)

/*Pre: 游戏配置设置完毕，且行和列定义了其边界内的一个单元格
  Post: 返回指定细胞活着的邻居数量*/

{
	int i, j;
	int count = 0;
	
	for (i = row - 1; i <= row + 1; i++) {
		for (j = col - 1; j <= col + 1; j++) {
			count += grid[i][j]; // 若邻居为活，计数器加一
		}
	}
	count -= grid[row][col]; // 计数器自减一次，因为之前的统计包含了细胞自己，应当排出	
	
	return count;
}
#endif
