//vector version
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool fibon_elem(int pos, int & elem)
{
	//������
	if(pos < 0 || pos > 1024)
	{
		cout << "����������ڷ�Χ��";
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
	
	cout << "��������Ҫ��ѯ��λ�ã�\n";
	cin >> pos;
	
	while (fibon_elem(pos, elem) && (flag == 'y' || flag == 'Y'))
	{
		cout << "���λ���ϵ�����:\n"
			 << elem
			 << '\n'
			 << "�������ѯ������y�������������n"
			 << endl;
		cin >> flag;
		if(flag == 'y' || flag == 'Y')
		{
			cout << "������λ�ð�";
			cin >> pos;
		}
	} 
	
}

