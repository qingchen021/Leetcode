/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
*/

class Solution {
public:
	void dfs(vector<int> &candidates, int target, int begin, vector<int> &steps, vector<vector<int> > &res)
	{
		if (target == 0)
		{
			res.push_back(steps);
		}
		else
		{
			int cur = begin;
			while (cur < candidates.size() && target - candidates[cur] >= 0)
			{
				if (cur == begin || candidates[cur] != candidates[cur - 1])
				{
					steps.push_back(candidates[cur]);
					dfs(candidates, target - candidates[cur], cur + 1, steps, res);
					steps.pop_back();
				}
				cur++;
			}
		}
	}

	vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > res;
		if (candidates.size() == 0){ return res; }
		sort(candidates.begin(), candidates.end());
		vector<int> steps;
		dfs(candidates, target, 0, steps, res);
		return res;
	}
};
