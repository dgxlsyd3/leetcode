#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string toHex(int num)
	{
		if (num == 0) 
		{
			return "0";
		}

		const char HEXCHAR[] = { 
			'0', '1', '2', '3', '4', 
			'5', '6', '7', '8', '9', 
			'a', 'b', 'c', 'd', 'e', 'f' };

		int hex[10];
		int hexLength = 0;

		for (int i = 0; i<32; i += 4) {
			if (num >> i == 0) {
				break;
			}

			int hexNum = num >> i & 0x0f;

			hex[hexLength] = hexNum;
			hexLength++;
		}

		string hexStr = "";
		for (int i = hexLength - 1; i >= 0; i--)
		{
			int hexChar = hex[i];
			hexStr += HEXCHAR[hexChar];
		}

		return hexStr;
	}
};

int main(int argc,char* argv[],char* env[])
{
	Solution s;
	
	cout<< s.toHex(-1) <<endl;
    return 0;
}
