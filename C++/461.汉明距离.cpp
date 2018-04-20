/*
��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
������������ x �� y����������֮��ĺ������롣

����: x = 1, y = 4
���: 2
����:
1   (0 0 0 1)
4   (0 1 0 0)
       ��   ��
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
