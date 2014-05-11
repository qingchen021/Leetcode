/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
*/
class Solution 
{
public:
    int minCut(string s) 
    {
    	vector<int> minCuts(s.length()+1,-1);
    	minCuts[s.length()] = -1;
    	vector<bool> tmp (s.length()+1,false);
    	vector<vector<bool> > isPal(s.length()+1, tmp);
    	for(int i = s.length()-1;i >= 0;i--)
    	{
    		minCuts[i] = s.length() - i - 1;
    		for(int j = i ; j < s.length(); j++)
    		{
    			if(s[i] == s[j] &&(j - i <= 2 || isPal[i+1][j-1]))
    			{
    				isPal[i][j] = true;
    				minCuts[i] = min(minCuts[i],minCuts[j+1] + 1);
    			}
    		}
    	}
    	return minCuts[0];
    }
};