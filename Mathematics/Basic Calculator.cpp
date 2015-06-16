/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function
*/

//recursion
class Solution {
public:
	int calculate(string s) {
		int p = 0;
		return calculate(s, p);
	}
	// Here has to string &s ,otherwrise it will report memory exceeded
	int calculate(string &s, int &p)
	{
		int num = 0;
		long long ret = 0;
		int lastSign = 1;
		for (; p < s.length(); p++)
		{
			switch (s[p])
			{
				case '(':
				{
							p++;
							ret += lastSign * calculate(s, p);							
							break;
				}
				case ')':
				{
							if (num != 0)
							{
								ret += lastSign * num;
							}
							return ret;
				}
				case '+':
				{
							ret += lastSign * num;
							lastSign = 1;
							num = 0;
							break;
				}
				case '-':
				{
							ret += lastSign * num;
							lastSign = -1;
							num = 0;
							break;
				}
				case ' ':
				{
							break;
				}
				default:
				{
						   num *= 10;
						   num += s[p] - '0';
						   break;
				}
			}
		}
		if (num != 0)
		{
			ret += lastSign * num;
		}
		return ret;
	}
};

// Using stack
/*
class Solution {
public:
	int calculate(string s) {
		stack<int> p;
		p.push(1);
		int curSign = 1;
		int ret = 0;
		int num = 0;
		for (int i = 0; i<s.length(); i++)
		{
			switch (s[i])
			{
			case '(':
			{
						p.push(curSign * p.top());
						curSign = 1;
						break;
			}
			case ')':
			{
						ret += num * curSign * p.top();
						curSign = 1;
						num = 0;
						p.pop();
						break;
			}
			case '+':
			{
						ret += num * curSign * p.top();
						curSign = 1;
						num = 0;
						break;
			}
			case '-':
			{
						ret += num * curSign * p.top();
						curSign = -1;
						num = 0;
						break;
			}
			case ' ':
			{
						break;
			}
			default:
			{
					   num *= 10;
					   num += s[i] - '0';
					   break;
			}
			}
		}
		ret += num * curSign * p.top();
		return ret;
	}
};
*/

