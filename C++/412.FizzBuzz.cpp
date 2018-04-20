#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<string> fizzBuzz(int n) 
	{

		vector<string> v;
		for (int i = 1; i <= n; i++)
		{
			//cout << i << endl;
			if (i % 3 == 0 && i % 5 != 0)
			{
				//cout << "Fizz" << endl;
				v.push_back("Fizz");
			}

			else if (i % 3 != 0 && i % 5 == 0)
			{
				//cout << "Buzz" << endl;
				v.push_back("Buzz");
			}

			else if (i % 3 == 0 && i % 5 == 0)
			{
				//cout << "FizzBuzz" << endl;
				v.push_back("FizzBuzz");
			}

			else
			{
				//cout << i << endl;
				char szText[10];
				sprintf(szText, "%d", i);
				v.push_back(szText);
			}
		}

		return v;
	}
};

int main(int argc, char* argv[], char* env[])
{
	Solution solution;
	vector<string> v = solution.fizzBuzz(15);

	for (auto s : v)
	{
		cout << s << endl;
	}

	return 0;
}
