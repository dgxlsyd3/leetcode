#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		#define NUM 1
		#define TXT 2

		int sign = 1;
		int state = NUM;
		
		string snumber;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			char cNext = -1;
			if (i<str.length()-1)
			{
				cNext = str[i + 1];
			}

			if (state == NUM)
			{
				if (snumber == "")
				{
					if (c == ' ')
					{
						continue;
					}
					
					if (c == '+')
					{
						if (isdigit(cNext))
						{
							sign = 1;
						}
						else
						{
							state = TXT;
						}
					}
					else if (c == '-')
					{
						if (isdigit(cNext))
						{
							sign = -1;
						}
						else
						{
							state = TXT;
						}
					}
					else if (isdigit(c))
					{
						if (c == '0')
						{
							if (isdigit(cNext))
							{
								if (cNext != '0')
								{
									snumber += c;
								}
							}
							else
							{
								state = TXT;
							}
						}
						else
						{
							snumber += c;
						}
					}
					else
					{
						state = TXT;
					}
				}
				else
				{
					if (isdigit(c))
					{
						snumber += c;
					}
					else
					{
						state = TXT;
					}
				}
			}
		}

		if (snumber == "")
		{
			return 0;
		}

		double num = 0;
		double base = pow(10,snumber.length()-1);

		for (size_t i = 0; i < snumber.length(); i++)
		{
			num += (snumber[i]-'0') * base;
			base = base / 10;
		}

		num *= sign;
		if (num>INT_MAX)
		{
			return INT_MAX;
		}

		if ( num<INT_MIN)
		{
			return INT_MIN;
		}

		return (int)num;
	}
};


int main()
{
	printf("%d\n", Solution().myAtoi("20000000000000000000"));
	printf("%d\n", Solution().myAtoi("-000000000000000000000000000000000000000000000000001"));
	printf("%d\n", Solution().myAtoi("-42"));
	printf("%d\n", Solution().myAtoi("   +0 123"));

	atoi("0");
	return 0;
}