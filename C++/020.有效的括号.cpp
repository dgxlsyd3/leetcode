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
    bool isValid(string s)
	{
		stack<char> st;
		for(auto c : s)
		{
			if(c == '[')
			{
				// 小技巧
				st.push(']');
			}
			else if(c == '{')
			{
				st.push('}');
			}
			else if(c == '(')
			{
				st.push(')');
			}

			if(c == '}' || c == ']' || c == ')')
			{
				if(!st.empty())
				{
					if(c != st.top())
					{
						break;
					}

					st.pop();
				}
				else
				{
					// 很关键，此时为空说明缺少前括号
					return false;
				}
			}
		}

		return st.empty();
    }
};

int main(int argc,char* argv[],char* env[])
{
	Solution s;
	cout<<s.isValid("]")<<endl;

    return 0;
}
