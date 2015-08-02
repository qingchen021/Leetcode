/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>steps;
		vector<string> res;
		restore(s, steps, res);
		return res;
	}
	void restore(string s, vector<string>&steps, vector<string> &res)
	{
		int sLen = s.length(), left = 4 - steps.size();
		if (sLen < left || sLen > left * 3)
			return;
		if (s.length() == 0)
		{
			if (steps.size() == 4)
			{
				string str = steps[0];
				for (int i = 1; i<4; i++)
					str += "." + steps[i];
				res.push_back(str);
			}
			return;
		}
		else
		{
			for (int i = 1; i < 4 && i <= s.length(); i++)
			{
				int n = stoi(s.substr(0, i));
				if (n >= 0 && n <256)
				{
					steps.push_back(s.substr(0, i));
					restore(s.substr(i), steps, res);
					steps.pop_back();
					if (s[0] == '0')
					{
						break;
					}
				}
			}
		}
	}
};