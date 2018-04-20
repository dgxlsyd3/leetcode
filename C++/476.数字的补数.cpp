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

class Solution {
public:
    int findComplement(int num) {

		int i=31;
		for(;i>=0;i--)
		{
			int bit = (num>>i) & 1;
			if(bit == 1)
				break;
		}

		int ret = 0;
		for(;i>=0;i--)
		{
			int bit = (num>>i) & 1;
			if(bit == 1)
			{
				bit = 0;
			}
			else if(bit == 0)
			{
				bit = 1;
			}

			ret += (bit<<i);
		}

        return ret;
    }
};

int main(int argc,char* argv[],char* env[])
{
	Solution s;
	cout << endl << s.findComplement(1) << endl;

    return 0;
}
