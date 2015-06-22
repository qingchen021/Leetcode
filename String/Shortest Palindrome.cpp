/*
 Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len < 2)
            return s;
        string str = s;
        reverse(str.begin(),str.end());
        int i = len;
        for(;i>=1;i--)
        {
            if(str.substr(len - i,i) == s.substr(0,i))
                break;
        }
        return str.substr(0,len-i) + s;
    }
};