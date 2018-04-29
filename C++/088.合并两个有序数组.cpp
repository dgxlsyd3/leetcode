#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {	
		
		int i = 0;
		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); i++)
		{
			// 删除掉m个元素后边的0
			if (i>=m)
			{
				//cout << *it << endl;				
				it = nums1.erase(it);
				// 此处相当于执行了it++

				if (it == nums1.end())
				{
					//cout << "end" << endl;
					break;
				}
			}
			else
			{
				it++;
			}
		}

		for (size_t i = 0; i < n; i++)
		{
			int num = nums2[i];

			bool find = false;
			for (vector<int>::iterator it = nums1.begin(); it!=nums1.end();it++)
			{
				if (*it >= num)
				{
					nums1.insert(it,num);
					find = true;
					break;
				}
			}

			if (!find)
			{
				nums1.insert(nums1.end(),num);
			}
		}
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	
	Solution s;
	s.merge(nums1,3 ,nums2,3);

	return 0;
}
