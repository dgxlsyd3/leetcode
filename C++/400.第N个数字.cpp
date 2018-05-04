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

// https://blog.csdn.net/JackZhang_123/article/details/78732896
class Solution{
public:
	int findNthDigit(int n) 
	{
		// 1  ..  9  是1位
		// 10 ... 99 是2位
		// ...
		int digitLen = 1;

		// 指定位数的数字个数
		long digitCount = 9;

		// 
		long digitStart = 1;

		while (n > digitCount*digitLen) {
			// 剩余的数字个数
			n -= (int)digitCount*digitLen;
			
			digitLen++;
			digitCount *= 10;
			digitStart *= 10;
		}

		// cout << "digitLen=" << digitLen
		// 	 << ", n=" << n
		// 	 << endl;

		int num = digitStart + (n - 1) / digitLen;

		int indexInNum = (n - 1) % digitLen;
		return stoi(to_string(num).substr(indexInNum,1));
	}
};

int main(int argc, char* argv[], char* env[])
{	
	Solution s;
	cout << s.findNthDigit(1000000) << endl;

	return 0;
}
