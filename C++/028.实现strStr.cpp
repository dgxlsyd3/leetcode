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

class Solution 
{
public:
	int strStr(string str, string findstr) 
	{		
		if (findstr == "")
		{
			return 0;
		}
		
		int flength = findstr.length();
		int endpos = str.length() - flength;
		if (endpos < 0)
		{
			return -1;
		}

		for (size_t i = 0; i <= endpos; i++)
		{
			if (str[i] == findstr[0])
			{
				bool is_equ = true;
				for (size_t j = 0; j < flength; j++)
				{
					if (str[i+j] != findstr[j])
					{
						is_equ = false;
						break;
					}
				}

				if (is_equ)
				{
					return i;
				}
			}
		}

		return -1;
	}
};

int main(int argc, char* argv[], char* env[])
{
	string haystack = "", needle = "";
	cout << Solution().strStr(haystack, needle) << endl;

	return 0;
}
