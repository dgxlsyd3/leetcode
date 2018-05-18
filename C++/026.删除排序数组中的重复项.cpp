#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums) 
	{
		set<int> s;
		for (auto n : nums)
		{
			s.insert(n);
		}
		nums.clear();

		for (auto n : s)
		{
			nums.push_back(n);
		}

		return nums.size();
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	Solution s;
	s.removeDuplicates(nums);

	return 0;
}
