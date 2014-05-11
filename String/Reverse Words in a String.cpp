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
		string ret;
		int len = s.length();
		Reverse(s, 0, len - 1);
		int begin = 0, end = 0;
		do
		{
			while (begin < len && s[begin] == ' ')
			{
				begin++;
			}
			if (begin == len)
				break;
			else
			{
				end = begin;
				while (end < len && s[end] != ' ')
				{
					end++;
				}
				Reverse(s, begin, end - 1);
				ret.append(s.substr(begin, end - begin));
				ret.append(" ");
				begin = end;
			}
		} while (end < len);

		s = ret.substr(0, ret.length() - 1);

	}

	void Reverse(string & s, int begin, int end)
	{
		int len = end - begin;
		for (int i = 0; i <= len / 2; i++)
		{
			swap(s[i + begin], s[len - i + begin]);
		}
	}
};