#ifdef DONE
void instructions() 
/*Pre: 无
  Post: 打印游戏说明*/
{
	cout << "Welcome to Conway's game of Life." << endl;
	cout << "This game uses a grid of size " << MAX_ROW << " by " << MAX_COL << " in which " << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to the number of neighboring cells which are alive." << endl;
}
 
bool user_says_yes() 

/*Pre: bool类型预置或进行了宏定义
  Post: 判断用户回复，返回对应的布尔值（true对应程序继续，false对应程序终止）
  Uses: 无*/

{
	int c;
	bool initial_response = true;
	
	do { // 持续循环，直到用户输入指定的命令
		if (initial_response) 
			cout << " (y,n)? " << flush; // 刷新输出流，确保文本立即显示
		else
			cout << "Respond with either y or n: " << flush; // 刷新输出流，确保文本立即显示
		do { // 忽略空白字符
			c = cin.get();			
		} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;		
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N'); // 对大小写不敏感
	return(c == 'y' || c == 'Y');
}
#endif
