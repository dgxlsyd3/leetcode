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

using namespace std;

class Solution 
{
public:
	vector<int> selfDividingNumbers(int left, int right) 
	{
		vector<int> v;
		for (int n = left; n <= right; n++)
		{
			bool isself = true;
			
			int num = n;
			while (num > 0)
			{
				int remainder = num % 10;
				num = num / 10;

				if (remainder == 0)
				{
					isself = false;
					continue;
				}

				if (n % remainder != 0)
				{
					isself = false;
				}
			}

			if (isself)
			{
				v.push_back(n);
			}
		}

		return v;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution solution;
	vector<int> v = solution.selfDividingNumbers(1,22);

	for (auto x: v)
	{
		cout << x << endl;
	}

	return 0;
}
