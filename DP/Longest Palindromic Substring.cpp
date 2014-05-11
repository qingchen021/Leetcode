/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 0 || len == 1)
			return s;
		bool cache[1001][1001] = { 0 };
		string ret = "";
		for (int i = 2; i <= len; i++)
		for (int j = 0; j + i <= len; j++)
		{
			if ((s[j] == s[j + i - 1]))
			{
				if ((i == 2 || i == 3) || (cache[j + 1][j + i - 2] == true))
				{
					cache[j][j + i - 1] = true;
					if (i > ret.length())
					{
						ret = s.substr(j, i);
					}
				}
			}
		}
		return ret;
	}
};
