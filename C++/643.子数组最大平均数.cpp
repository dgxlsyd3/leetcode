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
#include <typeinfo>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		if (nums.size() < k)
		{
			return 0;
		}

		double maxAverage = -10001;
		for (size_t i = 0; i <= nums.size() - k; i++)
		{
			// 滑动窗口
			double sum = 0.0;
			for (size_t j = 0; j < k; j++)
			{
				sum += nums[i + j];
			}

			maxAverage = max(sum/k, maxAverage);
		}

		return maxAverage;
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { -1 };
	
	Solution s;
	cout << s.findMaxAverage(nums,1) << endl;

	return 0;
}
