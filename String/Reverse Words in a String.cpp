/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

*/

class Solution {
public:
	void reverseWords(string &s) {
		int start = 0, end = s.length() - 1;
		while (s[start] == ' ')  ++start;
		while (s[end] == ' ') --end;
		Reverse(s, start, end);
		int cur = start;
		int lastStart = start;
		int lastPos = start;
		while (cur <= end + 1)
		{
			if (s[cur] == ' ' || cur == end + 1)
			{
				if (lastStart != -1)
				{
					Reverse(s, lastStart, cur - 1);
					Move(s, lastPos, lastStart, cur - 1);
					lastPos += cur - lastStart + 1;
					s[lastPos - 1] = ' ';
					lastStart = -1;
				}
			}
			else
			if (lastStart == -1)
				lastStart = cur;
			cur++;
		}
		s = s.substr(start, lastPos - start - 1);
	}

	void Move(string & s, int pos, int start, int end)
	{
		int len = end - start + 1;
		if (len <= 0 || pos == start)
			return;
		for (int i = 0; i < len; i++)
			s[pos + i] = s[start + i];

	}
	void Reverse(string & s, int start, int end)
	{
		if (start >= end )
			return;
		int len = end - start;
		for (int i = 0; i <= len / 2; i++)
		{
			swap(s[start + i], s[end - i]);
		}
	}
};