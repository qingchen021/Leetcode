/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pos;
	//最后一个反括号的值
	int lastBackQuote = -1;
	int longest = 0;
	for(int i = 0 ; i < s.length();i++)
	{
		if(s[i] == '(')
		{
			//push的是当前的index
			pos.push(i);
		}
		else
		{
			if(pos.empty())
			{
				//更新lastbackquote
				lastBackQuote = i;
			}
			else
			{
				//将于当前反括号匹配的顺括号，pop出来，check栈里面还有元素没
				//如果有那么当前反括号只能到栈顶元素的位置，
				//否则就能达到lastbackquote的位置
				pos.pop();
				if(pos.empty())
				{
					longest = max(longest, i - lastBackQuote);
				}
				else
				{
					longest = max(longest, i - pos.top());
				}
			}
		}
	}
	return longest;
    }
};