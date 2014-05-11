/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    	vector<vector<int> > combine(int n, int k) {
		vector<int> step;
		vector<vector<int> > res;
        combine(1, n, step,k, res);
		return res;
    	}
	void combine(int begin, int end ,vector<int> & step, int k,  vector<vector<int> > & res)
	{
		if(step.size() == k)
		{
			res.push_back(step);
			return ;
		}
		else
		{
			for(;begin<= end;++begin)
			{
				step.push_back(begin);
				combine(begin+1, end, step, k,res);
				step.pop_back();
			}
		}
	}
};