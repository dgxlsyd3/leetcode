#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution
{
public:
	string process_email(string email) 
	{
		int atpos = email.find_last_of('@');

		string domain = email.substr(atpos + 1);
		string prefix = email.substr(0, atpos - 1);

		int addpos = prefix.find_first_of('+');
		if (addpos != string::npos)
		{
			prefix = prefix.substr(0, addpos);
		}

		for (auto it = prefix.begin(); it != prefix.end();)
		{
			if (*it == '.')
			{
				it = prefix.erase(it);
			}
			else
			{
				it++;
			}
		}

		return prefix + "@" + domain;
	}

	int numUniqueEmails(vector<string>& emails) 
	{
		set<string> mails;
		for (size_t i = 0; i < emails.size(); i++)
		{
			string semail = process_email(emails[i]);
			mails.insert(semail);
		}

		return mails.size();
	}
};

int main(int argc, char* argv[], char* env[])
{
	vector<string> emails = {
		"test.email+alex@leetcode.com",
		"test.e.mail+bob.cathy@leetcode.com",
		"testemail+david@lee.tcode.com" };

	Solution s;
	int num = s.numUniqueEmails(emails);
	cout << "num=" << num << endl;

	return 0;
}
