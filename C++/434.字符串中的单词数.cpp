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
	int countSegments(string s) 
	{
		
		enum {
			Words = 1,
			NonWords = 2
		};

		int state = NonWords;
		int count = 0;
		int size = s.length();
		for (size_t i = 0; i < size; i++)
		{
			//cout << "[" << c << "]" << endl;
			char c = s[i];
			if (state == Words)
			{
				if (c == ' ')
				{
					state = NonWords;
				}
			}
			else if (state == NonWords)
			{
				if (c != ' ')
				{
					state = Words;
					count++;
				}
			}

		}

		return count;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution s;
	cout << s.countSegments("love live! mu'sic forever") << endl;

	return 0;
}
