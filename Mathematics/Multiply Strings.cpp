/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> res(num1.length() + num2.length(), 0);
		for (int i = num1.length(); i > 0; i--)
			for (int j = num2.length(); j > 0; j--)
			{
				int c = (num1[i - 1] - '0')*(num2[j - 1] - '0');
				res[i + j - 1] += c;
			}
		for (int i = num1.length() + num2.length() - 1; i > 0; i--)
		{
			int c = res[i] / 10;
			res[i - 1] += c;
			res[i] %= 10;
		}
		int i = 0;
		while (i < num1.length() + num2.length() && res[i] == 0)
			i++;
		string ret = "";
		while (i<num1.length() + num2.length())
			ret.append(1, res[i++] + '0');
		return ret;
	}
};