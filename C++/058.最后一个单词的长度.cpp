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

class Solution 
{
public:
	int lengthOfLastWord(string s) 
	{
		vector<string> list;

		string word;
		for (auto c : s)
		{
			if (c == ' ')
			{
				if (word != "")
				{
					list.push_back(word);
				}
				word = "";
			}
			else
			{
				word += c;
			}
		}

		if (word != "")
		{
			list.push_back(word);
		}

		return list.size()==0?0:(list[list.size() - 1].length());
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution s;
	cout << s.lengthOfLastWord("") << endl;

	return 0;
}
