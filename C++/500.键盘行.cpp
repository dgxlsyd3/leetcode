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
	bool isInStr(string qwertyuiop,string word)
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			char c = tolower(word[i]);
			if (qwertyuiop.find(c) == string::npos)
			{
				return false;
			}
		}

		return true;
	}

	vector<string> findWords(vector<string>& words) 
	{
		string qwertyuiop = "qwertyuiop";
		string asdfghjkl = "asdfghjkl";
		string zxcvbnm = "zxcvbnm";

		vector<string> words_ret;
		for (string word : words)
		{
			if (isInStr(qwertyuiop, word) || 
				isInStr(asdfghjkl, word) ||
				isInStr(zxcvbnm, word) )
			{
				words_ret.push_back(word);
			}
		}

		return words_ret;
	}
};


int main(int argc,char* argv[],char* env[])
{
	vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };

	Solution s;
	vector<string> ret_words = s.findWords(words);
	for (auto word : ret_words)
	{
		cout << word << endl;
	}
    
    return 0;
}
