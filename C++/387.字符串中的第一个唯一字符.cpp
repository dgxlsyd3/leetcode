class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char,int> chars;
		for (size_t i = 0; i <  s.length(); i++)
		{
			chars[s[i]]++;
		}

		for (size_t i = 0; i < s.length(); i++)
		{
			if (chars[s[i]]==1)
			{
				return i;
			}
		}

		return -1;
	}
};