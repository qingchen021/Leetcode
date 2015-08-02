/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> result(num1.length() + num2.length() - 1, 0);
		for (int i = 1; i <= num1.size(); i++)
		for (int j = 1; j <= num2.size(); j++)
		{
			int c1 = num1[i - 1] - '0';
			int c2 = num2[j - 1] - '0';
			result[i + j - 2] += c1 * c2;
		}
		string ret;
		int carry = 0;
		for (int i = result.size() - 1; i >= 0; i--)
		{
			int cur = result[i] + carry;
			ret.insert(0, to_string(cur % 10));
			carry = cur / 10;
		}
		if (carry>0)
			ret.insert(0, to_string(carry));
		return ret;
	}
};