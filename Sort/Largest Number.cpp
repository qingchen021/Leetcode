/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
	string largestNumber(vector<int> &num)
	{
		sort(num.begin(), num.end(), Compare);
		string ret;
		if(num[0]==0)
		    return "0";
		for (int i = 0; i<num.size(); i++)
			ret += to_string(num[i]);
		return ret;
	}

	static bool Compare(int i, int j)
	{
		auto s1 = to_string(i), s2 = to_string(j);
		if (s1.length() == s2.length())
			return s1.compare(s2)>0;
		else
			return (s1 + s2).compare(s2 + s1) > 0;
	}
};