/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/
class Solution {
public:

	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		vector<bool> tmp(s1.length() + 1, false);
		vector<vector<bool> > dp(s2.length() + 1, tmp);
		dp[0][0] = true;
		//dp[i][j] = if(s3[i+j-1] == s1[i]) dp[i-1][j] || if(s[i+j-1] == s2[j]) dp[i][j-1];
		//当前这个点，只能从左边或者上边来，但是要分别判断能否从左边或者上边过来
		//即s3[i+j-1] == s1[i] 或者s3[i+j-1] = s2[j]
		for (int i = 0; i <= s1.length(); i++)
		for (int j = 0; j <= s2.length(); j++)
		{
			if(i>0)
				if (s3[i + j - 1] == s1[i - 1] && dp[j][i - 1])
				{
					dp[j][i] = true;
				}
			if(j>0)
				if (s3[i + j - 1] == s2[j - 1] && dp[j-1][i])
				{
					dp[j][i] = true;
				}
		}
		return dp[s2.length()][s1.length()];
	}
};