/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings. 

*/

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( strs.size() == 0)
		{
			return "";
		}
		char ret[1000]={0};
		if(strs.size()==1)
			return strs[0];
		int p = 0;
		bool flag = true;

		while (flag)
		{
			char candidate =' ';
			if(strs[0].size() > p)
			{
				candidate = strs[0][p];
			}
			else
			{
				break;
			}
			for(int i = 1; i < strs.size(); i++)
			{
				if( strs[i].size() > p)
				{
					if( strs[i][p]== candidate)
					{
					}
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
			if(flag)
				ret[p++]=candidate;
		}
		ret[p]='\0';
		return ret;
	}
};