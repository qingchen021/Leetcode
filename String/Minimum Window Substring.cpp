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
	string minWindow(string S, string T) {
		int hashS[257] = { 0 };
		int hashT[257] = { 0 };
		for (int i = 0; i < T.length(); i++)
			hashT[T[i]] += 1;
		string ret = "";
		int first = 0, last = 0;
		int foundLen = 0, len = T.length();
		//首先找到符合条件的第一个字符串
		for (int i = 0; i < S.length(); i++)
		{
			char c = S[i];
			if (hashT[c] != 0)
			{			
				//每次发现如果能在hashT找到的就需要更新hashS
				hashS[c]++;
				if (hashS[c] <= hashT[c])
				{
					foundLen++;
					if (foundLen == len)
					{
						last = i;
						ret = S.substr(first, last - first + 1);
						break;
					}
				}
				
			}
		}
		if (foundLen != len)
			return ret;
		//再对此字符串从头开始往后缩进，如果发现当前元素会让foundlen变小，就需要last往后扩展找到与之相同的字符
		//知道first 和 last相遇或者last 已经到达字符串尾部 
		while (first <= last)
		{
			//一个一个数的往后缩进
			char c = S[first];
			first++;
			hashS[c]--;
			//发现如果此时first 会让foundLen减小，那么更新foundLen
			if (hashT[c] != 0 && hashS[c] < hashT[c])
				foundLen--;
			//只需要在foundLen不等于len的情况下更新last
			if (foundLen != len)
			{
				while (++last < S.length())
				{
					//每次发现如果能在hashT找到的就需要更新hashS
					if (hashT[S[last]] != 0)
						hashS[S[last]]++;
					//此时只需要找到让foundlen变小的那个字符
					if (S[last] == c)
					{
						foundLen++;
						break;
					}
				}
			}
			//如果发现foundLen 不等于len代表，last已经到尾端，可以直接退出了
			if (foundLen != len)
				return ret;
			else
			{
				//每次循环如果foundLen等于len，那么就需要更新ret了
				if (last - first + 1 < ret.length())
				{
					ret = S.substr(first, last - first + 1);
				}
			}
		}
		return ret;
	}
};