/*
 Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res;
		//输入空的集合
		res.push_back(vector<int>());
		//题目要求非逆序，所以要排个序
		sort(S.begin(), S.end());
		//依次遍历 集合size 从 1 到 S.size() 
		for (int i = 1; i <= S.size(); i++)
		{
			vector<int> steps;
			Subset(0, S.size() - 1, i, steps, S, res);
		}
		return res;
	}
	void Subset(int begin, int end, int k, vector<int> & steps, const vector<int> & S, vector<vector<int> > & res)
	{
		if (k < 0)
			return;
		else if (k == 0)
		{
			res.push_back(steps);
			return;
		}
		else
		{
			//从开始取，取K个，依次往后顺移
			for (; begin <= end; begin++)
			{
				steps.push_back(S[begin]);
				Subset(begin + 1, end, k - 1, steps, S, res);
				steps.pop_back();
			}
		}
	}
};