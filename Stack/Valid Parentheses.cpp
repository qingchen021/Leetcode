/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

 class Solution
 {

 public:

	 bool isValid(string s)
	 {

		 map<char, char> dicts;
		 dicts[')'] = '(';
		 dicts[']'] = '[';
		 dicts['}'] = '{';

		 int len = s.length();
		 stack<char> cStack;
		 for (int i = 0; i < len; i++)
		 {
			 if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			 {
				 if (!cStack.empty())
				 {
					 if (dicts[s[i]] == cStack.top())
						 cStack.pop();
					 else
						 return false;
				 }
				 else
					 return false;
			 }
			 else
				 cStack.push(s[i]);
		 }
		 // dont forget to judge the stack 
		 if (!cStack.empty())
			 return false;
		 return true;
	 }
 };