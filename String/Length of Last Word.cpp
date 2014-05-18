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
        int length = 0;
        int preLength = 0;
        while (*s) 
        {
            if (*s != ' ') 
            {
                length ++;
            }
            else if (*s == ' ') 
            {
                if(length)
                    preLength = length;
                length = 0;
            }
            ++s;
        }
        return length==0?preLength:length;
    }
};
