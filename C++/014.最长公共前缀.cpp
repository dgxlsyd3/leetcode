#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() < 1)
		{
			return "";
		}

		string longestPrefix = "";
		string s0 = strs[0];
		for (size_t i = 1; i <= s0.length(); i++)
		{
			bool found = true;
			string sprefix = s0.substr(0,i);
			for (size_t j = 0; j < strs.size(); j++)
			{
				string str = strs[j];
				if (str.length() < sprefix.length())
				{
					found = false;
					break;
				}

				if (sprefix != str.substr(0, i))
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				longestPrefix = sprefix;
			}
		}

		return longestPrefix;
	}
};

int main(int argc, char* argv[], char* env[])
{
	//cout << "Hello C++." << endl;

	Solution solution;

	vector<string> strs = { "flower","flow","flight","ss" };
	cout << solution.longestCommonPrefix(strs) << endl;

	return 0;
}
