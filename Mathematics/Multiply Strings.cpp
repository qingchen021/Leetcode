/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<string> sum;
		for (int i = num2.length() - 1; i >= 0; i--)
		{
			int carry = 0;
			int curNum = num2[i] - '0';
			string curStr = "";
			curStr.insert(0, num2.length() - 1 - i, '0');
			for (int j = num1.length() - 1; j >= 0; j--)
			{
				int n2 = num1[j] - '0';
				int m = n2 * curNum + carry;
				carry = m / 10;
				curStr.insert(0, 1, m % 10 + '0');
			}
			if (carry > 0)
				curStr.insert(0, 1, carry + '0');
			sum.push_back(curStr);
		}
		int carry = 0;
		string ret = "";
		for (int j = 1;; j++)
		{
			bool flag = false;
			int curSum = 0;

			for (int i = 0; i < sum.size(); i++)
			{
				int pos = sum[i].length() - j;
				if (pos >= 0)
				{
					flag = true;
					curSum += sum[i][pos] - '0';
				}
			}
			if (!flag && carry == 0)
			{
				break;
			}
			curSum += carry;
			ret.insert(0, 1, curSum % 10 + '0');
			carry = curSum / 10;
		}

		if (ret[0] == '0')
		{
			for (int i = 0; i < ret.length(); i++)
			{
				if (ret[i] == '0')
					continue;
				else
				{
					ret = ret.substr(i);
				}
			}
		}
		if (ret[0] == '0')
			return "0";
		return ret;
	}
};