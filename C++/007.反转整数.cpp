#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int exp(int n)
	{
		int sum = 1;
		while (n > 0)
		{
			sum *= 10;
			n--;
		}

		return sum;
	}

	int reverse(int x)
	{
		int64_t sign = (x > 0 ? 1 : -1);
		vector<int> v;

		if (sign == -1)
		{
			x = sign*x;
		}

		while (x > 0)
		{
			v.push_back(x % 10);
			x = x / 10;
		}

		int64_t sum = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			// cout << v[i] << endl;

			int64_t p = v.size() - i - 1;
			int64_t e = exp(p);
			sum += (v[i] * e);
		}

		int64_t nret = sum*sign;
		if (nret > INT_MAX || nret < INT_MIN)
		{
			nret = 0;
		}

		return nret;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution s;
	cout << s.reverse(123) << endl;

	return 0;
}
