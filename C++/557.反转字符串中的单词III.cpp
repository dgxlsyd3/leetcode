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
	string reverseWords(string s)
	{
		vector<string> words;
		string word;
		for(auto c : s)
		{
			if (c == ' ')
			{
				words.push_back(word);
				word= "";
			}
			else
			{
				word+=c;
			}
		}

		if(word != "")
		{
			words.push_back(word);
		}

		string rewords;
		for (int w= 0;w<words.size();w++)
		{
			string str = "";
			for (int i = words[w].length()-1;i>=0;i--)
			{
				str+=words[w][i];
			}

			if(w<words.size()-1)
			{
				rewords += (str + " ");
			}
			else
			{
				rewords += str ;
			}
		}

		return rewords;
	}
};

int main(int argc,char* argv[],char* env[])
{
	Solution t;
	cout<<t.reverseWords("Let's take LeetCode contest")<<endl;

	return 0;
}
