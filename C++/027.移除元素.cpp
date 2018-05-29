#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		for (auto it = nums.begin(); it != nums.end();)
		{
			if (val == *it)
			{
				// 典型的迭代器失效问题
				it = nums.erase(it);
				if (it == nums.end())
				{
					break;
				}
			}
			else
			{
				it++;
			}
		}

		return nums.size();
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
	cout << Solution().removeElement(nums, 2) << endl;
	return 0;
}
