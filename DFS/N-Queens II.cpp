/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
*/

class Solution {
public:
    int totalNQueens(int n) {
    	vector<int> steps;
    	int ret = 0;
        NQueen(steps,n,ret);
        return ret;
    }

    void NQueen(vector<int> & steps, const int & n, int & res)
    {
    	if(steps.size() == n)
    	{
    		res++;
    	}
    	else
    	{
    		for(int i = 0 ; i < n ;i++)
    		{
    			if(IsVaild(steps, i))
    			{
    				steps.push_back(i);
    				NQueen(steps,n, res);
    				steps.pop_back();
    			}
    		}
    	}
    }

    bool IsVaild(const vector<int> & steps, const int col)
    {
    	int row = steps.size();
    	for(int i = 0 ; i < steps.size() ;i++)
    	{
    		if(col == steps[i] ||  abs(i-row) == abs(steps[i] - col))
    		{
    			return false;
    		}
    	}
    	return true;
    }
};