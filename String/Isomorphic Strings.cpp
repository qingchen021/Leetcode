/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        map<char,char> m, rm;
        for(int i = 0;i<s.length();i++)
        {
            if(m.find(s[i]) == m.end())
            {
                if(rm.find(t[i]) != rm.end() && rm[t[i]] != s[i])
                    return false;
                
                m[s[i]] = t[i];
                rm[t[i]] = s[i];
                
            }
            else
            {
                if(m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};