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
#include <typeinfo>

using namespace std;

// #pragma pack(1)

class Solution 
{
public:
	string licenseKeyFormatting(string S, int K) 
	{
		if (S == "")
		{
			return "";
		}
		
		string dash;
		string s;
		int count = 0;
		// 如果是i--，且和0比较，不要用size_t
		for (int i = S.length()-1; i >= 0; i--)
		{
			//cout << S[i] << " " << endl;
			if (S[i] == '-')
			{
				continue;
			}

			count++;
			dash = "";
			if (count == K)
			{
				dash = "-";
				count = 0;
			}
			
			s = dash + (char)toupper(S[i]) + s;
		}

		if (s[0] == '-')
		{
			s = s.substr(1);
		}

		return s;
	}
};

int main(int argc, char* argv[], char* env[])
{
	string S = "--a-a-a-a--";
	int K = 2;

	Solution s;
	cout << s.licenseKeyFormatting(S,K) << endl;

	return 0;
}
