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
	 void dfs(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &r, int i){
		 if (target<0){
			 return;
		 }
		 else{
			 if (target == 0){
				 res.push_back(r);
			 }
			 else{
				 int begin = i;
				 while (i<candidates.size() && target - candidates[i] >= 0)
				 {
					 if (i == begin || candidates[i] != candidates[i - 1])
					 {
						 r.push_back(candidates[i]);
						 dfs(candidates, target - candidates[i], res, r, i+1);
						 r.pop_back();
						 ++i;
					 }
					 else
						 i++;
				 }
			 }
		 }

	 }
	 vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		 // Start typing your C/C++ solution below
		 // DO NOT write int main() function
		 vector<vector<int> > res;
		 if (candidates.size() == 0){ return res; }
		 sort(candidates.begin(), candidates.end());
		 vector<int> r;
		 dfs(candidates, target, res, r, 0);
		 return res;
	 }
 };