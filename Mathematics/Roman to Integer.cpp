/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
	int romanToInt(string s)
	{
		int pre = GetInt(s[0]);
		int curSum = pre;
		int totalSum = 0;
		for (int i = 1; i < s.length(); i++)
		{
			int cur = GetInt(s[i]);
			if (cur == pre)
			{
				curSum += cur;
			}
			else if (cur > pre)
			{
				curSum = cur - pre;
			}
			else
			{
				totalSum += curSum;
				curSum = cur;
			}
			pre = cur;
		}

		return totalSum + curSum;
	}

	int GetInt(char c)
	{
		switch (c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
};