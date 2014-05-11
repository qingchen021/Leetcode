/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		int carry = 0;
		if (digits[digits.size() - 1] == 9)
		{
			digits[digits.size() - 1] = 0;
			carry = 1;
		}
		else
		{
			digits[digits.size() - 1]++;
			return digits;
		}
		for (int i = len - 2; i >= 0; i--)
		{
			int cur = carry + digits[i];
			if (cur >= 10)
			{
				carry = 1;
				digits[i] = cur - 10;
			}
			else
			{
				carry = 0;
				digits[i] = cur;
			}
		}
		if (carry == 1)
		{
			digits.insert(digits.begin(), 1);
			return digits;
		}
		else
		{
			return digits;
		}
	}
};