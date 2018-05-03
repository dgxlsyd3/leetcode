#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findLHS(vector<int>& nums) 
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		
		int maxLength = 0;
		// pair<数字，这个数字的个数>
		map<int, int> mNums; 
		for (int n : nums) {
			mNums[n]++;
		}

		// 此时mNums已经是按照数字个数有序存储的
		// 找mNums[i]+mNums[i+1]的和最大的两个

		// 从第二个开始遍历
		for (auto it = next(mNums.begin());it!=mNums.end();it++)
		{
			// 前一个元素
			decltype(it) preIt = prev(it);

			// 相差1的两个数字
			if (preIt->first+1 == it->first)
			{
				maxLength = max(maxLength, preIt->second + it->second);
			}
		}

		return maxLength;
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { 1,2,3,4,5,4,5,4 };
	Solution s;
	cout << s.findLHS(nums) << endl;

	return 0;
}
