/*
 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 
*/
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<string> res;
		unordered_set<string> cache;
		WordBreak(s, "", dict, cache, res);
	
		return res;
	}
	void WordBreak(string s, string curStr, unordered_set<string> & dict, unordered_set<string>& cache, vector<string> & res)
	{
		if (s.length() == 0)
		{
			res.push_back(curStr);
			return;
		}
		else
		{
			for (int i = 1; i <= s.length(); i++)
			{
				string str = s.substr(0, i);
				if (dict.count(str) != 0 && cache.count(s.substr(i)) == 0)
				{
					int size = res.size();
					WordBreak(s.substr(i), curStr.length() > 0 ? curStr + " " + str : str, dict, cache, res);
					if (res.size() == size)
					{
						cache.insert(s.substr(i));
					}
				}
			}
		}
	}
};