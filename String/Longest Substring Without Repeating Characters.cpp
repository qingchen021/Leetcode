/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        bool hash[256]={0};
        int start = 0, end =0, res = 0;
        for(;end < s.length();)
        {
            if(!hash[s[end]])
                hash[s[end++]] = true;
            else
                hash[s[start++]] = false;
            res = max(res,end-start);
        }
        return res;
    }
};
