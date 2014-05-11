/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;
		bool hash[300] = { 0 };
		hash[s[0]] = true;
		int ret = 1;
		int first = 0, last = 0;
		//跟之前的题目类似，从last往后面推进，如果发现当前char出现在hash里面，
		//那么从first开始找，找到出现过char的位置，更新first为该位置的下一位
		//同时注意更新从first往后开始找的过程中，更新hash，把之前set过的值，unset
		for ( last = 1; last < s.length(); last++)
		{
			if (hash[s[last]])
			{
				//找到出现的那个char，并从它后面开始计数
				while (s[first] != s[last])
				{
					//注意更新那些被计数过的char，因为此时已经将他们exclude出去了。
					hash[s[first]] = false;
					first++;
				}
				first++;
			}
			else
			{
				//更新last的过程中也要更新每个char的hash
				hash[s[last]] = true;
			}
			ret = max(ret, last - first + 1);
		}
		return ret;
	}
};
