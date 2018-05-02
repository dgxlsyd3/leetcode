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
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t newNumber = 0;
		for (size_t i = 0; i <= 31; i++)
		{
			uint32_t bit = (n >> i) & 1;
			newNumber += (bit << (31 - i) );
		}

		return newNumber;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution s;
	cout << s.reverseBits(2147483648) << endl;

	return 0;
}
