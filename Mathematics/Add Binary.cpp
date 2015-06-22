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
		if (a.length()<b.length())
			swap(a, b);
		int i = a.length() - 1, j = b.length() - 1;
		while (i >= 0)
		{
			if (j >= 0)
				a[i] += b[j--] - '0';
			if (a[i] >= '2')
			{
				a[i] = a[i] - 2;
				if (i == 0)
					a = '1' + a;
				else
					++a[i - 1];
			}
			--i;
		}
		return a;
	}
};
