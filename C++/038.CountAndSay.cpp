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

// 第1个人说 “1”
// 第2个人说 “1”个“1”，连起来就是 “11”
// 第3个人说 “2”个“1”，连起来就是 “21”
// 第4个人说 “1”个“2”，“1”个“1”，连起来就是 “12 11”
// 第5个人说 “1”个“1”,“1”个“2”，“2”个“1”，连起来就是 “11 12 21”
// 本质是每个数都依赖于上一个数的结果
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		}

		string s = countAndSay(n - 1);
		
		string sCount = "";
		char cLast = '\0';
		int nLast = 0;
		size_t len = s.length();
		for (size_t i = 0; i < len; i++)
		{
			char c = s[i];
			if (cLast == '\0')
			{
				nLast++;
			}
			else if (cLast == c)
			{
				nLast++;
			}
			else
			{
				sCount = sCount + char(nLast + '0') + cLast ;
				nLast = 1;
			}

			cLast = c;
		}

		sCount = sCount + char(nLast+'0') + cLast ;
		return sCount;
	}
};

int main(int argc, char* argv[], char* env[])
{
	cout << Solution().countAndSay(5) << endl;

	// 根据ASCII码表
	// 数字+‘0’，正好是'数字'
	// 比如 5+'0' = '5'
	//cout << (int)'0' <<endl;
	//cout << (char)48 << endl;

	getchar();
	return 0;
}
