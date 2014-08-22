/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>  res;
		string s;
		letterCombinations(digits, s, res);
		return res;
	}

	void letterCombinations(string digits, string s, vector<string> & res)
	{
		if (digits.length() == 0)
		{
			res.push_back(s);
		}
		else
		{
			string num = GetNum(digits[0]);
			for (int i = 0; i < num.length(); i++)
			{
				string tmp = s;
				letterCombinations(digits.substr(1), tmp.append(1, num[i]), res);
			}
		}
	}

	string GetNum(char c)
	{
		int nth = c - '2';
		if(nth == 5)
			return "pqrs";
		if(nth == 6)
			return "tuv";
		if(nth == 7)
			return "wxyz";
		char start = 'a' + nth * 3;
		string ret;
		ret.append(1, start);
		ret.append(1, start + 1);
		ret.append(1, start + 2);
		return ret;
	}
};

//interative
/*
class Solution {
 public:
	 vector<string> letterCombinations(string digits) {
		 vector<string> ret;
		 ret.push_back("");
		 for (int j = 0; j < digits.size(); j++)
		 {
			 string str = GetString(digits[j]);
			 vector<string> v;
			 for (int k = 0; k < str.size(); k++)
			 {				
				 for (int i = 0; i < ret.size(); i++)
				 {
					 string s = ret[i];
					 s.append(1, str[k]);
					 v.push_back(s);
				 }				
			 }
			 ret = v;
		 }
		 return ret;
	 }

	 string GetString(char c)
	 {
		 if (c == '7')
			 return "pqrs";
		 if (c == '8')
			 return "tuv";
		 if (c == '9')
			 return "wxyz";
		 int n = c - '0';
		 string ret;
		 for (int i = 0; i < 3; i++)
			 ret.append(1, 'a' + (n - 2) * 3 + i);
		 return ret;
	 }
 };
*/