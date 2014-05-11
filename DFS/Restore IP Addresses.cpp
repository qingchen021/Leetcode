/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/
class Solution {
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> steps;
		vector<string> res;
		restoreIpAddresses(s, steps, res);
		return res;
	}

	void restoreIpAddresses(string s, vector<string> & steps, vector<string> & res)
	{
	    //要满足两个条件才行，steps可以是大于4的
		if (steps.size() == 4 && s == "")
		{
			string tmp = steps[0];
			for (int i = 1; i < steps.size(); i++)
			{
				tmp += ".";
				tmp += steps[i];
			}
			res.push_back(tmp);
		}
		//这里也是要判断的
		else if (steps.size() < 4)
		{
			int left = 4 - steps.size();
			int leftLen = s.length();
			if (leftLen <= 3 * (left) && leftLen >= left)
			{
				for (int i = 1; i <= 3 && i <= s.length(); i++)
				{
				     //第一位为0，那么只能取到这一位。
					if (s[0] == '0')
					{
						steps.push_back("0");
						restoreIpAddresses(s.substr(1), steps, res);
						steps.pop_back();
						break;
					}
					else
					{
						string str = s.substr(0, i);
						if (Vaild(str))
						{
							steps.push_back(str);
							restoreIpAddresses(s.substr(i), steps, res);
							steps.pop_back();
						}
					}					
				}
			}
		}
	}
	bool Vaild(const string & s)
	{
		if (s.length() < 1)
			return false;
		else if (s.length() == 3)
		{
			int i = atoi(s.c_str());
			if (i > 255 || i <= 0)
				return false;
		}
		return true;
	}
};