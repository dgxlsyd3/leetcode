#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {

		// 假设有K层，即k层的硬币总数为
		// n = (1 + k) * k / 2;
		// 因此根据一元二次方程，求解出k的值并向下取整即可
		return (sqrt( (8*(double)n+1) )-1)/2;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution s;
	cout << s.arrangeCoins(1804289383) << endl;

	return 0;
}
