/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
	string convertToTitle(int n)
	{
	    string ret;
	    while(n)
	    {
	        int c = n%26;
	        if(c==0)
	        {
	            ret.insert(ret.begin(),1,'Z');
	            --n;
	        }
	        else
	        {
	            ret.insert(ret.begin(),1,'A' + c -1);
	        }
	        n = n/26;
	    }
	    return ret;
	}
};