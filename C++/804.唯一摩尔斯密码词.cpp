#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
	int uniqueMorseRepresentations(vector<string>& words)
	{
		map<char, string> m = {
			{ 'a',".-" },
			{ 'b',"-..." },
			{ 'c',"-.-." },
			{ 'd',"-.." },
			{ 'e',"." },
			{ 'f',"..-." },
			{ 'g',"--." },
			{ 'h',"...." },
			{ 'i',".." },
			{ 'j',".---" },
			{ 'k',"-.-" },
			{ 'l',".-.." },
			{ 'm',"--" },
			{ 'n',"-." },
			{ 'o',"---" },
			{ 'p',".--." },
			{ 'q',"--.-" },
			{ 'r',".-." },
			{ 's',"..." },
			{ 't',"-" },
			{ 'u',"..-" },
			{ 'v',"...-" },
			{ 'w',".--" },
			{ 'x',"-..-" },
			{ 'y',"-.--" },
			{ 'z',"--.." }
		};

		set<string> s;
		for (auto word : words)
		{
			string smol = "";
			for (size_t i = 0; i < word.size(); i++)
			{
				char c = word[i];
				smol += m[c];
			}

			s.insert(smol);
		}

		return s.size();
	}
};

int main()
{
	vector<string> words = { "gin", "zen", "gig", "msg" };

	Solution s;
	int n = s.uniqueMorseRepresentations(words);

	cout << n << endl;
	return 0;
}
