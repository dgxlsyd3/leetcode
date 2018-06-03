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

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int size = nums.size();
		if (size == 0)
		{
			return 0;
		}

		size_t i = 0;
		for (; i < size; i++)
		{
			// 这里巧妙之处在>=
			if (nums[i] >= target)
			{
				return i;
			}
		}

		return i;
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { 1,3,5,6 };
	
	Solution s;
	cout << s.searchInsert(nums, 5) << endl;

	return 0;
}
