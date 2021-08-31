#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred)
{
	while ((first = find_if(first, last, bind2nd(pred, val))) != last)
	{
		cout << "value is:" << *first << "\n";
		*at = *first;
		at++;
		first++;
	}
	return at;
} 

int main()
{
	const int max = 8;
	int ia[max] = {1,2,3,4,5,6,7,8};
	vector<int>ivec(ia, ia+8);
	
	int ia2[max];
	vector<int>ivec2(max);
	
	filter(ia, ia+8, ivec2.begin(), 5, less<int>());
	cout << "flag" << endl;
	for(int index = 0; index < ivec2.size(); index++)
	{
		cout << " " << ivec2[index] << " \n";
	}
}
