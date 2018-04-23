#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/two-sum/description/

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;

		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
				}
			}
		}

		return ret;
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	Solution solution;
	vector<int> v = solution.twoSum(nums, target);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
