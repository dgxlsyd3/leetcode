#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution
{
public:
	vector<string> readBinaryWatch(int num)
	{
		vector<string> list;
		for (size_t i = 0; i < 12; i++)
		{
			bitset<4> h(i);
			for (size_t j = 0; j < 60; j++)
			{
				bitset<6> m(j);
				if (h.count() + m.count() == num)
				{
					char szTime[10];
					sprintf(szTime, "%d:%02d", i, j);
					list.push_back(szTime);
				}
			}
		}

		return list;
	}
};

int main()
{
	Solution s;
	vector<string> timeList = s.readBinaryWatch(1);

	return 0;
}