/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		const char * cur = s;
		const char * start = s;
		int lastLen = 0;
		while (true)
		{
			if (*cur == ' ' || *cur == '\0')
			{
				if (*start != ' ' && *start != '\0')
					lastLen = cur - start;
				if (*cur == '\0')
					break;
				start = cur + 1;
			}
			cur++;
		}
		return lastLen;
	}
};