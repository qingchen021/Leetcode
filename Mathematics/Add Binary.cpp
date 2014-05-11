/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

class Solution {
public:
	string addBinary(string a, string b) {
		int len1 = a.length();
		int len2 = b.length();
		int carry = 0;
		string ret = "";
		while (len1 && len2)
		{
			int cur = a[len1 - 1] - '0' + b[len2-1] - '0';
			cur += carry;
			if (cur > 1)
			{
				carry = 1;
				cur -= 2;
			}
			else
				carry = 0;
			ret.insert(0, 1, cur + '0');
			len1--;
			len2--;
		}
		while (len1)
		{
			int cur = a[len1-1] - '0';
			cur += carry;
			if (cur > 1)
			{
				carry = 1;
				cur -= 2;
			}
			else
				carry = 0;
			ret.insert(0, 1, cur + '0');
			len1--;
		}
		while (len2)
		{
			int cur = b[len2 - 1] - '0';
			cur += carry;
			if (cur > 1)
			{
				carry = 1;
				cur -= 2;
			}
			else
				carry = 0;
			ret.insert(0, 1, cur + '0');
			len2--;
		}
		if (carry > 0)
			ret.insert(0, 1, 1 + '0');
		return ret;
	}
};
