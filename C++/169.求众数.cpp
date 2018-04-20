/*
����һ����СΪ n �����飬�ҵ����е�������������ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�
����Լ��������Ƿǿյģ����������е�������Զ���ڡ�
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		int N = nums.size() / 2;

		// ǰ��������,�����ǳ��ֵĴ���
		map<int, int> mapNums;
		for (size_t i = 0; i < nums.size(); i++)
		{
			int num = nums[i];

			map<int, int>::iterator it = mapNums.find(num);
			if (it == mapNums.end())
			{
				mapNums[num] = 1;
			}
			else
			{
				mapNums[num] ++;
			}
		}

		// n��һ��pair
		for (auto n : mapNums)
		{
			if (n.second > N)
			{
				//cout << n.first << ":" << n.second << endl;
				return n.first;
			}
		}

		return 0;
	}
};

int main(int argc,char* argv[],char* env[])
{
	vector<int> nums = {1,2,2,4,2,2,3,1,2,3,2};

	Solution solution;
	int n = solution.majorityElement(nums);

	cout << "n=" << n << endl;

    return 0;
}
