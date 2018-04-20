#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool judgeCircle(string moves)
	{
	    int x = 0;
		int y = 0;
		for(auto c : moves)
		{
			if(c == 'L')
			{
				x -= 1;
			}
			else if(c == 'R')
			{
				x += 1;
			}
			else if(c == 'U')
			{
				y += 1;
			}
			else if(c == 'D')
			{
				y -= 1;
			}
		}

		return (x==0 && y == 0);
    }
};

int main(int argc,char* argv[],char* env[])
{
    string moves = "RLUD";

	Solution solution;
	cout<< solution.judgeCircle(moves) <<endl;

    return 0;
}
