/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> tmp(t.length()+1,0);
        vector<vector<int> > dp(s.length()+1,tmp);
        for(int i = 0;i <= s.length() ;i++)
        	dp[i][0] = 1;
        for(int i = 1;i<= t.length();i++)
        	for(int j = 1; j <= s.length(); j++)
        	{
        		if(t[i-1] == s[j-1])
        			dp[j][i] = dp[j-1][i] + dp[j-1][i-1];
        		else
        			dp[j][i] = dp[j-1][i];
        	}
        return dp[s.length()][t.length()];
        }
};