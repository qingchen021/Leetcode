/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    	bool isPalindrome(string s) {
        	int begin = 0 , end = s.length() -1 ;
		while(begin <= end)
		{
			while(begin <= end && !IsAlpha(s[begin])) begin++;
			while(begin <= end && !IsAlpha(s[end])) end--;
			if(begin <= end)
			{
				if(!IsEqual(s[begin], s[end]))
					return false;
				else
				{
				    begin++;
				    end--;
				}
			}
		}
		return true;
    	}
	bool IsAlpha(char c)
	{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
	}

	bool IsEqual(char a, char b)
	{
		//主要考察如果a 和 b有一种是 数字，那么其它必须为数字，否则为不等
		if(IsN(a) || IsN(b))
		{
			return a == b;
		}
		
		if( a == b ) 
		    return true;
		else if( a-b == 32 || a-b == -32 ) 
		    return true;
		else 
		    return false;
	}

	bool IsN(char c)
	{
		return (c >= '0' && c <= '9');
	}
};