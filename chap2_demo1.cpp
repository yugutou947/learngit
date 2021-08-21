//vector version
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool fibon_elem(int pos, int & elem)
{
	//输入检查
	if(pos < 0 || pos > 1024)
	{
		cout << "输入的数不在范围内";
		return false;
	}
	elem = 1;
	int pre = 1;
	int pre_pre = 1;
	for (int index = 3; index <= pos; index++)
	{
		elem = pre + pre_pre;
		pre_pre = pre;
		pre = elem;
	}
	return true;
}
int main()
{
	int elem;
	int pos;
	char flag = 'y';
	
	cout << "请输入你要查询的位置：\n";
	cin >> pos;
	
	while (fibon_elem(pos, elem) && (flag == 'y' || flag == 'Y'))
	{
		cout << "这个位置上的数是:\n"
			 << elem
			 << '\n'
			 << "想继续查询请输入y，想结束请输入n"
			 << endl;
		cin >> flag;
		if(flag == 'y' || flag == 'Y')
		{
			cout << "请输入位置吧";
			cin >> pos;
		}
	} 
	
}

