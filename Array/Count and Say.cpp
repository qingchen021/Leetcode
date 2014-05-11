/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string
*/

class Solution {
public:
	string countAndSay(int n) {
		int i = 1;
		string curStr = "1";
		while (i < n)
		{
			char c = curStr[0];
			int times = 0;
			string tmp = curStr;
			curStr = "";
			for (int j = 0; j <= tmp.size(); j++)
			{
				if (j < tmp.size() && tmp[j] == c)
				{
					times++;
				}
				else
				{
					string timesStr = to_string(times);
					curStr += timesStr;
					curStr.push_back(c);
					c = tmp[j];
					times = 1;
				}
			}
			i++;
		}
		return curStr;
	}
};