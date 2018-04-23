/*
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。

输入: x = 1, y = 4
输出: 2
解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
*/

#include <stdio.h>
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
    int hammingDistance(int x, int y) 
	{
        int ret = 0;
		
		for(int i = 0;i<32;i++)
		{
			int bitX = (x >> i) & 1;
			int bitY = (y >> i) & 1;
			
			if(bitX != bitY)
			{
				ret ++;
			}
		}
		
		return ret;
    }
};

int main(int argc,char* argv[],char* env[])
{
	Solution solution;
	cout << solution.hammingDistance(1,4) << endl;
    
    return 0;
}
