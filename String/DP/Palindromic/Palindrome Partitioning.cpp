/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/
class Solution 
{
vector<vector<int> > _isPal;
public:
    vector<vector<string>> partition(string s) 
    {
    	_isPal.clear();
   		vector<int> tmp(s.length() + 1, -1);
        _isPal.resize(s.length() + 1, tmp);
        vector<string> steps;
        vector<vector<string> > res;
        partition(s,0,s.length()-1,steps,res);
        return res;
    }

 	
    void partition(const string & s, int begin, int end, vector<string> & steps, vector<vector<string>> & res)
    {
    	if(begin > end)
    	{
    		 res.push_back(steps);
    		 return ;
    	}
    	else
    	{
    		for(int i = begin ;i <= end;i++ )
    		{
    			if(IsPal(s,begin,i))
    			{
    				steps.push_back(s.substr(begin,i-begin + 1));
    				partition(s,i+1,end,steps,res);
    				steps.pop_back();
    			}
    		}
    	}
    }

    bool IsPal(const string &s , int start, int end)
    {
    	if(_isPal[start][end] != -1)
    		return _isPal[start][end];
    	else
		{
			if(s[start] == s[end])
			{
				if(end-start <= 2)
					return true;
				else
				{
					return IsPal(s,start+1,end-1);
				}
			}
			else
				return false;
		}
    }
};