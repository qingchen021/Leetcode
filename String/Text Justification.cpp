/*
 Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.
Corner Cases:

    A line other than the last line might contain only one word. What should you do in this case?
    In this case, that line should be left-justified.
*/

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> ret;
		int curLeft = L;
		vector<string> curLine;
		for (int i = 0; i <= words.size();)
		{
			if (i < words.size() && ((curLine.size() == 0 && curLeft >= words[i].length()) ||
				(curLine.size() > 0 && curLeft >= words[i].length() + 1)))
			{
				if (curLine.size() == 0)
					curLeft -= words[i].length();
				else
					curLeft -= words[i].length() + 1;
				curLine.push_back(words[i]);
				i++;
			}
			else
			{
				string s = curLine[0];
				if (i == words.size())
				{
					for (int j = 1; j < curLine.size(); j++)
					{
						s.append(1, ' ');
						s += curLine[j];
					}
					s.append(curLeft, ' ');
					ret.push_back(s);
					break;
				}
				int dev = curLine.size() - 1;
				if (dev == 0)
				{
					s.append(curLeft, ' ');
				}
				else
				{
					int avg = curLeft / dev;
					int additions = curLeft % dev;
					for (int j = 1; j < curLine.size(); j++)
					{
						if (additions > 0)
						{
							s.append(avg + 1 + 1, ' ');
							additions--;
						}
						else
							s.append(avg + 1, ' ');
						s += curLine[j];
					}
				}
				ret.push_back(s);
				curLeft = L;
				curLine.clear();
			}
		}
		return ret;
	}
};