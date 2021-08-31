#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

vector<int> less_than_10(const vector<int> &vec)
{
	vector<int> nvec;
	for(int index = 0; index < vec.size(); index++)
	{
		if(vec[index] < 10)
		{
			nvec.push_back(vec[index]);
		}
	}
	return nvec;
}

int main(void)
{
	int a1[8] = {1,2,3,4,5,6,7,11};
	vector<int> demo1(a1, a1 + 8);
	vector<int> temp;
	temp = less_than_10(demo1);
	for(int index = 0; index < temp.size(); index++)
	{
		cout << " " << temp[index] << " \n";
	}
	return 0;
}
