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
		//if s3.length() == 0 should return true;
		if (s3.length() == 0)
			dp[0][0] = true;
		//更新没有s2的情况下，s1的情况下最大的能到的距离
		for (int i = 1; i <= dp[0].size(); i++)
		{
			if (i > s1.length())
				break;
			if (s3[i - 1] != s1[i - 1])
				break;
			else
				dp[0][i] = true;
		}
		//更新没有s1的情况下，s2的情况下最大的能到的距离
		for (int i = 1; i <= dp.size(); i++)
		{
			if (i > s2.length())
				break;
			if (s3[i - 1] != s2[i - 1])
				break;
			else
				dp[i][0] = true;
		}
		//dp[i][j] = if(s3[i+j-1] == s1[i]) dp[i-1][j] || if(s[i+j-1] == s2[j]) dp[i][j-1];
		//当前这个点，只能从左边或者上边来，但是要分别判断能否从左边或者上边过来
		//即s3[i+j-1] == s1[i] 或者s3[i+j-1] = s2[j]
		for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.length(); j++)
		{
				if (s3[i + j - 1] == s1[i - 1] && dp[j][i - 1])
				{
					dp[j][i] = true;
				}
				if (s3[i + j - 1] == s2[j - 1] && dp[j-1][i])
				{
					dp[j][i] = true;
				}
		}
		return dp[s2.length()][s1.length()];
	}
};