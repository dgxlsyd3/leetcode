#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}

		int arr[20];
		int cnt = 0;
		while (x > 0)
		{
			arr[cnt++] = x % 10;
			x = x / 10;
		}

		for (int i = 0;i < cnt / 2;i++)
		{
			if (arr[i] != arr[cnt -i-1])
			{
				return false;
			}
		}

		return true;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution().isPalindrome(0);
	return 0;
}
