/*
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict)
	{
		unordered_set<string> cache;
	    bool ret = WordBreak(s, "", dict, cache);
		return ret;
	}
	bool WordBreak(string s, string curStr, unordered_set<string> & dict, unordered_set<string>& cache)
	{
		if (s.length() == 0)
		{
			return true;
		}
		else
		{
			for (int i = 1; i <= s.length(); i++)
			{
				string str = s.substr(0, i);
				if (dict.count(str) != 0 && cache.count(s.substr(i)) == 0)
				{
					bool ret = WordBreak(s.substr(i), curStr.length() > 0 ? curStr + " " + str : str, dict, cache);
					if(ret)
					    return true;
					cache.insert(s);
				}
			}
			return false;
		}
	}
};