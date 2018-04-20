/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ? n/2 ? 的元素。
你可以假设数组是非空的，并且数组中的众数永远存在。
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

		// 前面是数字,后面是出现的次数
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

		// n是一个pair
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
