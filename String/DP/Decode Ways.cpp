/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

class Solution {
public:
	int numDecodings(string s) 
	{
		if(s.length()==0)
			return 0;
		vector<int> dp(s.length() + 1,0);
		dp[0] = 1;
		for(int i = 1;i <= s.length();i++)
		{
			if(i == 1)
				dp[1] = (s[0] == '0'?0:1);
			else
			{
				if((s[i-2]-'0') * 10 + (s[i-1]-'0') <= 26 && s[i-2] !='0')
				{
					dp[i] += dp[i-2];
				}				
				if(s[i-1] != '0')
					dp[i] += dp[i-1];
			}
			if(dp[i] == 0)
				return 0;
		}
		return dp[s.length()];
	}
};
