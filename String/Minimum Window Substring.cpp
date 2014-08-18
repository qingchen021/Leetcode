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
		int hashS[1 << 8] = { 0 };
		int hashT[1 << 8] = { 0 };
		int total = 0;
		for (int i = 0; i < T.size(); i++)
		{
			++total;
			++hashT[T[i]];
		}
		int start = -1, head = 0, length = INT_MAX;
		for (int i = 0; i < S.size(); i++)
		{
			hashS[S[i]]++;
			if (hashT[S[i]] != 0 && hashS[S[i]] <= hashT[S[i]])
				total--;
			while (head <= i && hashS[S[head]]>hashT[S[head]])
			{
				hashS[S[head]]--;
				head++;
			}
			if (total == 0 && i - head + 1< length)
			{
				start = head;
				length = i - head + 1;
			}
		}
		return start == -1 ? "" : S.substr(start, length);
	}
};