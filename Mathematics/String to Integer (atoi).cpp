/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0)
			return 0;
		int cur = 0;
		int flag = 1;
		int start = 0;
		while (str[cur] == ' ')
			cur++;
		if (str[cur] == '-')
		{
			flag = -1;
			cur++;
		}
		else if (str[cur] == '+')
		{
			cur++;
		}
		long long num = 0;
		for (; cur < str.length(); cur++)
		{
			int c = str[cur] - '0';
			if (c < 0 || c >9)
				break;
			num *= 10;
			num += c;
			if (num *flag > INT_MAX || num *flag < INT_MIN)
				break;
		}
		num *= flag;
		if (num > INT_MAX)
			return INT_MAX;
		if (num < INT_MIN)
			return INT_MIN;
		return num;
	}
};