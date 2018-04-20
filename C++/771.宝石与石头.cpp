#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int count = 0;

		for (size_t i = 0; i < J.length(); i++)
		{
			char jChar = J[i];
			for (size_t j = 0; j < S.length(); j++)
			{
				char sChar = S[j];
				if (jChar == sChar)
				{
					count++;
				}
			}
		}

		return count;
	}
};

int main(int argc, char* argv[], char* env[])
{
	string J = "aA", S = "aAAbbbb";

	Solution solution;
	int n = solution.numJewelsInStones(J, S);

	cout << "n=" << n << endl;

	return 0;
}
