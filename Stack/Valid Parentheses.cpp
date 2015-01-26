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
		 stack<char> cStack;
		 for (int i = 0; i < s.length(); i++)
		    if(dicts.find(s[i]) != dicts.end())
			    if (!cStack.empty()){
				    if (dicts[s[i]] == cStack.top())
					    cStack.pop();
					else
					    return false;
			    }
				else
					   return false;
			 else
				 cStack.push(s[i]);
		 return cStack.empty();
	 }
 };