/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/

class Solution {
public:
	string minWindow(string s, string t) {
		int hashT[256] = { 0 };
		int hashS[256] = { 0 };
		for (int i = 0; i<t.size(); i++)
			hashT[t[i]]++;
		int start = -1, end = -1, count = 0;
		string ret;
		for (int i = 0; i<s.length(); i++)
		{
			hashS[s[i]]++;
			if (hashS[s[i]] <= hashT[s[i]])
			{
				count++;
			}
			if (count == t.size())
			{
				if (start == -1)
				{
					start = 0;
					end = i;
					ret = s.substr(start, end - start + 1);
				}
				while (hashS[s[start]] > hashT[s[start]])
				{
					hashS[s[start]]--;
					if (end - start < ret.size())
						ret = s.substr(start, end - start + 1);
				}
			}
		}
		return ret;
	}
};
