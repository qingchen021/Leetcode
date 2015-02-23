/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

 class Solution {
 public:
	 vector<string> restoreIpAddresses(string s) {
		 vector<string> steps;
		 vector<string> res;
		 restoreIpAddresses(s, steps, res);
		 return res;
	 }

	 void restoreIpAddresses(string s, vector<string> & steps, vector<string>& res)
	 {
		  if (s.length() == 0 && steps.size() == 4)
		 {
			 string result;
			 for (int i = 0; i<steps.size(); i++)
			 {
				 result += steps[i];
				 if (i <steps.size() - 1)
					 result += ".";
			 }
			 res.push_back(result);
			 return;
		 }
		 else
		 {
			 int sLen = s.length(), n = steps.size();
			 if (sLen < (4 - n) || sLen > 3 * (4 - n))
				 return;
			 for (int i = 1; i <= 3 && i <= s.length(); i++)
			 {
				 int num = stoi(s.substr(0, i));
				 if (num <= 255)
				 {
					 steps.push_back(s.substr(0, i));
					 restoreIpAddresses(s.substr(i), steps, res);
					 steps.pop_back();
					 if (s[0] == '0')
						 break;
				 }
				 else
					 break;
			 }
		 }
	 }
 };