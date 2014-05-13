/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        if(candidates.size() == 0) return res;
        vector<int> step;
        combinationSum(candidates,target,0,step, res );
        return res;
    }
    
    void combinationSum(vector<int> & ca, int target, int begin,vector<int> &step, vector<vector<int> > & res )
    {
        if(target == 0)
        {
            res.push_back(step);
            return ;
        }
        else
        {
            while(begin < ca.size() && ca[begin] <= target)
            {
                step.push_back(ca[begin]);
                combinationSum(ca, target-ca[begin], begin, step, res);
                step.pop_back();
                begin++;
            }
        }
    }
};
