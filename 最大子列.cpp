#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//���㱩��ѭ��
/*
int maxnumarray(const vector<int> &vec)
{
	int i, j = 0;
	int sum_max = 0;
	int this_sum;
	
	for (i= 0 ; i < vec.size(); i++)
	{
		this_sum = 0;
		for(j = i; j < N; j++)
		{
			this_sum += vec[j];
			if (this_sum > sum_max)
				sum_max = this_sum;
		}
	}
	return sum_max;
}
*/

//̰��
/*
int maxnumarray(const vector<int> &vec)
{
	int N = vec.size();
	int cur_sum = vec[0], max_sum = vec[0];
	for(int index = 1; index < N; ++index)
	{
		cur_sum = cur_sum < 0 ? vec[index] : (vec[index] + cur_sum);
		if(cur_sum > max_sum)
		{
			max_sum = cur_sum;
		}
	} 
	return max_sum;
}
*/

//�ֶ���֮
/*
#define max3(x,y,z) x > y ? (x > z ? x : z) : (y > z ? y : z)   //������ȡ�����

int maxnumarray(vector<int> & nums,int left,int right){
    if(left == right)  return nums[left];

    int mid = (left+right)/2;   //��ԭ���еȷ�
    int lsum = maxnumarray(nums,left,mid); //�ݹ��ȡ��ߵ���������к�
    int rsum = maxnumarray(nums,mid+1,right);//�ݹ��ȡ�ұߵ���������к�
    //�Ի�����Ϊ�����������ɨ�����������ȡ�м����е�������к�
    int lbsum = INT_MIN,rbsum = INT_MIN,tmp = 0;
    for(int i = mid;i >= left;--i){ //����ɨ��
        tmp += nums[i];
        if(tmp > lbsum) lbsum = tmp;
    }tmp = 0;
    for(int i = mid+1;i <= right;++i){//����ɨ��
        tmp += nums[i];
        if(tmp > rbsum) rbsum = tmp;
    }return max3(lsum,rsum,lbsum+rbsum);//�������ߵ����ֵ
}
int maxSubArray3(vector<int> & nums)
{               //�ֶ���֮
    int n = nums.size();
    return maxnumarray(nums,0,n-1);
}
*/

//���ߴ���

int maxnumarray(const vector<int> &vec)
{
	int this_sum = 0;
	int max_sum = 0;
	for( int index = 0; index < vec.size(); index ++){
		this_sum += vec[index];
		if (max_sum < this_sum)
			{
				max_sum = this_sum;
			}
		if (this_sum < 0)
			this_sum = 0;
	}return max_sum;
}


int main()
{
	int max_sum = 0;
	int a[10] = {1, 2, 0, -2, 5, 10, -7, -6, -5, 8};
	int b[5] = {-2, -3, -1, -4, -5};
	vector<int> vec(b, b+5);
	max_sum = maxnumarray(vec);
	cout << max_sum << endl;
}
