#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution 
{
public:
	vector<int> plusOne(vector<int>& digits) 
	{	
		// 模拟加法竖式,carry是进位
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int n = digits[i] + carry;
			if (n >= 10)
			{
				carry = 1;
				digits[i] = n % 10;
			}
			else
			{
				carry = 0;
				digits[i] = n;
				break;
			}
		}

		if (carry == 1)
		{
			digits.insert(digits.begin(), 1);
		}
		
		return digits;
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<int> digits = {9,8,9};
	digits = Solution().plusOne(digits);
	for (size_t i = 0; i < digits.size(); i++)
	{
		cout << digits[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}
