#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
	int thirdMax(vector<int>& nums)
	{
		// set 是有序的
		set<int> max3;
		for (auto i : nums)
		{
			max3.insert(i);
			if (max3.size()>3)
			{
				max3.erase(max3.begin());
			}
		}

		if (max3.size() == 3)
		{
			return *max3.begin();
		}
		else
		{
			return *max3.rbegin();
		}
	}
};

int main()
{
	vector<int> nums = { 1,4,5,2,2,5 };
	Solution s;
	cout << s.thirdMax(nums) << endl;

	return 0;
}
