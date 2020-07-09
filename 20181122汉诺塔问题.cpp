/*
*程序名：汉诺塔问题
*作者：何卓远
*编制时间：2018-11-22
*功能：

*/
#include <iostream>

using namespace std;
void moveOneDisk(char from, char to)
{
	cout << from << "->" << to << endl;
}
void moveNDisks(int disks, char from, char to, char via)
{
	if (disks == 1)
		cout << from << "->" << to << endl;
	else
	{
		moveNDisks(disks - 1, from, via, to);
		cout << from << "->" << to << endl;
		moveNDisks(disks - 1, via, to, from);
	}
}

int main()
{
	int diskNumber;
	cin >> diskNumber;
	moveNDisks(diskNumber, 'A', 'C', 'B');
	return 0;   //程序结束
}