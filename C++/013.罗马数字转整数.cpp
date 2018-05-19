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
	int txt(char c)
	{
		switch (c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:
			return 0;
		}
	}

	int romanToInt(string s) 
	{
		int length = s.length();
		int num = 0;
		for (size_t i = 0; i < length; i++)
		{
			char c = s[i];
			char cNext = 0;
			if (i<length -1)
			{
				cNext = s[i + 1];
			}

			int n = txt(c);
			if (c == 'I' )
			{
				if (cNext == 'V')
				{
					n = 4;
					i++;
				}
				else if (cNext == 'X')
				{
					n = 9;
					i++;
				}
			}
			else if (c == 'X')
			{
				if (cNext == 'L')
				{
					n = 40;
					i++;
				}
				else if (cNext == 'C')
				{
					n = 90;
					i++;
				}
			}
			else if (c == 'C')
			{
				if (cNext == 'D')
				{
					n = 400;
					i++;
				}
				else if (cNext == 'M')
				{
					n = 900;
					i++;
				}
			}

			num += n;
		}

		return num;
	}
};

int main(int argc, char* argv[], char* env[])
{
	cout << "III=" << Solution().romanToInt("III") << endl;
	cout << "IV=" << Solution().romanToInt("IV") << endl;
	cout << "IX=" << Solution().romanToInt("IX") << endl;
	cout << "LVIII=" << Solution().romanToInt("LVIII") << endl;
	cout << "MCMXCIV=" << Solution().romanToInt("MCMXCIV") << endl;
	return 0;
}
