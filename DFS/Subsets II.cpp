/*
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
		res.push_back(vector<int>());
		sort(S.begin(),S.end());
		for(int i = 1 ;i <= S.size() ;i++)
		{
			vector<int> steps;
			subset(0,S.size()-1,i,steps,S,res);
		}
		return res;
    }
	void subset(int begin, int end, int k , vector<int>& steps, const vector<int> & S, vector<vector<int> > & res)
	{
		if(k < 0) return ;
		else if( k == 0) 
		{
			res.push_back(steps);
			return;
		}
		else
		{
			for( ; begin <= end ;)
			{
				steps.push_back(S[begin]);
				subset(begin+1, end , k-1, steps, S, res);
				steps.pop_back();
				//与之前的题目比较，这个主要考察以下这个条件，如果下一个元素和此时的元素相同，
				//就没有必要再搜它了，因为该元素所有的情况已经被覆盖了
				do
				{
					begin++;
				}while(begin <=end && S[begin]== S[begin-1]);
			}
		}
	}
};