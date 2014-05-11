/*
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
        	return false;
        string tmp1 = s1, tmp2 = s2;
        if(s1 == s2)
        	return true;
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());
        if(tmp1!=tmp2)
            return false;
        for(int i = 1 ;i < s1.length();i++)
       	{
       		string s1Left = s1.substr(0,i);
       		string s1Right = s1.substr(i);

       		string s2Left = s2.substr(0,i);
       		string s2Right = s2.substr(i);
       		bool result = isScramble(s1Left,s2Left) && isScramble(s1Right, s2Right);
       		if(result)
       			return true;

       		s2Left = s2.substr(s2.length() -i);
       		s2Right = s2.substr(0,s2.length() -i);
       		result = isScramble(s1Left,s2Left) && isScramble(s1Right, s2Right);
       		if(result)
       			return true;
       	}
       	return false;
    }
};